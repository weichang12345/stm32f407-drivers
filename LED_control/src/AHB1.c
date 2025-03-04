#include "AHB1.h"
#include "stm32f407.h"

/* Enable of disable AHB1 peripheral clock */
void RCC_AHB1Peri_ClkCtrl(uint32_t peripheral, RCC_ClockState_t state)
{
    if(!IS_RCC_AHB1EN_PERIPH(peripheral)){
        // Error handling to be implemented
        return;
    }

    if (state == ENABLE)
    {
        RCC->AHB1ENR |=  peripheral;
    }
    else
    {
        RCC->AHB1ENR &= ~peripheral;
    }
}

/* Reset the register values of the selected AHB1 peripheral*/
void RCC_AHB1Peri_Reset(uint32_t peripheral)
{
    if(!IS_RCC_AHB1RST_PERIPH(peripheral)){
        // Error handling to be implemented
        return;
    }
    
    RCC->AHB1RSTR |= peripheral;
    RCC->AHB1RSTR &= ~peripheral;
}
