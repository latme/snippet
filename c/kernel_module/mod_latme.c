#include <linux/module.h>   // for module_init, module_exit
#include <linux/kernel.h>   // for KERN_INFO, printk
#include <linux/init.h>     // for __init, __exit

//for resolve "WARNING: modpost: missing MODULE_LICENSE()"
MODULE_LICENSE("GPL");



static int __init latme_init(void)
{

    printk(KERN_INFO "hello latme!\n");
    return 0;
}

static void __exit latme_exit(void)
{
    printk(KERN_INFO "bye latme!\n");
}


module_init(latme_init);
module_exit(latme_exit);

