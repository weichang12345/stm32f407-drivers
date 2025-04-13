/* 
 * This file contains the base addresses, register definitions of the
 * core peripherals (Private Peripheral Bus) of the Cortex®-M4 processor.
 */

#ifndef _PPB_H_
#define _PPB_H_


#include "stm32f407.h"

#define SystemCoreClock   ((uint32_t) 16000000) // CAUTION: SystemCoreClockUpdate() is not implemented yet

/* Private peripheral bus base address */
#define PPB_BASEADDR       ((uint32_t) 0xE0000000)

/* PPB peripherals */
#define STK_BASEADDR       (PPB_BASEADDR + 0xE010) // 0xE000E010, SysTick timer base address
#define NVIC_BASEADDR      (PPB_BASEADDR + 0xE100) // 0xE000E100, Nested Vectored Interrupt Controller base address
#define SCB_BASEADDR1      (PPB_BASEADDR + 0xE008) // 0xE000E008, System Control Block base address with respect to ACTLR register
#define SCB_BASEADDR2      (PPB_BASEADDR + 0xED00) // 0xE000ED00, System Control Block base address with respect to CPUID register
#define MPU_BASEADDR       (PPB_BASEADDR + 0xED90) // 0xE000ED90, Memory Protection Unit base address
#define FPU_BASEADDR       (PPB_BASEADDR + 0xEF30) // 0xE000ED90, Floating Point Unit base address
 
/* STK base register address definition */
#define STK                ((STK_RegDef_t *) STK_BASEADDR)

/* STK registers definition */
typedef struct 
{
    volatile uint32_t CTRL;
    volatile uint32_t LOAD;
    volatile uint32_t VAL;
    volatile uint32_t CALIB;
}STK_RegDef_t;


/* NVIC base register address definition */
#define NVIC               ((NVIC_RegDef_t *) NVIC_BASEADDR)

/* NVIC registers definition */
/* Note that in stm32f407, there are only 82 IRQs, thus only 0th ~ 3rd
 * register are needed for every registers.
 */
typedef struct 
{
    volatile uint32_t ISER[8];        // Interrupt set-enable register, 8 in total
    volatile uint32_t RESERVED0[24];
    volatile uint32_t ICER[8];        // Interrupt clear-enable register, 8 in total
    volatile uint32_t RESERVED1[24];
    volatile uint32_t ISPR[8];        // Interrupt set-pendin register, 8 in total
    volatile uint32_t RESERVED2[24];
    volatile uint32_t ICPR[8];        // Interrupt clear-enable register, 8 in total
    volatile uint32_t RESERVED3[24];
    volatile uint32_t IABR[8];        // Interrupt active bit register, 8 in total
    volatile uint32_t RESERVED4[56];
    volatile uint8_t  IPR[240];         // Interrupt priority register, 8 in total
    volatile uint32_t RESERVED5[644];
    volatile uint32_t STIR[8];        // Software trigger interrupt register, 8 in total
}NVIC_RegDef_t;


/* SCB base register address definition */
#define SCB1                ((SCB1_RegDef_t *) SCB_BASEADDR1)
#define SCB2                ((SCB2_RegDef_t *) SCB_BASEADDR2)

/* SCB registers definition */
typedef struct
{
    volatile uint32_t ACTLR;               // Auxiliary control register
}SCB1_RegDef_t;


typedef struct 
{
    volatile uint32_t CPUID;               // CPUID base register
    volatile uint32_t ICSR;                // Interrupt control and state register
    volatile uint32_t VTOR;                // Vector table offset register
    volatile uint32_t AIRCR;               // Application interrupt and reset control register
    volatile uint32_t SCR;                 // System control register
    volatile uint32_t CCR;                 // Configuration and control register
    volatile uint32_t SHPR[3];             // System handler priority registers
    volatile uint32_t SHCSR;               // System handler control and state register
    volatile uint32_t CFSR;                // Configurable fault status register
    volatile uint32_t HFSR;                // Hard fault status register
    volatile uint32_t RESERVED;    
    volatile uint32_t MMFAR;               // Memory management fault address register
    volatile uint32_t BFAR;                // Bus fault address register
    volatile uint32_t AFSR;                // Auxiliary fault status register
}SCB2_RegDef_t;

/* SysTick features */
#define IS_SYSTICKS(ticks)  ((ticks) <= 0x00FFFFFF)
static inline void SysTick_Config(uint32_t ticks)
{
    if(!IS_SYSTICKS(ticks)){
        // Error handling
        return;
    }
    STK->CTRL = 0x07;
    STK->LOAD = ticks - 1;
    STK->VAL = 0;
}


#endif // _PPB_H_
