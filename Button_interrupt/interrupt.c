#include "module_conf.h"


void EXTI0_IRQHandler (void)
{
    /* IRQ handling */
    GPIO_TogglePin(GPIOD, GPIO_PIN_14);
    for(uint32_t i = 0; i < 50000; i++);

    // Clear the interrupt
    EXTI_ClearPendingBit(IRQn_EXTI0);
}