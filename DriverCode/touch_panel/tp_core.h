#ifndef __TP_CORE_H
#define __TP_CORE_H

#include <linux/regulator/consumer.h>
#include <linux/firmware.h>

/*TP core debug macro*/
#define TAG	"[TP] :"
#undef PDEBUG
#ifdef TP_DEBUG
#	ifdef	__KERNEL__
#		define	PDEBUG(fmt, args ...)	printk(KERN_DEBUG TAG fmt, ## args);
#	else
#		define	PDEBUG(fmt, args ...)	fprintf(stderr, TAG fmt, ## args);
#	endif
#else
#	define	PDEBUG(fmt, args ...)
#endif
#define PDEBUGG(fmt, args ...)

#endif

typedef enum {
	SCAN_LOW_POWER,
	SCAN_NORMAL_POWER,
	SCAN_MODE_MAX,
}scan_mode_t;

typedef enum {
	GLOVE,
	COVER,
	CHARGER,
	GESTURE,
	GRIP,
	STYLUS,
	FEATURE_MAX,
}feature_t;

typedef enum {
	GESTURE_DISABLE,
	GESTURE_DOUBLE_CLICK,
	GESTURE_MAX,
}gesture_t;

/*TP operations*/
struct tp_core_ops_t {
	int (*reset)(struct tp_core_ops_t *core);
	int (*power_on)(struct tp_core_info_t *core);
	int (*power_off)(struct tp_core_info_t *core);
	int (*get_lockdown_info)(struct tp_core_info_t *core);
	int (*get_firmware)(struct tp_core_info_t *core);
	int (*put_firmware)(struct tp_core_info_t *core);
	int (*is_firmware_update)(void);
	int (*update_firmware)(struct tp_core_info_t *core);
	int (*resume)(struct tp_core_info_t *core);
	int (*suspend)(struct tp_core_info_t *core);
	int (*set_scan_mode)(scan_mode_t mode);
	int (*set_feature)(feature_t feature, int func);
	int (*init)(struct tp_core_info_t *core);
};

/*TP core info*/
struct tp_core_info_t {
	struct i2c_client *i2c_client;
	struct regulator *pwr_reg;
	struct regulator *bus_reg;
	struct pinctrl *tp_pinctrl;
	struct pinctrl_state *active_state;
	struct pinctrl_state *suspend_state;
	struct firmware *fw;
	struct input_dev *input;
	irq_handler_t handler;	/*TODO: complete next version*/
	struct tp_hw_info_t *hw_info;
};


/*TODO
 *1.pinctrl name 完成可变长buffer自动解析pinctrl_name
 *2.irq_flag是什么类型的数据，是否由xslate翻译
 *3.考虑将hw_info解析的工作交由specific实现，core使用其callback.
 */
/*TP hardware info*/
struct tp_hw_info_t {
	u32 i2c_addr;
	char *pinctrl_active_name;
	char *pinctrl_suspend_name;
	char *pwr_reg_name;
	char *bus_reg_name;
	int gpio_irq;
	u32 irq_flag;
	bool reset_exist;
	int gpio_reset;
	bool dump_click_count;
	u32 config_array_size;
	void *config_buffer;
	void *hw_private;
};

/*TP config*/
struct tp_config_t {
	u32 vender;
	char *fw_name;
	char *limit_name;
	char *click_file_name;
};

int register_irq_handler(irq_handler_t handler);
