#include "exti.h"


/* EXTI_Config
 * Configuration of the EXTI line settings.
 * Need not to call it actively, the GPIO module will handle if the 
 * GPIO mode is in interrupt mode */
void EXTI_Config(EXTI_ConfigHandle_t *handle)
{
    if(handle == (void *)0 || !IS_EXTI_LINE(handle->exti_line) || !IS_EXTI_MODE(handle->exti_mode) || !IS_EXTI_TRIG_MODE(handle->trigger_mode)){
        /* Error handling */
        return;
    }
    if(handle->exti_mode == HW_ITR){
        EXTI->IMR |= (1 << (handle->exti_line));
    }else if(handle->exti_mode == HW_EVT){
        EXTI->EMR |= (1 << (handle->exti_line));
    }

    /* Rising edge trigger selection */
    if(handle->trigger_mode == RISE_TRIG){         
        EXTI->RTSR &= ~(1 << (handle->exti_line));
        EXTI->RTSR |=  (1 << (handle->exti_line));
    /* Falling edge trigger selection */
    }else if(handle->trigger_mode == FALL_TRIG){   
        EXTI->FTSR &= ~(1 << (handle->exti_line));  
        EXTI->FTSR |=  (1 << (handle->exti_line));   
    /* Rising and falling edge trigger selection */
    }else if(handle->trigger_mode == RISE_FALL_TRIG){ 
        EXTI->RTSR &= ~(1 << (handle->exti_line));
        EXTI->RTSR |=  (1 << (handle->exti_line));
        EXTI->FTSR &= ~(1 << (handle->exti_line));  
        EXTI->FTSR |=  (1 << (handle->exti_line));  
    }
}
    
void EXTI_ClearPendingBit(uint32_t exti_line)
{
    if(!IS_EXTI_LINE(exti_line)){
        /* Error handling */
        return;
    }
    EXTI->PR |= (1 << exti_line);
}



