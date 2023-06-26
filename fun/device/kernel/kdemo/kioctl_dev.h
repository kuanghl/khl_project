#ifndef __IOCTL_DEV_H__
#define __IOCTL_DEV_H__

#define IOCTL_BASE	'W'
#define IOCTL_BASE_GET_MUIR				_IO(IOCTL_BASE, 1)

typedef struct
{
	atomic_t available;
	struct semaphore sem;
	struct cdev cdev;
} ioctl_d_interface_dev;

int ioctl_d_interface_open(struct inode *inode, struct file *filp);
int ioctl_d_interface_release(struct inode *inode, struct file *filp);
long ioctl_d_interface_ioctl(struct file *filp, unsigned int cmd, unsigned long arg);

#endif // __IOCTL_DEV_H__