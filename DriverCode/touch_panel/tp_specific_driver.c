#include <linux/i2c.h>

#include "tp_specific_driver.h"


char *g_tp_name = "fts";

struct of_device_id g_of_specific_id = {
	.compatible = "st,fts",
};


int tp_reset(void)
{
	
}
