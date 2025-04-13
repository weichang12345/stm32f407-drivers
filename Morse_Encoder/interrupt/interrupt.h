
#ifndef _INTERRUPT_H_
#define _INTERRUPT_H_

#include "module_conf.h"

typedef void (*ISR_Callback_t)(void);

void register_EXTI0_callback(ISR_Callback_t callback);


#endif // _INTERRUPT_H_
