#include <linux/kernel.h>
#include <linux/i2c.h>
#include <linux/error.h>
#include <linux/regulator/consumer.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <linux/input.h>
#include <linux/input/mt.h>
#include <linux/kobject.h>
#include <linux/interrupt.h>

#include "tp_core.h"
#include "tp_specific_driver.h"


static struct tp_core_info_t *g_core_info;

struct i2c_client *tp_get_i2c_client(void)
{
	if (!g_core_info->i2c_client)
	{
		return ERR_PTR(-ENODEV);
	}

	return g_core_info->i2c_client;
}

int register_irq_handler(irq_handler_t handler)
{
	if (NULL == handler)
	{
		return -EINVAL;
	}
	
	g_core_info->handler = handler;

	return 0;
}

static int parse_hw_info_from_dts(struct device_node *node, struct tp_hw_info_t *hw_info)
{
	int ret, i = 0;
	struct tp_config_t *p_config;
	struct device_node *child;

	if (!node || !hw_info)
	{
		return -EINVAL;
	}
	
	ret = of_property_read_u32(node, "reg", &hw_info->i2c_addr);
	if (ret)
	{
		printk(KERN_ERR TAG "parse [reg] failed\n");
		goto err;
	}
	
	ret = of_property_read_string(node, "pinctrl-names", &hw_info->pinctrl_active_name);
	if (!ret)
	{
		struct property *prop = container_of(hw_info->pinctrl_active_name, struct property, value);
		
		hw_info->pinctrl_suspend_name = of_prop_next_string(prop, hw_info->pinctrl_active_name);
	}
	else
	{
		printk(KERN_ERR TAG "parse [pinctrl-names] failed\n");
		goto err;
	}

	ret = of_property_read_string(node, "fts,pwr-reg-name", &hw_info->pwr_reg_name);
	if (ret)
	{
		printk(KERN_ERR TAG "parse [pwr-reg-name] failed\n");
		goto err;
	}

	ret = of_property_read_string(node, "fts,bus-reg-name", &hw_info->bus_reg_name);
	if (ret)
	{
		printk(KERN_ERR TAG "parse [bus-reg-name] failed\n");
		goto err;
	}

	hw_info->gpio_irq = of_get_named_gpio_flags(node, "fts,irq-gpio", 0, NULL);
	if (hw_info->gpio_irq < 0)
	{
		printk(KERN_ERR TAG "parse [irq-gpio] failed\n");
		ret = hw_info->gpio_irq;
		goto err;
	}
	
	ret = of_property_read_u32(node, "fts,irq-flags", &hw_info->irq_flag);
	if (ret)
	{
		printk(KERN_ERR TAG "parse [irq-flags] failed\n");
		goto err;
	}

	hw_info->reset_exist = of_property_read_bool(node, "fts,reset-gpio-enable");
	if (hw_info->reset_exist)
	{
		hw_info->gpio_reset = of_get_named_gpio_flags(node, "fts,reset-gpio", 0, NULL);
		if (hw_info->gpio_reset < 0)
		{
			printk(KERN_ERR TAG "parse [reset-gpio] failed\n");
			ret = hw_info->gpio_reset;
			goto err;
		}
	}

	hw_info->dump_click_count = of_property_read_bool(node, "fts,dump-click-count");

	ret = of_property_read_u32(node, "fts,config-array-size", &hw_info->config_array_size);
	if (ret)
	{
		printk(KERN_ERR TAG "parse [config-array-size] failed\n");
		goto err;
	}
	
	p_config = kzalloc(sizeof(*p_config) * hw_info->config_array_size, GFP_KERNEL);
	if (p_config)
	{
		printk(KERN_ERR TAG "kzalloc p_config failed\n");
		ret = -ENOMEM;	
	}

	for_each_child_of_node(node, child)
	{
		i++;

		ret = of_property_read_u32(child, "fts,tp-vendor", &p_config[i].vender);
		if (ret)
		{
			printk(KERN_ERR TAG "parse [vender] failed\n");
			goto err;
		}

		ret = of_property_read_string(child, "fts,fw-name", &p_config[i].fw_name);
		if (ret)
		{
			printk(KERN_ERR TAG "parse [fw-name] failed\n");
			goto err;
		}

		ret = of_property_read_string(child, "fts,limit-name", &p_config[i].limit_name);
		if (ret)
		{
			printk(KERN_ERR TAG "parse [limit-name] failed\n");
			goto err;
		}

		ret = of_property_read_string(child, "fts,click-file-name", &p_config[i].click_file_name);
		if (ret)
		{
			printk(KERN_ERR TAG "parse [click-file-name] failed\n");
			goto err;
		}

	}
	
err:
	return ret;
	
}

static int tp_regulator_get(struct tp_core_info_t *core_info, bool get)
{
	int ret = 0;
	struct device *dev = &core_info->i2c_client->dev;

	if (!get)
		goto regulator_put;
	core_info->pwr_reg = regulator_get(dev, core_info->hw_info->pwr_reg_name);
	if (IS_ERR(core_info->pwr_reg))
	{
		dev_err(dev, "regulator pwr get failed\n");
		return PTR_ERR(core_info->pwr_reg);
	}
	
	core_info->bus_reg = regulator_get(dev, core_info->hw_info->bus_reg_name);
	if (IS_ERR(core_info->bus_reg))
	{
		dev_err(dev, "regulator bus get failed\n");
		ret = PTR_ERR(core_info->bus_reg);
		goto regulator_put;
	}
	
	return 0;

regulator_put:
	if (core_info->pwr_reg)
	{
		regulator_put(core_info->pwr_reg);
		core_info->pwr_reg = NULL;
	}
	if (core_info->bus_reg)
	{
		regulator_put(core_info->bus_reg);
		core_info->bus_reg = NULL;
	}

	return ret;
}

static int tp_regulator_enable(struct tp_core_info_t *core_info)
{
	int ret = 0;
	
	ret = regulator_enable(core_info->pwr_reg);
	if(ret < 0)
	{
		dev_err(&core_info->i2c_client->dev, "regulator pwr enable failed\n");
		return ret;
	}

	ret = regulator_enable(core_info->bus_reg);
	if(ret < 0)
	{
		dev_err(&core_info->i2c_client->dev, "regulator bus enable failed\n");
		regulator_disable(core_info->pwr_reg);
	}

	return ret;
}

static int tp_regulator_disable(struct tp_core_info_t *core_info)
{
	int ret = 0;

	ret = regulator_disable(core_info->pwr_reg);
	if (ret < 0)
	{
		dev_err(&core_info->i2c_client->dev, "regulator pwr disable failed\n");
		return ret;
	}

	ret = regulator_disable(core_info->bus_reg);
	if (ret < 0)
	{
		dev_err(&core_info->i2c_client->dev, "regulator bus disable failed\n");
	}
	return ret;
}

static int tp_pinctrl_init(struct tp_core_info_t *core_info)
{
	int ret = 0;
	struct device *dev = &core_info->i2c_client->dev;

	core_info->tp_pinctrl = devm_pinctrl_get(dev);
	if (IS_ERR(core_info->tp_pinctrl))
	{
		dev_err(dev, "get pinctrl failed\n");
		return PTR_ERR(core_info->tp_pinctrl);
	}
	
	core_info->active_state = pinctrl_lookup_state(core_info->tp_pinctrl, core_info->hw_info->pinctrl_active_name);
	if (IS_ERR(core_info->active_state))
	{
		dev_err(dev, "look up pinctrl active state failed\n");
		ret = PTR_ERR(core_info->active_state);
		goto state_err;
	}

	core_info->suspend_state = pinctrl_lookup_state(core_info->tp_pinctrl, core_info->hw_info->pinctrl_suspend_name);
	if (IS_ERR(core_info->suspend_state))
	{
		dev_err(dev, "look up pinctrl suspend state failed\n");
		ret = PTR_ERR(core_info->suspend_state);
		goto state_err;
	}

state_err:
	devm_pinctrl_put(core_info->tp_pinctrl);
	return ret;
}

static int tp_event(struct input_dev *dev, unsigned int type, unsigned int code, int vaule)
{
	/*TODO*/
	return 0;
}

irqreturn_t default_irq_handle (int irq, void *data)
{
	/*TODO*/
	return IRQ_HANDLED;
}

static int tp_core_probe(struct i2c_client *i2c_client, const struct i2c_device_id *dev_id)
{
	int ret, irq;
	struct i2c_adapter *adap = i2c_client->adapter;
	struct device *dev = &i2c_client->dev;
	struct tp_core_info_t *core_info = NULL;
	struct tp_hw_info_t *hw_info = NULL;
	struct input_dev *input = NULL;
	char *input_name, *phys;

	/*i2c check*/
	if (! i2c_check_functionality(adap, I2C_FUNC_I2C))
	{
		dev_err(dev, "i2c don't have func I2C_FUNC_I2C\n");
		return -ENODEV;
	}
	
	core_info = kzalloc(sizeof(*core_info), GFP_KERNEL);
	if (!core_info)
	{
		dev_err(dev, "kzalloc core_info failed\n");
		return -ENOMEM;
	}
	
	g_core_info = core_info;
	core_info->i2c_client = i2c_client;

	/*parse hw info*/
	hw_info = kzalloc(sizeof(*hw_info), GFP_KERNEL);
	if (!hw_info)
	{
		dev_err(dev, "kzalloc hw_info failed\n");
		return -ENOMEM;
	}
	
	ret = parse_hw_info_from_dts(dev->of_node, hw_info);
	if (ret)
	{
		dev_err(dev, "can't parse hardware from dts\n");
		goto hw_err;
	}
	
	core_info->hw_info = hw_info;

	dev_info(dev, "parse hardware informations from dts finish!\n");

	/*request tp resourse*/
	
	ret = tp_regulator_get(core_info, true);
	if (ret)
		goto hw_err;
	
	ret = tp_pinctrl_init(core_info);
	if (ret)
		goto pinctrl_err;

	if (gpio_is_valid(hw_info->gpio_irq))
	{
		ret = gpio_request(hw_info->gpio_irq, "tp_irq");
		if (ret)
		{
			dev_err(dev, "request gpio irq failed\n");
			goto req_gpio_irq_err;
		}

		ret = gpio_direction_input(hw_info->gpio_irq);
		if (ret)
		{
			dev_err(dev, "set direction for gpio irq failed\n");
			goto set_irq_direction_err;
		}
	}

	if(hw_info->reset_exist)
	{
		if(gpio_is_valid(hw_info->gpio_reset))
		{
			ret = gpio_request(hw_info->gpio_reset, "tp_reset");
			if(ret)
			{
				dev_err(dev, "request gpio reset failed\n");
				goto set_irq_direction_err;
			}

			ret = gpio_direction_output(hw_info->gpio_reset);
			if (ret)
			{
				dev_err(dev, "set direction for gpio reset failed\n");
				goto set_reset_direction_err;
			}
	
		}
	}
	
	/*input subsystem init*/
	input = devm_input_allocate_device(dev);
	if (IS_ERR(input))
	{
		dev_err(dev, "allocate input dev failed\n");
		goto set_reset_direction_err;
	}
	
	input->name = dev->driver->name;
	input->phys = "tp/input0"; 
	input->id.bustype = BUS_I2C; 
	input->id.vendor = 0x0001;
	input->id.product = 0x0002;
	input->id.version = 0x0100;
	input->event = tp_event;
	
	set_bit(EV_SYN, input->evbit);

	set_bit(EV_KEY, input->evbit);
	input_set_capability(dev, EV_KEY, BTN_TOUCH);

	set_bit(EV_ABS, input->evbit);
	/*ABS_MT_SLOT,ABS_MT_TRACKING_ID already set in this func*/
	input_mt_init_slots(input, FINGER_NUMBER, INPUT_MT_DIRECT);
	input_set_abs_params(input, ABS_MT_POSITION_X, 0, X_LEN-1, 0, 0);
	input_set_abs_params(input, ABS_MT_POSITION_Y, 0, Y_LEN-1, 0, 0);
	input_set_abs_params(input, ABS_MT_TOUCH_MAJOR, AREA_MIN, AREA_MAX, 0, 0);
	input_set_abs_params(input, ABS_MT_TOUCH_MINOR, AREA_MIN, AREA_MAX, 0, 0);

	/*do not need now
	 *
	 *input_set_abs_params(input, ABS_MT_TOOL_TYPE, 0, MT_TOOL_MAX, 0, 0);
	 *input_set_abs_params(input, ABS_MT_PRESSURE, PRESSURE_MIN, PRESSURE_MAX, 0, 0);
	 */
	ret = input_register_device(input);
	if (ret)
	{
		dev_err(dev, "input register failed\n");
		goto set_reset_direction_err;
	}

	/*IC init*/

	/*avoid unexpect interrupt to be received, put irq request at the end of probe*/
	irq = gpio_to_irq(hw_info->gpio_irq);
	if (irq < 0)
	{
		dev_err(dev, "gpio to irq failed\n");
		goto set_reset_direction_err;
	}

	ret = devm_request_threaded_irq(dev, irq, NULL, default_irq_handle, hw_info->irq_flag, "tp_irq", core_info);
	if(ret < 0)
	{
		dev_err(dev, "request irq handler failed\n");
		goto set_reset_direction_err;
	}
	
	

set_reset_direction_err:
	gpio_free(hw_info->gpio_reset);
set_irq_direction_err:
	gpio_free(hw_info->gpio_irq);
req_gpio_irq_err:
	devm_pinctrl_put(core_info->tp_pinctrl);
pinctrl_err:
	regulator_put(core_info->pwr_reg);
	regulator_put(core_info->bus_reg);
hw_err:
	kfree(hw_info);
	return ret;
}

static int tp_core_remove(struct i2c_client *i2c_client)
{

}


static struct i2c_driver tp_i2c_drv = {
	.probe = tp_core_probe,
	.remove = tp_core_remove,
	.dirver = {
		.name = g_tp_name,
		.owner = THIS_MODULE,
		.of_match_table = &g_of_specific_id,
	},
};

module_i2c_driver(tp_i2c_drv);

MODULE_LICESEN("GPL");
MODULE_AUTHOR("JJ");



