/* 
 * This file contains all function prototypes of the SYSCFG peripheral.
 */

#ifndef _SYSCFG_H_
#define _SYSCFG_H_

#include "stm32f407.h"
#include "gpio.h"

void SYSCFG_Config_EXTI(uint8_t exti_line, GPIO_RegDef_t *port);


#endif // _SYSCFG_H_
