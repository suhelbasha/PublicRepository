#include <linux/module.h>

int init_module (void)
{
	printk("module inserted \n"); 			//printk is used here for printing on the console
	return 0;
}

void cleanup_module (void)
{
	printk("module removed\n");			//printk is used here for printing on the console
}

MODULE_AUTHOR ("suhel.basha@techveda.org");		//To tell who is the author of this code
MODULE_DESCRIPTION ("LKD_CW: First kernel module");	//To tell module description
MODULE_LICENSE ("GPL");					//To tell what license it belongs
