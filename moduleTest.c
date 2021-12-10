#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>

static int myint = 0;

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Caio, Júlio, João Paulo");
MODULE_DESCRIPTION("Módulo que recebe um parametro");
MODULE_VERSION("1");
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(myint, "Esse é o int passado para a inicialização do módulo");

static int __init lkm_example_init(void) {
	printk(KERN_INFO "Hello, World!\n");
	return 0;
}
static void __exit lkm_example_exit(void) {
	printk("variavel passada : %d (0 é default)", myint);
	printk(KERN_INFO "Goodbye, World!\n");
}
module_init(lkm_example_init);
module_exit(lkm_example_exit);