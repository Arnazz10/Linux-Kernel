/*
 * hello_kernel.c - A simple Linux Kernel Module (LKM)
 *
 * This module demonstrates basic LKM functionality:
 * - Module initialization and cleanup
 * - Proper use of printk with appropriate log levels
 * - Kernel coding style compliance
 *
 * Author: Linux Kernel Development Assistant
 * License: GPL v2
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

/* Module metadata */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Linux Kernel Development Assistant");
MODULE_DESCRIPTION("A simple hello world kernel module");
MODULE_VERSION("1.0");

/**
 * hello_init - Module initialization function
 *
 * This function is called when the module is loaded into the kernel.
 * It prints a welcome message using printk with KERN_INFO log level.
 *
 * Return: 0 on success, negative value on failure
 */
static int __init hello_init(void)
{
	/*
	 * KERN_INFO is the appropriate log level for informational messages
	 * that are not errors or warnings. The message will appear in
	 * kernel logs and can be viewed with dmesg command.
	 */
	printk(KERN_INFO "Hello, Kernel! Module loaded successfully.\n");
	
	/* Return 0 to indicate successful initialization */
	return 0;
}

/**
 * hello_exit - Module cleanup function
 *
 * This function is called when the module is removed from the kernel.
 * It prints a goodbye message using printk with KERN_INFO log level.
 */
static void __exit hello_exit(void)
{
	/*
	 * Print goodbye message when module is unloaded.
	 * This helps in debugging and understanding module lifecycle.
	 */
	printk(KERN_INFO "Goodbye, Kernel! Module unloaded successfully.\n");
}

/* Register the module initialization and cleanup functions */
module_init(hello_init);
module_exit(hello_exit);


