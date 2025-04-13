#include "interrupt.h"

static ISR_Callback_t EXTI0_Callback = 0;
extern volatile uint32_t msTicks;

void SysTick_Handler(void)
{
    if(msTicks != 0) {
        msTicks--;
    }
}


void register_EXTI0_callback(ISR_Callback_t callback) {
    EXTI0_Callback = callback;
}

void EXTI0_IRQHandler (void)
{
    /* IRQ handling */
    if (EXTI0_Callback != 0) {
        EXTI0_Callback();
    }

    // Clear the interrupt
    EXTI_ClearPendingBit(IRQn_EXTI0);
}

