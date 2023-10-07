#include <linux/miscdevice.h> 
#include <linux/delay.h> 
#include <linux/kernel.h> 
#include <linux/module.h> 
#include <linux/init.h> 
#include <linux/mm.h> 
#include <linux/fs.h> 
#include <linux/types.h> 
#include <linux/delay.h> 
#include <linux/moduleparam.h> 
#include <linux/slab.h> 
#include <linux/errno.h> 
#include <linux/ioctl.h> 
#include <linux/cdev.h> 
#include <linux/string.h> 
#include <linux/list.h> 
#include <linux/pci.h> 
#include <linux/gpio.h> 
 
#define DEVICE_NAME "kmmap" 
 
#define kmmap_level 0

#if (kmmap_level == 0)
static unsigned char array[10]={10,1,2,3,4,5,6,7,8,9}; 
static unsigned char *buffer; 
 
static int _open(struct inode *inode, struct file *file) 
{ 
	return 0; 
} 
 
 
static int _map(struct file *filp, struct vm_area_struct *vma) 
{ 
	unsigned long page; 
	unsigned char i; 
	unsigned long start = (unsigned long)vma->vm_start; 
	//unsigned long end = (unsigned long)vma->vm_end; 
	unsigned long size = (unsigned long)(vma->vm_end - vma->vm_start); 
	
	//得到物理地址 
	page = virt_to_phys(buffer); 
	//将用户空间的一个vma虚拟内存区映射到以page开始的一段连续物理页面上 
	if(remap_pfn_range(vma,start,page>>PAGE_SHIFT,size,PAGE_SHARED))//第三个参数是页帧号，由物理地址右移PAGE_SHIFT得到 
	return -1; 
	
	//往该内存写10字节数据 
	for(i=0;i<10;i++) 
		buffer[i] = array[i]; 
	
	return 0; 
} 
 
 
static struct file_operations dev_fops = { 
	.owner = THIS_MODULE, 
	.open = _open, 
	.mmap = _map, 
}; 
 
static struct miscdevice misc = { 
	// .minor = MISC_DYNAMIC_MINOR, 
	.minor = MISC_DYNAMIC_MINOR, 
	.name = DEVICE_NAME, 
	.fops = &dev_fops, 
}; 
 
 
static int __init dev_init(void) 
{ 
	int ret; 
	
	//注册混杂设备 
	ret = misc_register(&misc); 

	//内存分配 
	buffer = (unsigned char *)kmalloc(PAGE_SIZE,GFP_KERNEL); 
	//将该段内存设置为保留 
	SetPageReserved(virt_to_page(buffer)); 
	
	return ret; 
} 
 
 
static void __exit dev_exit(void) 
{ 
	//注销设备 
	misc_deregister(&misc); 
	//清除保留 
	ClearPageReserved(virt_to_page(buffer)); 
	//释放内存 
	kfree(buffer); 
} 
 
 
module_init(dev_init); 
module_exit(dev_exit); 
MODULE_LICENSE("GPL"); 
MODULE_AUTHOR("kuanghl");

#elif (kmmap_level == 1)
#define BUF_SIZE (32*PAGE_SIZE)

static void *kbuff;

static int remap_pfn_open(struct inode *inode, struct file *file)
{
	struct mm_struct *mm = current->mm;

	printk("client: %s (%d)\n", current->comm, current->pid);
	printk("code  section: [0x%lx   0x%lx]\n", mm->start_code, mm->end_code);
	printk("data  section: [0x%lx   0x%lx]\n", mm->start_data, mm->end_data);
	printk("brk   section: s: 0x%lx, c: 0x%lx\n", mm->start_brk, mm->brk);
	printk("mmap  section: s: 0x%lx\n", mm->mmap_base);
	printk("stack section: s: 0x%lx\n", mm->start_stack);
	printk("arg   section: [0x%lx   0x%lx]\n", mm->arg_start, mm->arg_end);
	printk("env   section: [0x%lx   0x%lx]\n", mm->env_start, mm->env_end);

	return 0;
}

static int remap_pfn_mmap(struct file *file, struct vm_area_struct *vma)
{
	unsigned long offset = vma->vm_pgoff << PAGE_SHIFT;
	unsigned long virt_start = (unsigned long)kbuff + (unsigned long)(vma->vm_pgoff << PAGE_SHIFT);
	unsigned long pfn_start = (unsigned long)vmalloc_to_pfn((void *)virt_start);
	unsigned long size = vma->vm_end - vma->vm_start;
	int ret = 0;
	unsigned long vmstart = vma->vm_start;
	int i = 0;

	printk("phy: 0x%lx, offset: 0x%lx, size: 0x%lx\n", pfn_start << PAGE_SHIFT, offset, size);

	while (size > 0) {
		ret = remap_pfn_range(vma, vmstart, pfn_start, PAGE_SIZE, vma->vm_page_prot);
		if (ret) {
			printk("%s: remap_pfn_range failed at [0x%lx  0x%lx]\n",
				__func__, vmstart, vmstart + PAGE_SIZE);
			ret = -ENOMEM;
			goto err;
		} else
			printk("%s: map 0x%lx (0x%lx) to 0x%lx , size: 0x%lx, number: %d\n", __func__, virt_start,
				pfn_start << PAGE_SHIFT, vmstart, PAGE_SIZE, ++i);

		if (size <= PAGE_SIZE)
			size = 0;
		else {
			size -= PAGE_SIZE;
			vmstart += PAGE_SIZE;
			virt_start += PAGE_SIZE;
			pfn_start = vmalloc_to_pfn((void *)virt_start);
		}
	}

	// ret = remap_pfn_range(vma, vma->vm_start, pfn_start, size, vma->vm_page_prot);
	// if (ret){
	// 	printk("%s: remap_pfn_range failed at [0x%lx  0x%lx]\n",
	// 		__func__, vma->vm_start, vma->vm_end);
	// 	goto err;
	// }
	// printk("%s: map 0x%lx to 0x%lx, size: 0x%lx\n", __func__, virt_start,
	// 		vma->vm_start, size);
		
	return 0;
err:
	return ret;
}

static const struct file_operations remap_pfn_fops = {
	.owner = THIS_MODULE,
	.open = remap_pfn_open,
	.mmap = remap_pfn_mmap,
};

static struct miscdevice remap_pfn_misc = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = DEVICE_NAME,
	.fops = &remap_pfn_fops,
};

static int __init remap_pfn_init(void)
{
	int ret = 0;

	kbuff = vmalloc(BUF_SIZE);
	if (!kbuff) {
		ret = -ENOMEM;
		goto err;
	}

	// kbuff = kzalloc(BUF_SIZE, GFP_KERNEL);
	// if (!kbuff) {
	// 	ret = -ENOMEM;
	// 	goto err;
	// }

	ret = misc_register(&remap_pfn_misc);
	if (unlikely(ret)) {
		pr_err("failed to register misc device!\n");
		goto err;
	}

	return 0;

err:
	return ret;
}

static void __exit remap_pfn_exit(void)
{
	misc_deregister(&remap_pfn_misc);
	vfree(kbuff);
	// kfree(kbuff);
}

module_init(remap_pfn_init);
module_exit(remap_pfn_exit);
MODULE_LICENSE("GPL");

#elif (kmmap_level == 2)
#define BUF_SIZE (32*PAGE_SIZE)

static struct page *start_page;

static int remap_pfn_open(struct inode *inode, struct file *file)
{
	struct mm_struct *mm = current->mm;

	printk("client: %s (%d)\n", current->comm, current->pid);
	printk("code  section: [0x%lx   0x%lx]\n", mm->start_code, mm->end_code);
	printk("data  section: [0x%lx   0x%lx]\n", mm->start_data, mm->end_data);
	printk("brk   section: s: 0x%lx, c: 0x%lx\n", mm->start_brk, mm->brk);
	printk("mmap  section: s: 0x%lx\n", mm->mmap_base);
	printk("stack section: s: 0x%lx\n", mm->start_stack);
	printk("arg   section: [0x%lx   0x%lx]\n", mm->arg_start, mm->arg_end);
	printk("env   section: [0x%lx   0x%lx]\n", mm->env_start, mm->env_end);

	return 0;
}

static int remap_pfn_mmap(struct file *file, struct vm_area_struct *vma)
{
	unsigned long offset = vma->vm_pgoff << PAGE_SHIFT;
	unsigned long pfn_start = page_to_pfn(start_page) + vma->vm_pgoff;
	unsigned long virt_start = (unsigned long)page_address(start_page);
	unsigned long size = vma->vm_end - vma->vm_start;
	int ret = 0;

	printk("phy: 0x%lx, offset: 0x%lx, size: 0x%lx\n", pfn_start << PAGE_SHIFT, offset, size);

	ret = remap_pfn_range(vma, vma->vm_start, pfn_start, size, vma->vm_page_prot);
	if (ret)
		printk("%s: remap_pfn_range failed at [0x%lx  0x%lx]\n",
			__func__, vma->vm_start, vma->vm_end);
	else
		printk("%s: map 0x%lx to 0x%lx, size: 0x%lx\n", __func__, virt_start,
			vma->vm_start, size);

	return ret;
}

static const struct file_operations remap_pfn_fops = {
	.owner = THIS_MODULE,
	.open = remap_pfn_open,
	.mmap = remap_pfn_mmap,
};

static struct miscdevice remap_pfn_misc = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = DEVICE_NAME,
	.fops = &remap_pfn_fops,
};

static int __init remap_pfn_init(void)
{
	int ret = 0;

	start_page = alloc_pages(GFP_KERNEL, get_order(BUF_SIZE));
	if (!start_page) {
		ret = -ENOMEM;
		goto err;
	}

	ret = misc_register(&remap_pfn_misc);
	if (unlikely(ret)) {
		pr_err("failed to register misc device!\n");
		goto err;
	}

	return 0;

err:
	return ret;
}

static void __exit remap_pfn_exit(void)
{
	misc_deregister(&remap_pfn_misc);
	__free_pages(start_page, get_order(BUF_SIZE));
}

module_init(remap_pfn_init);
module_exit(remap_pfn_exit);
MODULE_LICENSE("GPL");

#endif