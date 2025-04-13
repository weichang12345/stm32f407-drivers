/* 
 * This file contains all function prototypes of the EXTI peripheral.
 * The EXTI module configures: 
 * 1. Hardware interrupt
 * 2. Hardware event
 * 3. Software interrupt/event
 * 
 */


#ifndef _EXTI_H_
#define _EXTI_H_


#include "stm32f407.h"
#include "gpio.h"

typedef enum
{
    HW_ITR     = 0, // Hardware interrupt mode
    HW_EVT     = 1, // Hardware event mode 
    SW_IER_EVT = 2  // Software interrupt/event mode
}EXTI_Mode_t;

typedef enum
{
    RISE_TRIG      = 4, // Rising edge trigger
    FALL_TRIG      = 5, // Falling trigger
    RISE_FALL_TRIG = 6, // Rising and falling trigger
}EXTI_TrigMode_t;

typedef struct 
{
    uint32_t           exti_line;
    EXTI_Mode_t        exti_mode;
    EXTI_TrigMode_t    trigger_mode;
}EXTI_ConfigHandle_t;


static inline uint32_t IS_EXTI_LINE(uint32_t exti_line)    { return (exti_line <= 22); }
static inline uint32_t IS_EXTI_MODE(EXTI_Mode_t exti_mode) { return ((exti_mode == HW_ITR) || (exti_mode == HW_EVT) || (exti_mode == SW_IER_EVT)); }
static inline uint32_t IS_EXTI_TRIG_MODE(EXTI_TrigMode_t trigger_mode) { return ((trigger_mode == RISE_TRIG) || \
                                                                                 (trigger_mode == FALL_TRIG) || \
                                                                                 (trigger_mode == RISE_FALL_TRIG)); }

/* 
 * Interfaces
 */

void EXTI_Config(EXTI_ConfigHandle_t *handle);
void EXTI_ClearPendingBit(uint32_t exti_line);


#endif // _EXTI_H_
