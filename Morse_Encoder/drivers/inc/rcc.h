#ifndef _RCC_H_
#define _RCC_H_


#include <stdint.h>
#include "stm32f407.h"

/* AHB1 peripherals definition */
#define RCC_AHB1_GPIOA              (1 << 0)
#define RCC_AHB1_GPIOB              (1 << 1)
#define RCC_AHB1_GPIOC              (1 << 2)
#define RCC_AHB1_GPIOD              (1 << 3)
#define RCC_AHB1_GPIOE              (1 << 4)
#define RCC_AHB1_GPIOF              (1 << 5)
#define RCC_AHB1_GPIOG              (1 << 6)
#define RCC_AHB1_GPIOH              (1 << 7)
#define RCC_AHB1_GPIOI              (1 << 8)
#define RCC_AHB1_CRC                (1 << 12)
#define RCC_AHB1_BKPSRAM            (1 << 18)
#define RCC_AHB1_CCMDATARAM         (1 << 20)
#define RCC_AHB1_DMA1               (1 << 21)
#define RCC_AHB1_DMA2               (1 << 22)
#define RCC_AHB1_ETHMAC             (1 << 25)
#define RCC_AHB1_ETHMACTX           (1 << 26)
#define RCC_AHB1_ETHMACRX           (1 << 27)
#define RCC_AHB1_ETHMACPTP          (1 << 28)
#define RCC_AHB1_OTGHS              (1 << 29)
#define RCC_AHB1_OTGHSULPI          (1 << 30)

/* AHB2 peripherals definition */
#define RCC_AHB2_DCMI                (1 << 0)
#define RCC_AHB2_CRYP                (1 << 4)
#define RCC_AHB2_HASH                (1 << 5)
#define RCC_AHB2_RNG                 (1 << 6)
#define RCC_AHB2_OTGFS               (1 << 7)

/* AHB3 peripherals definition */
#define RCC_AHB3_FSMC                (1 << 0)

/* APB1 peripherals definition */
#define RCC_APB1_TIM2                    (1 << 0)
#define RCC_APB1_TIM3                    (1 << 1)
#define RCC_APB1_TIM4                    (1 << 2)
#define RCC_APB1_TIM5                    (1 << 3)
#define RCC_APB1_TIM6                    (1 << 4)
#define RCC_APB1_TIM7                    (1 << 5)
#define RCC_APB1_TIM12                   (1 << 6)
#define RCC_APB1_TIM13                   (1 << 7)
#define RCC_APB1_TIM14                   (1 << 8)
#define RCC_APB1_WWDG                    (1 << 11)
#define RCC_APB1_SPI2                    (1 << 14)
#define RCC_APB1_SPI3                    (1 << 15)
#define RCC_APB1_USART2                  (1 << 17)
#define RCC_APB1_USART3                  (1 << 18)
#define RCC_APB1_UART4                   (1 << 19)
#define RCC_APB1_UART5                   (1 << 20)
#define RCC_APB1_I2C1                    (1 << 21)
#define RCC_APB1_I2C2                    (1 << 22)
#define RCC_APB1_I2C3                    (1 << 23)
#define RCC_APB1_CAN1                    (1 << 25)
#define RCC_APB1_CAN2                    (1 << 26)
#define RCC_APB1_PWR                     (1 << 28)
#define RCC_APB1_DAC                     (1 << 29)

/* APB2 peripherals definition */
#define RCC_APB2_TIM1                    (1 << 0)
#define RCC_APB2_TIM8                    (1 << 1)
#define RCC_APB2_USART1                  (1 << 4)
#define RCC_APB2_USART6                  (1 << 5)
#define RCC_APB2_ADC1                    (1 << 8)
#define RCC_APB2_ADC2                    (1 << 9)
#define RCC_APB2_ADC3                    (1 << 10)
#define RCC_APB2_SDIO                    (1 << 11)
#define RCC_APB2_SPI1                    (1 << 12)
#define RCC_APB2_SYSCFG                  (1 << 14)
#define RCC_APB2_TIM9                    (1 << 16)
#define RCC_APB2_TIM10                   (1 << 17)
#define RCC_APB2_TIM11                   (1 << 18)

/* System clock and peripheral clocks type structure definition */
typedef struct
{
  uint32_t SYSCLK_Frequency;
  uint32_t HCLK_Frequency; 
  uint32_t PCLK1_Frequency;
  uint32_t PCLK2_Frequency;
}RCC_ClocksTypeDef;

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

/* Check the peripheral is under control by the RCC_AHB2xxx register */
static inline uint32_t IS_RCC_AHB2_PERIPH(uint32_t peripheral)
{
    return ((peripheral & 0xF1) && (peripheral != 0)); // 0xF1 = 0000 0000 0000 0000 0000 0000 1111 0001
}

/* Check the peripheral is under control by the RCC_AHB3xxx register */
static inline uint32_t IS_RCC_AHB3_PERIPH(uint32_t peripheral)
{
    return ((peripheral & 0x1) && (peripheral != 0));
}

/* Check the peripheral is under control by the RCC_APB1xxx register */
static inline uint32_t IS_RCC_APB1_PERIPH(uint32_t peripheral)
{
    return ((peripheral & 0x36FEC9FF) && (peripheral != 0)); // 0x36FEC9FF = 0011 0110 1111 1110 1100 1001 1111 1111
}

/* Check the peripheral is under control by the RCC_APB2ENR register */
static inline uint32_t IS_RCC_APB2EN_PERIPH(uint32_t peripheral)
{
    return ((peripheral & 0x00075F33) && (peripheral != 0)); // 0x00075F33 = 0000 0000 0000 0111 0101 1111 0011 0011
}

/* Check the peripheral is under control by the RCC_APB2RSTR register */
static inline uint32_t IS_RCC_APB2RST_PERIPH(uint32_t peripheral)
{
    return ((peripheral & 0x00075933) && (peripheral != 0)); // 0x00075933 = 0000 0000 0000 0111 0101 1001 0011 0011
}

/* 
 * Interfaces
 */

void RCC_AHB1Peri_ClkCtrl(uint32_t peripheral, Function_State_t state);
void RCC_AHB1Peri_Reset(uint32_t peripheral);

void RCC_AHB2Peri_ClkCtrl(uint32_t peripheral, Function_State_t state);
void RCC_AHB2Peri_Reset(uint32_t peripheral);

void RCC_AHB3Peri_ClkCtrl(uint32_t peripheral, Function_State_t state);
void RCC_AHB3Peri_Reset(uint32_t peripheral);

void RCC_APB1Peri_ClkCtrl(uint32_t peripheral, Function_State_t state);
void RCC_APB1Peri_Reset(uint32_t peripheral);

void RCC_APB2Peri_ClkCtrl(uint32_t peripheral, Function_State_t state);
void RCC_APB2Peri_Reset(uint32_t peripheral);

void RCC_GetClkFreq(RCC_ClocksTypeDef *clock);

#endif // _RCC_H_