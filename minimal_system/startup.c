
#include <stdint.h>

#define SRAM_start   (uint32_t) 0x20000000               // Start position of SRAM
#define SRAM_size    (uint32_t) 128 * (uint32_t) 1024    // Size of SRAM
#define SRAM_end     ((SRAM_start) + (SRAM_size))        // End position of SRAM

#define STACK_START  SRAM_end  // The end of SRAM is the start of the stack

/* Symbols from linker script */
extern uint32_t _etext; // End of text section
extern uint32_t _sidata; // Start of data section IN LMA
extern uint32_t _sdata; // Start of data section
extern uint32_t _edata; // End of data section
extern uint32_t _sbss;  // Start of bss section
extern uint32_t _ebss;  // End of bss section

/* Extern main function */
extern int main(void);


/* Function prototypes */
void Reset_Handler                 (void)                                                ;  // Reset handler
void NMI_Handler                   (void) __attribute__((weak, alias("Default_Handler"))); // Non maskable interrupt handler. The RCC clock security system (CSS) is linked to the NMI vector.
void HardFault_Handler             (void) __attribute__((weak, alias("Default_Handler"))); // HardFault handler. All class of fault are linked to the HardFault exception.
void MemManage_Handler             (void) __attribute__((weak, alias("Default_Handler"))); // Memory management handler
void BusFault_Handler              (void) __attribute__((weak, alias("Default_Handler"))); // Pre-fetch fault, memory access fault
void UsageFault_Handler            (void) __attribute__((weak, alias("Default_Handler"))); // Undefined instruction or illegal state
void SVCall_Handler                (void) __attribute__((weak, alias("Default_Handler"))); // System service call via SWI instruction
void DebugMonitor_Handler          (void) __attribute__((weak, alias("Default_Handler"))); // Debug Monitor handler
void PendSV_Handler                (void) __attribute__((weak, alias("Default_Handler"))); // Pendable request for system service
void SysTick_Handler               (void) __attribute__((weak, alias("Default_Handler"))); // System tick timer
void WWDG_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); // Window Watchdog interrupt
void PVD_IRQHandler                (void) __attribute__((weak, alias("Default_Handler"))); // PVD through EXTI Line detection interrupt
void TAMP_STAMP_IRQHandler         (void) __attribute__((weak, alias("Default_Handler"))); // Tamper and TimeStamp through EXTI Line interrupts
void RTC_WKUP_IRQHandler           (void) __attribute__((weak, alias("Default_Handler"))); // RTC Wakeup through EXTI Line interrupt
void FLASH_IRQHandler              (void) __attribute__((weak, alias("Default_Handler"))); // Flash global interrupt
void RCC_IRQHandler                (void) __attribute__((weak, alias("Default_Handler"))); // RCC global interrupt
void EXTI0_IRQHandler              (void) __attribute__((weak, alias("Default_Handler"))); // EXTI Line 0 interrupt
void EXTI1_IRQHandler              (void) __attribute__((weak, alias("Default_Handler"))); // EXTI Line 1 interrupt
void EXTI2_IRQHandler              (void) __attribute__((weak, alias("Default_Handler"))); // EXTI Line 2 interrupt
void EXTI3_IRQHandler              (void) __attribute__((weak, alias("Default_Handler"))); // EXTI Line 3 interrupt
void EXTI4_IRQHandler              (void) __attribute__((weak, alias("Default_Handler"))); // EXTI Line 4 interrupt
void DMA1_Stream0_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); // DMA1 Stream 0 global interrupt
void DMA1_Stream1_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); // DMA1 Stream 1 global interrupt
void DMA1_Stream2_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); // DMA1 Stream 2 global interrupt
void DMA1_Stream3_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); // DMA1 Stream 3 global interrupt
void DMA1_Stream4_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); // DMA1 Stream 4 global interrupt
void DMA1_Stream5_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); // DMA1 Stream 5 global interrupt
void DMA1_Stream6_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); // DMA1 Stream 6 global interrupt
void ADC_IRQHandler                (void) __attribute__((weak, alias("Default_Handler"))); // ADC1, ADC2 and ADC3 global interrupt
void CAN1_TX_IRQHandler            (void) __attribute__((weak, alias("Default_Handler"))); // CAN1 TX interrupts
void CAN1_RX0_IRQHandler           (void) __attribute__((weak, alias("Default_Handler"))); // CAN1 RX0 interrupts
void CAN1_RX1_IRQHandler           (void) __attribute__((weak, alias("Default_Handler"))); // CAN1 RX1 interrupts
void CAN1_SCE_IRQHandler           (void) __attribute__((weak, alias("Default_Handler"))); // CAN1 SCE interrupt
void EXTI9_5_IRQHandler            (void) __attribute__((weak, alias("Default_Handler"))); // EXTI Line [9:5] interrupts
void TIM1_BRK_TIM9_IRQHandler      (void) __attribute__((weak, alias("Default_Handler"))); // TIM1 Break and TIM9 global interrupts
void TIM1_UP_TIM10_IRQHandler      (void) __attribute__((weak, alias("Default_Handler"))); // TIM1 Update and TIM10 global interrupts
void TIM1_TRG_COM_TIM11_IRQHandler (void) __attribute__((weak, alias("Default_Handler"))); // TIM1 Trigger and Commutation and TIM11 interrupts
void TIM1_CC_IRQHandler            (void) __attribute__((weak, alias("Default_Handler"))); // TIM1 Capture Compare interrupt
void TIM2_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); // TIM2 global interrupt
void TIM3_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); // TIM3 global interrupt
void TIM4_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); // TIM4 global interrupt
void I2C1_EV_IRQHandler            (void) __attribute__((weak, alias("Default_Handler"))); // I2C1 Event interrupt
void I2C1_ER_IRQHandler            (void) __attribute__((weak, alias("Default_Handler"))); // I2C1 Error interrupt
void I2C2_EV_IRQHandler            (void) __attribute__((weak, alias("Default_Handler"))); // I2C2 Event interrupt
void I2C2_ER_IRQHandler            (void) __attribute__((weak, alias("Default_Handler"))); // I2C2 Error interrupt
void SPI1_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); // SPI1 global interrupt
void SPI2_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); // SPI2 global interrupt
void USART1_IRQHandler             (void) __attribute__((weak, alias("Default_Handler"))); // USART1 global interrupt
void USART2_IRQHandler             (void) __attribute__((weak, alias("Default_Handler"))); // USART2 global interrupt
void USART3_IRQHandler             (void) __attribute__((weak, alias("Default_Handler"))); // USART3 global interrupt
void EXTI15_10_IRQHandler          (void) __attribute__((weak, alias("Default_Handler"))); // EXTI Line [15:10] interrupts
void RTC_Alarm_IRQHandler          (void) __attribute__((weak, alias("Default_Handler"))); // RTC Alarm (A and B) through EXTI Line interrupt
void OTG_FS_WKUP_IRQHandler        (void) __attribute__((weak, alias("Default_Handler"))); // USB OTG FS Wakeup through EXTI line interrupt
void TIM8_BRK_TIM12_IRQHandler     (void) __attribute__((weak, alias("Default_Handler"))); // TIM8 Break and TIM12 global interrupts
void TIM8_UP_TIM13_IRQHandler      (void) __attribute__((weak, alias("Default_Handler"))); // TIM8 Update and TIM13 global interrupts
void TIM8_TRG_COM_TIM14_IRQHandler (void) __attribute__((weak, alias("Default_Handler"))); // TIM8 Trigger and Commutation and TIM14 interrupts
void TIM8_CC_IRQHandler            (void) __attribute__((weak, alias("Default_Handler"))); // TIM8 Capture Compare interrupt
void DMA1_Stream7_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); // DMA1 Stream7 global interrupt
void FSMC_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); // FSMC global interrupt
void SDIO_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); // SDIO global interrupt
void TIM5_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); // TIM5 global interrupt
void SPI3_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); // SPI3 global interrupt
void UART4_IRQHandler              (void) __attribute__((weak, alias("Default_Handler"))); // UART4 global interrupt
void UART5_IRQHandler              (void) __attribute__((weak, alias("Default_Handler"))); // UART5 global interrupt
void TIM6_DAC_IRQHandler           (void) __attribute__((weak, alias("Default_Handler"))); // TIM6 and DAC1&2 underrun error interrupts
void TIM7_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); // TIM7 global interrupt
void DMA2_Stream0_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); // DMA2 Stream 0 global interrupt
void DMA2_Stream1_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); // DMA2 Stream 1 global interrupt
void DMA2_Stream2_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); // DMA2 Stream 2 global interrupt
void DMA2_Stream3_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); // DMA2 Stream 3 global interrupt
void DMA2_Stream4_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); // DMA2 Stream 4 global interrupt
void ETH_IRQHandler                (void) __attribute__((weak, alias("Default_Handler"))); // Ethernet global interrupt
void ETH_WKUP_IRQHandler           (void) __attribute__((weak, alias("Default_Handler"))); // Ethernet Wakeup through EXTI line interrupt
void CAN2_TX_IRQHandler            (void) __attribute__((weak, alias("Default_Handler"))); // CAN2 TX interrupts
void CAN2_RX0_IRQHandler           (void) __attribute__((weak, alias("Default_Handler"))); // CAN2 RX0 interrupts
void CAN2_RX1_IRQHandler           (void) __attribute__((weak, alias("Default_Handler"))); // CAN2 RX1 interrupts
void CAN2_SCE_IRQHandler           (void) __attribute__((weak, alias("Default_Handler"))); // CAN2 SCE interrupt
void OTG_FS_IRQHandler             (void) __attribute__((weak, alias("Default_Handler"))); // USB OTG FS global interrupt
void DMA2_Stream5_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); // DMA2 Stream 5 global interrupt
void DMA2_Stream6_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); // DMA2 Stream 6 global interrupt
void DMA2_Stream7_IRQHandler       (void) __attribute__((weak, alias("Default_Handler"))); // DMA2 Stream 7 global interrupt
void USART6_IRQHandler             (void) __attribute__((weak, alias("Default_Handler"))); // USART6 global interrupt
void I2C3_EV_IRQHandler            (void) __attribute__((weak, alias("Default_Handler"))); // I2C3 event interrupt
void I2C3_ER_IRQHandler            (void) __attribute__((weak, alias("Default_Handler"))); // I2C3 error interrupt
void OTG_HS_EP1_OUT_IRQHandler     (void) __attribute__((weak, alias("Default_Handler"))); // USB OTG HS End Point 1 Out global interrupt
void OTG_HS_EP1_IN_IRQHandler      (void) __attribute__((weak, alias("Default_Handler"))); // USB OTG HS End Point 1 In global interrupt
void OTG_HS_WKUP_IRQHandler        (void) __attribute__((weak, alias("Default_Handler"))); // USB OTG HS Wakeup through EXTI interrupt
void OTG_HS_IRQHandler             (void) __attribute__((weak, alias("Default_Handler"))); // USB OTG HS global interrupt
void DCMI_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); // DCMI global interrupt
void CRYP_IRQHandler               (void) __attribute__((weak, alias("Default_Handler"))); // CRYP crypto global interrupt
void HASH_RNG_IRQHandler           (void) __attribute__((weak, alias("Default_Handler"))); // Hash and Rng global interrupt
void FPU_IRQHandler                (void) __attribute__((weak, alias("Default_Handler"))); // FPU global interrupt

/* Create interrupt vector table */
const uint32_t interrupt_vector_table[] __attribute__((section(".IVT"))) = {
    // Stack and system handlers
    (uint32_t) STACK_START, // Initial stack pointer
    (uint32_t) &Reset_Handler,
    (uint32_t) &NMI_Handler,
    (uint32_t) &HardFault_Handler,
    (uint32_t) &MemManage_Handler,
    (uint32_t) &BusFault_Handler,
    (uint32_t) &UsageFault_Handler,
    0, // Reserved
    0, // Reserved
    0, // Reserved
    0, // Reserved
    (uint32_t) &SVCall_Handler,
    (uint32_t) &DebugMonitor_Handler,
    0, // Reserved
    (uint32_t) &PendSV_Handler,
    (uint32_t) &SysTick_Handler,
    // Interrupt request handlers
    (uint32_t) &WWDG_IRQHandler,
    (uint32_t) &PVD_IRQHandler,
    (uint32_t) &TAMP_STAMP_IRQHandler,
    (uint32_t) &RTC_WKUP_IRQHandler,
    (uint32_t) &FLASH_IRQHandler,
    (uint32_t) &RCC_IRQHandler,
    (uint32_t) &EXTI0_IRQHandler,
    (uint32_t) &EXTI1_IRQHandler,
    (uint32_t) &EXTI2_IRQHandler,
    (uint32_t) &EXTI3_IRQHandler,
    (uint32_t) &EXTI4_IRQHandler,
    (uint32_t) &DMA1_Stream0_IRQHandler,
    (uint32_t) &DMA1_Stream1_IRQHandler,
    (uint32_t) &DMA1_Stream2_IRQHandler,
    (uint32_t) &DMA1_Stream3_IRQHandler, 
    (uint32_t) &DMA1_Stream4_IRQHandler,
    (uint32_t) &DMA1_Stream5_IRQHandler,
    (uint32_t) &DMA1_Stream6_IRQHandler,
    (uint32_t) &ADC_IRQHandler,
    (uint32_t) &CAN1_TX_IRQHandler,
    (uint32_t) &CAN1_RX0_IRQHandler,
    (uint32_t) &CAN1_RX1_IRQHandler,
    (uint32_t) &CAN1_SCE_IRQHandler,
    (uint32_t) &EXTI9_5_IRQHandler,
    (uint32_t) &TIM1_BRK_TIM9_IRQHandler,
    (uint32_t) &TIM1_UP_TIM10_IRQHandler,
    (uint32_t) &TIM1_TRG_COM_TIM11_IRQHandler,
    (uint32_t) &TIM1_CC_IRQHandler,
    (uint32_t) &TIM2_IRQHandler,
    (uint32_t) &TIM3_IRQHandler,
    (uint32_t) &TIM4_IRQHandler,
    (uint32_t) &I2C1_EV_IRQHandler,
    (uint32_t) &I2C1_ER_IRQHandler,
    (uint32_t) &I2C2_EV_IRQHandler,
    (uint32_t) &I2C2_ER_IRQHandler,
    (uint32_t) &SPI1_IRQHandler,
    (uint32_t) &SPI2_IRQHandler,
    (uint32_t) &USART1_IRQHandler, 
    (uint32_t) &USART2_IRQHandler,
    (uint32_t) &USART3_IRQHandler,
    (uint32_t) &EXTI15_10_IRQHandler,
    (uint32_t) &RTC_Alarm_IRQHandler,
    (uint32_t) &OTG_FS_WKUP_IRQHandler,
    (uint32_t) &TIM8_BRK_TIM12_IRQHandler,
    (uint32_t) &TIM8_UP_TIM13_IRQHandler,
    (uint32_t) &TIM8_TRG_COM_TIM14_IRQHandler,
    (uint32_t) &TIM8_CC_IRQHandler,
    (uint32_t) &DMA1_Stream7_IRQHandler,
    (uint32_t) &FSMC_IRQHandler,
    (uint32_t) &SDIO_IRQHandler,
    (uint32_t) &TIM5_IRQHandler,
    (uint32_t) &SPI3_IRQHandler,
    (uint32_t) &UART4_IRQHandler,
    (uint32_t) &UART5_IRQHandler,
    (uint32_t) &TIM6_DAC_IRQHandler,
    (uint32_t) &TIM7_IRQHandler,
    (uint32_t) &DMA2_Stream0_IRQHandler,
    (uint32_t) &DMA2_Stream1_IRQHandler,
    (uint32_t) &DMA2_Stream2_IRQHandler,
    (uint32_t) &DMA2_Stream3_IRQHandler,
    (uint32_t) &DMA2_Stream4_IRQHandler,
    (uint32_t) &ETH_IRQHandler,
    (uint32_t) &ETH_WKUP_IRQHandler,
    (uint32_t) &CAN2_TX_IRQHandler,
    (uint32_t) &CAN2_RX0_IRQHandler,
    (uint32_t) &CAN2_RX1_IRQHandler,
    (uint32_t) &CAN2_SCE_IRQHandler,
    (uint32_t) &OTG_FS_IRQHandler,
    (uint32_t) &DMA2_Stream5_IRQHandler,
    (uint32_t) &DMA2_Stream6_IRQHandler,
    (uint32_t) &DMA2_Stream7_IRQHandler,
    (uint32_t) &USART6_IRQHandler,
    (uint32_t) &I2C3_EV_IRQHandler,
    (uint32_t) &I2C3_ER_IRQHandler,
    (uint32_t) &OTG_HS_EP1_OUT_IRQHandler,
    (uint32_t) &OTG_HS_EP1_IN_IRQHandler,
    (uint32_t) &OTG_HS_WKUP_IRQHandler,
    (uint32_t) &OTG_HS_IRQHandler,
    (uint32_t) &DCMI_IRQHandler,
    (uint32_t) &CRYP_IRQHandler,
    (uint32_t) &HASH_RNG_IRQHandler,
    (uint32_t) &FPU_IRQHandler,
};

/* Default handler, all exceptions will be directed to this handler if not specified elsewhere */
void Default_Handler(void)
{
    while(1);
}

/* Reset handler.
.data and .bss sections and system are initialized here, then main() is called */
void Reset_Handler(void)
{
    /* Copy the .data section from FLASH to SRAM */

    uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata; // Size of .data section

    uint8_t *pSrc = (uint8_t *)&_etext; // Location of .data section in FLASH
    uint8_t *pDst = (uint8_t *)&_sdata; // Location of .data section in SRAM

    for(uint32_t i = 0; i < size; i++)
    {
        *pDst++ = *pSrc++;
    }

    /* Initialize the .bss section to zero in SRAM */

    size = (uint32_t)&_ebss - (uint32_t)&_sbss; // Size of .bss section

    pDst = (uint8_t *)&_sbss; // Location of .bss section in SRAM

    for(uint32_t i = 0; i < size; i++)
    {
        *pDst++ = 0;
    }

    /* Call main function */

    main();

    while(1); // If main returns(should not return though), loop forever to prevent the program being untrackable

}
