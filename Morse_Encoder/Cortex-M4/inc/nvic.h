/* 
 * This file contains all function prototypes of the 
 * Nested Vectored Interrupt Controller (NVIC) core peripheral.
 */

#ifndef _NVIC_H_
#define _NVIC_H_


#include "ppb.h"


typedef struct 
{
    IRQn_t              IRQ_number;
    uint8_t             group_priority;
    uint8_t             sub_priority;
}NVIC_Handle_t;

typedef enum
{
    GP4_SP0 = 0x300, // 4 bits for group priority, 0 bit for subpriority
    GP3_SP1 = 0x400, // 3 bits for group priority, 1 bit for subpriority
    GP2_SP2 = 0x500, // 2 bits for group priority, 2 bits for subpriority
    GP1_SP3 = 0x600, // 1 bit for group priority, 3 bits for subpriority
    GP0_SP4 = 0x700, // 0 bit for group priority, 4 bits for subpriority (preemption disabled)
}Priority_Group_t;

/* IABRx => IP[4x] - IP[4x+3]
0x300 = 0011 0000 0000 => GGGG 0000 tmppriority = 4 tmppre = 0 tmpsub = 0000 tmppriority = GGGG SP & tmpsub = 0000
0x400 = 0100 0000 0000 => GGGS 0000 tmppriority = 3 tmppre = 1 tmpsub = 0001 tmppriority = GGG0 SP & tmpsub = 000S
0x500 = 0101 0000 0000 => GGSS 0000 tmppriority = 2 tmppre = 2 tmpsub = 0011 tmppriority = GG00 SP & tmpsub = 00SS
0x600 = 0110 0000 0000 => GSSS 0000 tmppriority = 1 tmppre = 3 tmpsub = 0111 tmppriority = G000 SP & tmpsub = 0SSS
0x700 = 0111 0000 0000 => SSSS 0000 tmppriority = 0 tmppre = 4 tmpsub = 1111 tmppriority = 0000 SP & tmpsub = SSSS
*/

static inline uint32_t IS_Priority_Group_t(Priority_Group_t group_type) { return( (group_type == GP4_SP0) || \
                                                                         (group_type == GP3_SP1) || \
                                                                         (group_type == GP2_SP2) || \
                                                                         (group_type == GP1_SP3) || \
                                                                         (group_type == GP0_SP4)); }

static inline uint32_t IS_Priority_Num(uint32_t priority) { return (priority < 16); }



void NVIC_PriorGroupConfig(Priority_Group_t group_type);
void NVIC_SetPriority(NVIC_Handle_t *handle);
void NVIC_IRQ_Enable(NVIC_Handle_t *handle);
void NVIC_IRQ_Disable(NVIC_Handle_t *handle);
// uint32_t NVIC_GetPriority(IRQn_t irqn);
void NVIC_IRQ_SetPending(NVIC_Handle_t *handle);
void NVIC_IRQ_ClearPending(NVIC_Handle_t *handle);


#endif // _NVIC_H_