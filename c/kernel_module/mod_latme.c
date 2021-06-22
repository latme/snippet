#include <linux/module.h>   // for module_init, module_exit
#include <linux/kernel.h>   // for KERN_INFO, printk
#include <linux/init.h>     // for __init, __exit
#include <linux/fs.h>       // for file_operations
#include <linux/cdev.h>     // for cdev_*
#include <linux/device.h>   // for device_*




static dev_t          latme_devt = 0;
static struct cdev    latme_cdev;
static struct class  *latme_class;
static struct device *latme_device;



static int latme_open(struct inode *ino, struct file *flip)
{
    printk(KERN_INFO "latme open\n");
    return 0;
}


static int latme_close(struct inode *ino, struct file *flip)
{
    printk(KERN_INFO "latme close\n");
    return 0;
}


static long latme_ioctl(struct file *flip,
            unsigned int ioctl_cmd, unsigned long param)
{
    printk(KERN_INFO "latme ioctl: cmd 0x%08x, param %ld\n", ioctl_cmd, param);
    return 0;
}


static struct file_operations latme_fops = {
    .open           = latme_open,
    .unlocked_ioctl = latme_ioctl,
    .release        = latme_close
};


static int __init latme_init(void)
{
    int     ret;

    ret = alloc_chrdev_region(&latme_devt, 0, 1, "latme");
    if (ret < 0) {
        printk(KERN_ERR "latme alloc chrdev failed!");
        goto err_alloc_chrdev_region;
    } else {
        printk(KERN_INFO "latme devt=%d:%d\n", MAJOR(latme_devt), MINOR(latme_devt));
    }


    cdev_init(&latme_cdev, &latme_fops);

    ret = cdev_add(&latme_cdev, latme_devt, 1);
    if (ret < 0) {
        printk(KERN_ERR "latme cdev_add failed!");
        goto err_cdev_add;
    }

    latme_class = class_create(THIS_MODULE, "latmus");
    if (IS_ERR(latme_class)) {
        printk(KERN_ERR "latme create class failed!");
        goto err_class_create;
    }

    latme_device = device_create(latme_class, NULL, latme_devt, NULL, "latme_dev");
    if (IS_ERR(latme_class)) {
        printk(KERN_ERR "latme create device failed!");
        goto err_device_create;
    }

    printk(KERN_INFO "latme init done!\n");
    return 0;

err_device_create:
    class_destroy(latme_class);
err_class_create:
err_cdev_add:
    unregister_chrdev_region(latme_devt, 1);
err_alloc_chrdev_region:
    return -1;
}

static void __exit latme_exit(void)
{
    device_destroy(latme_class, latme_devt);
    class_destroy(latme_class);
    unregister_chrdev_region(latme_devt, 1);

    printk(KERN_INFO "latme exit!\n");
}


//for resolve "WARNING: modpost: missing MODULE_LICENSE()"
MODULE_LICENSE("GPL");
module_init(latme_init);
module_exit(latme_exit);

