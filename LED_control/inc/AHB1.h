#ifndef _AHB1_H_
#define _AHB1_H_


#include <stdint.h>

typedef enum
{
    DISABLE = 0,
    ENABLE  = 1 
}RCC_ClockState_t;


/* Check the peripheral is under control by the RCC_AHB1ENR register */
static inline uint32_t IS_RCC_AHB1EN_PERIPH(uint32_t peripheral)
{
    return ((peripheral & 0x7E7411FF) && (peripheral != 0)); // 0x7E7411FF = 0111 1110 0111 0100 0001 0001 1111 1111
}

/* Check the peripheral is under control by the RCC_AHB1RSTR register */
static inline uint32_t IS_RCC_AHB1RST_PERIPH(uint32_t peripheral)
{
    return ((peripheral & 0x226011FF) && (peripheral != 0)); // 0x226011FF = 0010 0010 0110 0000 0001 0001 1111 1111
}


/* 
 * Interfaces
 */

void RCC_AHB1Peri_ClkCtrl(uint32_t peripheral, RCC_ClockState_t state);
void RCC_AHB1Peri_Reset(uint32_t peripheral);


#endif // _AHB1_H_