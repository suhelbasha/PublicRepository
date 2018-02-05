#include <linux/module.h>

int init_module (void)
{
	printk("module inserted and hello world\n");
	return 0;

}

void cleanup_module (void)
{
	printk("module removed\n");
}

MODULE_AUTHOR ("suhel.basha@techveda.org");
MODULE_DESCRIPTION ("LKD_CW: First kernel module");
MODULE_LICENSE ("GPL");
