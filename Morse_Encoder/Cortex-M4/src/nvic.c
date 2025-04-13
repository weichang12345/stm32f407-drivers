#include "nvic.h"
#include "ppb.h"

#define VECTKEY    ((uint32_t)0x05FA0000) // To write AIRCR register successfully in NVIC_PriorGroupConfig(), VECTKEY is needed

/* NVIC_SetPriority
 * Set the group priority and subpriority of the IRQ.
 *
 * Since only 4 bits can be written, before setting the priorities,
 * the bit fields should be configured by NVIC_PriorGroupConfig().
 * 
 * GP4_SP0 = 0x300 => The [7:4] bits are (GGGG << 0) | (SSSS & 0000) = GGGG
 * GP3_SP1 = 0x400 => The [7:4] bits are (GGGG << 1) | (SSSS & 0001) = GGGS
 * GP2_SP2 = 0x500 => The [7:4] bits are (GGGG << 2) | (SSSS & 0011) = GGSS
 * GP1_SP3 = 0x600 => The [7:4] bits are (GGGG << 3) | (SSSS & 0111) = GSSS
 * GP0_SP4 = 0x700 => The [7:4] bits are (GGGG << 4) | (SSSS & 1111) = SSSS 
 */
void NVIC_SetPriority(NVIC_Handle_t *handle){
    /* Check whether the group priority and the subpriority are legal or not */
    if(handle == (void *)0 || !IS_IRQn_t(handle->IRQ_number) || !IS_Priority_Num(handle->group_priority) || !IS_Priority_Num(handle->sub_priority)){
        /* Error handling */
    }
    uint8_t shift = ((SCB2->AIRCR & 0x700) >> 0x8) - 0x3;
    uint8_t temp = (uint8_t)(handle->group_priority << shift) | (handle->sub_priority & (0x0F >> (4 - shift))); // The [7:4] bits
    NVIC->IPR[handle->IRQ_number] = temp << 4;

    if(IS_SYSTEM_HANDLER(handle->IRQ_number)){
        if ( (handle->IRQ_number == IRQn_MemoryManagement) || (handle->IRQ_number == IRQn_BusFault) || (handle->IRQ_number == IRQn_UsageFault) ){
            SCB2->SHPR[0] = temp;
        }else if(handle->IRQ_number == IRQn_SVCall){
            SCB2->SHPR[1] = temp;
        }else if(handle->IRQ_number == IRQn_PendSV || handle->IRQ_number == IRQn_SysTick){
            SCB2->SHPR[2] = temp;
        }
    }
} 

/* NVIC_PriorGroupConfig
 * Congifure the 4-bit bit field of group priority and subpriority.
 *
 * Let the binary value of group priority be GGGG, binary value of subpriority be SSSS.
 * There are 5 configurable modes:
 * 1. GP4_SP0: The value storing in IP[x] is configured as GGGG 0000, thus group priority = 0 ~ 15, no subpriority
 * 2. GP3_SP1: The value storing in IP[x] is configured as GGGS 0000, thus group priority = 0 ~ 11, subpriority = 0 ~ 3
 * 3. GP2_SP2: The value storing in IP[x] is configured as GGSS 0000, thus group priority = 0 ~ 7,  subpriority = 0 ~ 7
 * 4. GP1_SP3: The value storing in IP[x] is configured as GSSS 0000, thus group priority = 0 ~ 3,  subpriority = 0 ~ 11
 * 5. GP0_SP4: The value storing in IP[x] is configured as SSSS 0000, thus no group priority,  subpriority = 0 ~ 16
 * 
 * If NVIC_PriorGroupConfig is not called, the reset mode is GP4_SP0.
 */
void NVIC_PriorGroupConfig(Priority_Group_t group_type){
    if(!IS_Priority_Group_t(group_type)){
        /* Error handling */
    }
    /* DO NOT DO "|=" operation, since the 16th to 31th bit of AIRCR register will be read as 0xFA05 */
    SCB2->AIRCR = (VECTKEY | group_type);
}

void NVIC_IRQ_Enable(NVIC_Handle_t *handle)
{
    if(handle->IRQ_number < 32){
        NVIC->ISER[0] |= (1 << handle->IRQ_number);
    }else if((32 <= handle->IRQ_number) && (handle->IRQ_number < 64)){
        NVIC->ISER[1] |= (1 << (handle->IRQ_number & 0x1F)); // IRQn & 0x1F is equivalent to IRQn % 32
    }else if((64 <= handle->IRQ_number) && (handle->IRQ_number < 81)){
        NVIC->ISER[2] |= (1 << (handle->IRQ_number & 0x1F)); // IRQn & 0x1F is equivalent to IRQn % 32
    }else{
        /* Error handler */
    }
}


void NVIC_IRQ_Disable(NVIC_Handle_t *handle);

// uint32_t NVIC_GetPriority(IRQn_t irqn)
// {

// }

void NVIC_IRQ_SetPending(NVIC_Handle_t *handle);


void NVIC_IRQ_ClearPending(NVIC_Handle_t *handle);

