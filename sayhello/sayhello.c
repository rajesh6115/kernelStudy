#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("rajesh6115 <sahoorajesh.d@gmail.com>");
MODULE_DESCRIPTION("Say Hello Kernel Module. Designed to say hello when reading from this character Device");

static int sayhello_open(struct inode *, struct file *);
static int sayhello_release(struct inode *, struct file *);
static ssize_t sayhello_read(struct file *, char *, size_t, loff_t *);
static ssize_t sayhello_write(struct file *, const char *, size_t, loff_t *);

static struct file_operations sayhello_file_ops={
	.read=sayhello_read,
	.write=sayhello_write,
	.open=sayhello_open,
	.release=sayhello_release,
};

static int sayhello_open(struct inode *dev_node, struct file *dev_file){
	printk(KERN_ALERT "Say Hello Device Opened\n");
	return 0;
}

static int sayhello_release(struct inode *dev_node, struct file *dev_file){
	printk(KERN_ALERT "Say Hello Device Closed\n");
	return 0;
}


static int sayhello_read(struct file *dev_file, char *usr_buffer, size_t count, loff_t *ppos){
	char *hello_str = "Hello world From Kernel!!!";
	int hello_len = strlen(hello_str);
	if(count < hello_len)
		return -EINVAL;
	if(*ppos != 0)
		return 0;
	if(copy_to_user(usr_buffer, hello_str, hello_len))
		return -EINVAL;
	*ppos = hello_len;
	return hello_len;
}

static int sayhello_write(struct file *dev_file, const char *usr_buffer, size_t count, loff_t *ppos){
	printk(KERN_ALERT "Sayhello Device Only Designed to READ\n");
	return count;
}

static int __init sayhello_init(void){
	/* Register Character Device Driver Here*/
	int temp = register_chrdev(90, "SayHello", &sayhello_file_ops);
	if(temp < 0){
		printk(KERN_ALERT "Sayhello Kernel Module Having Error In Loading\n");
	}else{
		printk(KERN_ALERT "Sayhello Kernel Module Loaded.\n");
	}
	return 0;
}

module_init(sayhello_init);

static void __exit sayhello_exit(void){
	/* UnRegister Character Device Driver Here*/
	unregister_chrdev(90, "SayHello");
	printk(KERN_ALERT "Sayhello Kernel Module Unloaded.\n");
}

module_exit(sayhello_exit);
