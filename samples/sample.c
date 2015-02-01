/******************************************************************************
 * File Name		: sample.c                                            * 
 * Module Name		: Template Module                                     * 
 * Description		: Simple Module File For Reference                    *
 * Target Architecture	: Generic                                             *
 * Date			: 28-Sept-2014                                        *
 * Author		: rajesh6115                                          *
 * Version		: 0.0.1                                               *
 * Dependency		: NA                                                  *
 * ****************************************************************************
 */

#include "sample.h"

MODULE_LICENSE("GPL");
static int __init hello_init(void){
	        printk(KERN_INFO "Hello World Linux Kernel\n");
		        return 0;
}

static void __exit hello_exit(void){
	        printk(KERN_INFO "Good Bye Linux Kernel\n");
}

module_init(hello_init);
module_exit(hello_exit);


