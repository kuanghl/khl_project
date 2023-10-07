#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/time64.h>

static int major = 258;
static int minor = 0;
static dev_t devno;
static struct cdev cdev;

static int hello_open (struct inode *inode, struct file *filep)
{
	// 读取当前时间
	struct timespec64 ts;
	ktime_get_real_ts64(&ts);
	// ktime_get_boottime_ts64(&ts);
	pr_notice("ts khello time: %llds, %ldns.\n", ts.tv_sec, ts.tv_nsec);
	printk("hello_open \n");
	return 0;
}
static struct file_operations hello_ops=
{
	.open = hello_open,			
};
 
static int hello_init(void)
{
	int ret;	
	printk("hello_init");
	devno = MKDEV(major,minor);
	ret = register_chrdev_region(devno, 1, "khello");
	if(ret < 0)
	{
		printk("register_chrdev_region fail \n");
		return ret;
	}
	cdev_init(&cdev,&hello_ops);
	ret = cdev_add(&cdev,devno,1);
	if(ret < 0)
	{
		printk("cdev_add fail \n");
		return ret;
	}

	return 0;
}
static void hello_exit(void)
{
	cdev_del(&cdev);
	unregister_chrdev_region(devno,1);
	printk("hello_exit \n");
}

MODULE_LICENSE("GPL");
module_init(hello_init);
module_exit(hello_exit);