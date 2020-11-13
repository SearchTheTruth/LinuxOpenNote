#include <linux/module.h>
#include <linux/gpiolib.h>


static int __init pinctrl_confilct_test_init(void)
{
	of_get_named_gpio_flags
}

static void __exit pinctrl_confilct_test_exit(void)
{

}

module_init(pinctrl_confilct_test_init);
module_exit(pinctrl_confilct_test_exit);
MODULE_AUTHOR("JJ");
MOUDLE_LICENSE("GPL");
