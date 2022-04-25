#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h> // printk()
#include <linux/slab.h>   // kmalloc()
#include <linux/fs.h>     // everything
#include <linux/errno.h>  // error codes
#include <linux/types.h>  // size_t
#include <linux/proc_fs.h>
#include <linux/fcntl.h>   // O_ACCMODE
#include <linux/uaccess.h> // copy_from/to_user

MODULE_LICENSE("Dual BSD/GPL");
#define BUFFER_SIZE 4

/* Declaration of memory.c functions */
int memory_open(struct inode *inode, struct file *filp);
int memory_release(struct inode *inode, struct file *filp);
ssize_t memory_read(struct file *filp, char *buf, size_t count, loff_t *f_pos);
ssize_t memory_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos);
void memory_exit(void);
int memory_init(void);

/* Structure that declares the usual file */
struct file_operations memory_fops = {
    read : memory_read,
    write : memory_write,
    open : memory_open,
    release : memory_release
};

module_init(memory_init);
module_exit(memory_exit);

/* Global variables of the driver*/
int memory_major = 60;
char *memory_buffer;

int memory_init(void)
{
    int result;
    // Registering device
    result = register_chrdev(memory_major, "memory", &memory_fops);
    if (result < 0)
    {
        printk("<1> memory: cannot obtain major number %d\n", memory_major);
        return result;
    }

    // Allocating memory for the buffer
    memory_buffer = kmalloc(BUFFER_SIZE, GFP_KERNEL);

    if (!memory_buffer)
    {
        result = -ENOMEM;
        goto fail;
    }

    // Set buffer to 0 by default
    memset(memory_buffer, 0, BUFFER_SIZE);

    printk("<1> Inserting memory module\n");
    return 0;

fail:
    memory_exit();
    return result;
}

void memory_exit(void)
{
    unregister_chrdev(memory_major, "memory");

    if (memory_buffer)
        kfree(memory_buffer);

    printk("<1> Removing memory module\n");
}

int memory_open(struct inode *inode, struct file *filp)
{
    return 0;
}

int memory_release(struct inode *inode, struct file *filp)
{
    return 0;
}

ssize_t memory_read(struct file *filp, char *buf, size_t count, loff_t *f_pos)
{
    if (*f_pos == 0)
    {
        *f_pos += BUFFER_SIZE;
        copy_to_user(buf, memory_buffer, BUFFER_SIZE);
        return BUFFER_SIZE;
    }
    else
    {
        return 0;
    }
}

ssize_t memory_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos)
{
    copy_from_user(memory_buffer, buf, BUFFER_SIZE);
    return BUFFER_SIZE;
}