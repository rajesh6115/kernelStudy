/******************************************************************************
 * File Name            : hello.c                                             * 
 * Module Name          : Hello World Module                                  * 
 * Description          : Hello World Module which wiil print msg at the load *
 *                      : and unload of this module                           *
 * Target Architecture  : Generic                                             *
 * Date                 : 28-Sept-2014                                        *
 * Author               : rajesh6115                                          *
 * Version              : 0.0.1                                               *
 * Dependency           : NA                                                  *
 * ****************************************************************************
 */


#include "hello.h"
#define HELLO_AUTHOR "Rajesh6115 <sahoorajesh.d@gmail.com>"
#define HELLO_DESC   "A Simple Hello World Module"

/******************************************************************************
 * MODULE INFO MACROS USED TO PROVIDE INFO FOR THE MODULES                    *
 ******************************************************************************
 */

/*****************************************************************************
 * The following license idents are currently accepted as indicating free    *
 * software modules                                                          *
 *                                                                           *
 *	"GPL"		               [GNU Public License v2 or later]      *
 *	"GPL v2"		       [GNU Public License v2]               *
 *	"GPL and additional rights"    [GNU Public License v2                *
 *                                                   rights and more]        *
 *	"Dual BSD/GPL"			[GNU Public License v2               *
 *					 or BSD license choice]              *
 *	"Dual MIT/GPL"			[GNU Public License v2               *
 *					 or MIT license choice]              *
 *	"Dual MPL/GPL"			[GNU Public License v2               *
 *					 or Mozilla license choice]          *
 *                                                                           *
 * The following other idents are available                                  *
 *                                                                           *   
 *	"Proprietary"			[Non free products]                  *
 *                                                                           *
 * There are dual licensed components, but when running with Linux it is the *
 * GPL that is relevant so this is a non issue. Similarly LGPL linked with   *
 * GPL is a GPL combined work.                                               *
 *                                                                           *
 * This exists for several reasons                                           *
 * 1.	So modinfo can show license info for users wanting to vet their setup* 
 *	is free                                                              *
 * 2.	So the community can ignore bug reports including proprietary modules*
 * 3.	So vendors can do likewise based on their own policies               *
 *****************************************************************************
 */
MODULE_LICENSE("GPL");

MODULE_AUTHOR(HELLO_AUTHOR);	/* Who wrote this module? */
MODULE_DESCRIPTION(HELLO_DESC);	/* What does this module do */

static int __init hello_init(void){
	printk(KERN_INFO "Hello Kernel Module Loaded!!\n");
	return 0;
}

static void __exit hello_exit(void){
	printk(KERN_INFO "Hello Kernel Module Unloaded.\n");
}

module_init(hello_init);
module_exit(hello_exit);

