/* 
 * This file manages the module header files for main.c.
 * If any peripheral is being used in main.c, uncomment the enable peripheral header file inclusion.
 */


#ifndef _MODULE_CONF_H_
#define _MODULE_CONF_H_


/* If any peripheral is being used in main.c, uncomment the enable peripheral header file inclusion. */
#include "gpio.h"
#include "rcc.h"
#include "stm32f407.h"
#include "ppb.h"
#include "nvic.h"
#include "exti.h"
#include "usart.h"
#include "interrupt.h"

#endif // _MODULE_CONF_H_