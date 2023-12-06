#include <linux/version.h>
#include <linux/module.h>
#include <linux/errno.h>
#include <linux/kernel.h>
#include <linux/sched.h>

#include <linux/vmalloc.h>
#include <linux/init.h>

#include <linux/fs_struct.h>
#include <linux/limits.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#if defined(CONFIG_HARDLOCKUP_DETECTOR) && LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,32)
#include <linux/kthread.h>
#include <linux/slab.h>
#endif

static char *module_path = NULL;

module_param(module_path, charp, S_IRUGO);
MODULE_PARM_DESC(module_path, "Absolute path of the module");

static int module_para[255] = {1,2,3,4};
static int module_para_len = 0;
module_param_array(module_para, int, &module_para_len, S_IRUGO);
MODULE_PARM_DESC(module_para, "Array of the module");

void read_write_file(void){
    struct file *fd;
    char *buf = NULL;
    loff_t size, pos = 0;
    mm_segment_t  old_fs;
    
    fd = filp_open("./test.bin", O_RDWR, 0);
    size = fd->f_inode->i_size;
    pos = fd->f_pos;

    buf = vmalloc(size);
    memset(buf, 0, size);

#if LINUX_VERSION_CODE < KERNEL_VERSION(5,10,0)
            old_fs = get_fs();
            set_fs(KERNEL_DS);
            pos = 0
            fd->f_op->write(fd, buf, size, &pos);
            pos = 0;
            fd->f_op->read(fd, buf, size, &pos);
            set_fs(old_fs);
#else   
            pos = 0;
            kernel_write(fd,  buf, size, &pos);
            pos = 0;
            kernel_read(fd,  buf, size, &pos);
#endif
    filp_close(fd, NULL);
    vfree(buf);
}

void read_path(void){
    struct file *file;
    char *module_name = THIS_MODULE->name;
    char module_path[PATH_MAX];

    file = filp_open("/proc/modules", O_RDWR, 0);
    if (file) {
        char buf[PAGE_SIZE];
        int ret;
        mm_segment_t old_fs;

#if LINUX_VERSION_CODE < KERNEL_VERSION(5,10,0)
        old_fs = get_fs();
        set_fs(KERNEL_DS);

        ret = vfs_read(file, buf, sizeof(buf), &file->f_pos);
        if (ret > 0) {
            char *pos = strstr(buf, module_name);
            if (pos) {
                char *newline = strchr(pos, '\n');
                if (newline) {
                    size_t len = newline - pos;
                    if (len < PATH_MAX) {
                        strncpy(module_path, pos, len);
                        module_path[len] = '\0';
                        printk("Driver absolute path: %s\n", module_path);
                    }
                }
            }
        }
        set_fs(old_fs);
#endif

        filp_close(file, NULL);
    }
}

void get_path(void){
    struct path exe_path;
    char *buf = NULL;

    buf = vmalloc(PATH_MAX);
    if (!buf)
        return -ENOMEM;

    struct qstr root_path;
    struct qstr current_path;
    //获取根目录
    root_path = current->fs->root.dentry->d_name;
    //获取当前目录名
    current_path = current->fs->pwd.dentry->d_name;
    pr_info("root path node name: %s\n", root_path.name);
    pr_info("parent path node name: %s\n", current->fs->pwd.dentry->d_parent->d_iname);
    pr_info("current path node name: %s\n", current_path.name);
    pr_info("root path: %s\n", d_path(&current->fs->root.dentry, buf, PATH_MAX));
    pr_info("current path: %s\n", dentry_path_raw(current->fs->pwd.dentry, buf, PATH_MAX));
    pr_info("task path: %s\n", dentry_path_raw(current->mm->exe_file->f_path.dentry, buf, PATH_MAX));
    pr_info("task path: %s\n", d_path(&current->mm->exe_file->f_path, buf, PATH_MAX));

    pr_info("module name: %s\n", THIS_MODULE->name);
    pr_info("Module Path: %s\n", __FILE__); // 编译路径

    get_fs_root(current->fs, &exe_path);
    pr_info("Root path: %s\n", d_path(&exe_path, buf, PATH_MAX));

    get_fs_pwd(current->fs, &exe_path);
    pr_info("Current path: %s\n", d_path(&exe_path, buf, PATH_MAX));

    vfree(buf);
}

static int __init my_driver_init(void)
{
    get_path();
    read_path();
    read_write_file();

    if (module_path) {
        printk("Driver absolute path: %s\n", module_path);
    } else {
        printk("Driver absolute path is not available\n");
    }

    int i;
    for(i = 0; i < module_para_len; i++)
        printk("module_para[%d] : %d \n", i, module_para[i]);

    // Other initialization code

    return 0;
}

static void __exit my_driver_exit(void)
{
    // Cleanup code
    printk("***************: exit\n");
}

module_init(my_driver_init);
module_exit(my_driver_exit);

MODULE_LICENSE("GPL");