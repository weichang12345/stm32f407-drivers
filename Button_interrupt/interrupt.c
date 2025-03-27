#include "module_conf.h"

typedef void (*ISR_Callback_t)(void);
static ISR_Callback_t EXTI0_Callback = 0;

void register_isr_callback(ISR_Callback_t callback) {
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