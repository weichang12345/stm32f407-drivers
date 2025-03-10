#include "rcc.h"
#include "stm32f407.h"

/* -------------------------------- AHB1 clock -------------------------------- */

/* RCC_AHB1Peri_ClkCtrl
 * Enable of disable AHB1 peripheral clock */
void RCC_AHB1Peri_ClkCtrl(uint32_t peripheral, Function_State_t state)
{
    if(!IS_RCC_AHB1EN_PERIPH(peripheral) || !IS_FunctionState(state)){
        // Error handling to be implemented
        return;
    }

    if (state != ENABLE)
    {
        RCC->AHB1ENR &= ~peripheral;
    }
    else
    {
        RCC->AHB1ENR |=  peripheral;
    }
}

/* RCC_AHB1Peri_Reset
 * Reset the register values of the selected AHB1 peripheral*/
void RCC_AHB1Peri_Reset(uint32_t peripheral)
{
    if(!IS_RCC_AHB1RST_PERIPH(peripheral)){
        // Error handling to be implemented
        return;
    }
    
    RCC->AHB1RSTR |= peripheral;
    RCC->AHB1RSTR &= ~peripheral;
}


/* -------------------------------- APB2 clock -------------------------------- */

/* RCC_APB2Peri_ClkCtrl
 * Enable of disable APB2 peripheral clock */
void RCC_APB2Peri_ClkCtrl(uint32_t peripheral, Function_State_t state)
{
    if(!IS_RCC_APB2EN_PERIPH(peripheral) || !IS_FunctionState(state)){
        // Error handling to be implemented
        return;
    }

    if (state != ENABLE)
    {
        RCC->APB2ENR &= ~peripheral;
    }
    else
    {
        RCC->APB2ENR |=  peripheral;
    }
}

/* 
 * Reset the register values of the selected APB2 peripheral*/
void RCC_APB2Peri_Reset(uint32_t peripheral)
{
    if(!IS_RCC_APB2RST_PERIPH(peripheral)){
        // Error handling to be implemented
        return;
    }
    
    RCC->APB2RSTR |= peripheral;
    RCC->APB2RSTR &= ~peripheral;
}


