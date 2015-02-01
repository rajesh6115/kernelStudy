#ifndef _HELLO_MODULE_
#define _HELLO_MODULE_
/******************************************************************************
 * Module Name          : Hello Module                                        * 
 * Description          : Hello Kernel Module                                 *
 *                      : only insmod and rmmod                               *
 * Target Architecture  : Generic                                             *
 * Date                 : 01-Feb-2015                                         *
 * Author               : rajesh6115                                          *
 * Version              : 0.0.1                                               *
 * Dependency           : NA                                                  *
 * ****************************************************************************
 */

#include <linux/module.h>
#include <linux/init.h>

/******************************************************************************
 * @description: This function is Initialisation Code for this hello module   *
 * This function is called when we load module using insmod                   *
 ******************************************************************************
 */
static int __init hello_init(void);

/******************************************************************************
 * @description: This function is de-initialisation Code for this hello module*
 * This function is called when we unload module using rmmod                  *
 ******************************************************************************
 */
static void __exit hello_exit(void);

#endif
