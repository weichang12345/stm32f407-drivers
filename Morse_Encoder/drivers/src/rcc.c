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

/* ---------------------------------------------------------------------------- */



/* -------------------------------- AHB2 clock -------------------------------- */

/* RCC_AHB2Peri_ClkCtrl
 * Enable of disable AHB2 peripheral clock */
void RCC_AHB2Peri_ClkCtrl(uint32_t peripheral, Function_State_t state)
{
    if(!IS_RCC_AHB2_PERIPH(peripheral) || !IS_FunctionState(state)){
        // Error handling to be implemented
        return;
    }

    if (state != ENABLE)
    {
        RCC->AHB2ENR &= ~peripheral;
    }
    else
    {
        RCC->AHB2ENR |=  peripheral;
    }
}

/* RCC_AHB2Peri_Reset
 * Reset the register values of the selected AHB2 peripheral*/
void RCC_AHB2Peri_Reset(uint32_t peripheral)
{
    if(!IS_RCC_AHB2_PERIPH(peripheral)){
        // Error handling to be implemented
        return;
    }
    
    RCC->AHB2RSTR |= peripheral;
    RCC->AHB2RSTR &= ~peripheral;
}

/* ---------------------------------------------------------------------------- */



/* -------------------------------- AHB3 clock -------------------------------- */

/* RCC_AHB3Peri_ClkCtrl
 * Enable of disable AHB3 peripheral clock */
void RCC_AHB3Peri_ClkCtrl(uint32_t peripheral, Function_State_t state)
{
    if(!IS_RCC_AHB3_PERIPH(peripheral) || !IS_FunctionState(state)){
        // Error handling to be implemented
        return;
    }

    if (state != ENABLE)
    {
        RCC->AHB3ENR &= ~peripheral;
    }
    else
    {
        RCC->AHB3ENR |=  peripheral;
    }
}

/* RCC_AHB3Peri_Reset
 * Reset the register values of the selected AHB3 peripheral*/
void RCC_AHB3Peri_Reset(uint32_t peripheral)
{
    if(!IS_RCC_AHB3_PERIPH(peripheral)){
        // Error handling to be implemented
        return;
    }
    
    RCC->AHB3RSTR |= peripheral;
    RCC->AHB3RSTR &= ~peripheral;
}

/* ---------------------------------------------------------------------------- */



/* -------------------------------- APB1 clock -------------------------------- */

/* RCC_APB1Peri_ClkCtrl
 * Enable of disable APB1 peripheral clock */
void RCC_APB1Peri_ClkCtrl(uint32_t peripheral, Function_State_t state)
{
    if(!IS_RCC_APB1_PERIPH(peripheral) || !IS_FunctionState(state)){
        // Error handling to be implemented
        return;
    }

    if (state != ENABLE)
    {
        RCC->APB1ENR &= ~peripheral;
    }
    else
    {
        RCC->APB1ENR |=  peripheral;
    }
}

/* 
 * Reset the register values of the selected APB1 peripheral*/
void RCC_APB1Peri_Reset(uint32_t peripheral)
{
    if(!IS_RCC_APB1_PERIPH(peripheral)){
        // Error handling to be implemented
        return;
    }
    
    RCC->APB1RSTR |= peripheral;
    RCC->APB1RSTR &= ~peripheral;
}

/* ---------------------------------------------------------------------------- */



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

/* ---------------------------------------------------------------------------- */


/* RCC_GetClkFreq
 * Get all the peripheral clock frequencies.
 * Before calling, please declare a RCC_ClocksTypeDef stucture first and pass the structure
 * into the function */
void RCC_GetClkFreq(RCC_ClocksTypeDef *clock)
{
    uint32_t clksrc = 0, ahbpresc = 0, apbpresc1 = 0, apbpresc2 = 0;

    /* Get the system clock source */
    clksrc = (RCC->CFGR >> 2) & 0x3;
    if(clksrc == 0x00)
    {
        clock->SYSCLK_Frequency = 16000000;
    }
    else if(clksrc == 0x01)
    {
        clock->SYSCLK_Frequency = 8000000;
    }
    else if(clksrc == 0x02)
    {
        // To be implemented
    }
    else
    {
        clock->SYSCLK_Frequency = 16000000; // Default value
    }

    /* Get the AHB clock frequency */
    ahbpresc = (RCC->CFGR >> 4) & 0xF;
    if(ahbpresc < 8)
    {
        clock->HCLK_Frequency = clock->SYSCLK_Frequency;
    }
    else if(ahbpresc < 12)
    {
        clock->HCLK_Frequency = clock->SYSCLK_Frequency >> (ahbpresc - 7);
    }
    else
    {
        clock->HCLK_Frequency = clock->SYSCLK_Frequency >> (ahbpresc - 6);
    }

    /* Get the APB1 clock frequency */
    apbpresc1 = (RCC->CFGR >> 10) & 0x7;
    if(apbpresc1 < 4)
    {
        clock->PCLK1_Frequency = clock->HCLK_Frequency;
    }
    else
    {
        clock->PCLK1_Frequency = clock->HCLK_Frequency >> (apbpresc1 - 3);
    }

    /* Get the APB2 clock frequency */
    apbpresc2 = (RCC->CFGR >> 13) & 0x7;
    if(apbpresc2 < 4)
    {
        clock->PCLK2_Frequency = clock->HCLK_Frequency;
    }
    else
    {
        clock->PCLK2_Frequency = clock->HCLK_Frequency >> (apbpresc2 - 3);
    }

}

