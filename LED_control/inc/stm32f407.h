#ifndef _STM32F407_H_
#define _STM32F407_H_


#include <stdint.h>

/* AHBx and APBx base addresses */
#define AHB1_BASEADDR       ((uint32_t) 0x40020000)
#define AHB2_BASEADDR       ((uint32_t) 0x50000000)
#define AHB3_BASEADDR       ((uint32_t) 0xA0000000)
#define APB1_BASEADDR       ((uint32_t) 0x40000000)
#define APB2_BASEADDR       ((uint32_t) 0x40010000)

/* APB1 peripherals */
#define TIM2_BASEADDR       (APB1_BASEADDR + 0x0000 ) // 0x40000000, Timer 2 base address
#define TIM3_BASEADDR       (APB1_BASEADDR + 0x0400 ) // 0x40000400, Timer 3 base address
#define TIM4_BASEADDR       (APB1_BASEADDR + 0x0800 ) // 0x40000800, Timer 4 base address
#define TIM5_BASEADDR       (APB1_BASEADDR + 0x0C00 ) // 0x40000C00, Timer 5 base address
#define TIM6_BASEADDR       (APB1_BASEADDR + 0x1000 ) // 0x40001000, Timer 6 base address
#define TIM7_BASEADDR       (APB1_BASEADDR + 0x1400 ) // 0x40001400, Timer 7 base address
#define TIM12_BASEADDR      (APB1_BASEADDR + 0x1800 ) // 0x40001800, Timer 12 base address
#define TIM13_BASEADDR      (APB1_BASEADDR + 0x1C00 ) // 0x40001C00, Timer 13 base address
#define TIM14_BASEADDR      (APB1_BASEADDR + 0x2000 ) // 0x40002000, Timer 14 base address
#define RTC_BASEADDR        (APB1_BASEADDR + 0x2800 ) // 0x40002800, Real Time Clock base address
#define WWDG_BASEADDR       (APB1_BASEADDR + 0x2C00 ) // 0x40002C00, Window Watchdog base address
#define IWDG_BASEADDR       (APB1_BASEADDR + 0x3000 ) // 0x40003000, Independent Watchdog base address
#define I2S2ext_BASEADDR    (APB1_BASEADDR + 0x3400 ) // 0x40003400, I2S 2 External base address
#define SPI2_BASEADDR       (APB1_BASEADDR + 0x3800 ) // 0x40003800, Serial Peripheral Interface 2 base address
#define SPI3_BASEADDR       (APB1_BASEADDR + 0x3C00 ) // 0x40003C00, Serial Peripheral Interface 3 base address
#define I2S3ext_BASEADDR    (APB1_BASEADDR + 0x4000 ) // 0x40004000, I2S 3 External base address
#define USART2_BASEADDR     (APB1_BASEADDR + 0x4400 ) // 0x40004400, USART 2 base address
#define USART3_BASEADDR     (APB1_BASEADDR + 0x4800 ) // 0x40004800, USART 3 base address
#define UART4_BASEADDR      (APB1_BASEADDR + 0x4C00 ) // 0x40004C00, UART 4 base address
#define UART5_BASEADDR      (APB1_BASEADDR + 0x5000 ) // 0x40005000, UART 5 base address
#define I2C1_BASEADDR       (APB1_BASEADDR + 0x5400 ) // 0x40005400, Inter-Integrated Circuit 1 base address
#define I2C2_BASEADDR       (APB1_BASEADDR + 0x5800 ) // 0x40005800, Inter-Integrated Circuit 2 base address
#define I2C3_BASEADDR       (APB1_BASEADDR + 0x5C00 ) // 0x40005C00, Inter-Integrated Circuit 3 base address
#define CAN1_BASEADDR       (APB1_BASEADDR + 0x6400 ) // 0x40006400, Controller Area Network 1 base address
#define CAN2_BASEADDR       (APB1_BASEADDR + 0x6800 ) // 0x40006800, Controller Area Network 2 base address
#define PWR_BASEADDR        (APB1_BASEADDR + 0x7000 ) // 0x40007000, Power Control base address
#define DAC_BASEADDR        (APB1_BASEADDR + 0x7400 ) // 0x40007400, Digital to Analog Converter base address
#define UART7_BASEADDR      (APB1_BASEADDR + 0x7800 ) // 0x40007800, UART7 base address
#define UART8_BASEADDR      (APB1_BASEADDR + 0x7C00 ) // 0x40007C00, UART8 base address

/* APB2 peripherals */
#define TIM1_BASEADDR       (APB2_BASEADDR + 0x0000 ) // 0x40010000, Timer 1 base address
#define TIM8_BASEADDR       (APB2_BASEADDR + 0x0400 ) // 0x40010400, Timer 8 base address
#define USART1_BASEADDR     (APB2_BASEADDR + 0x1000 ) // 0x40011000, USART 1 base address
#define USART6_BASEADDR     (APB2_BASEADDR + 0x1400 ) // 0x40011400, USART 6 base address
#define ADC1_BASEADDR       (APB2_BASEADDR + 0x2000 ) // 0x40012000, Analog to Digital Converter 1 base address
#define ADC2_BASEADDR       (APB2_BASEADDR + 0x2100 ) // 0x40012100, Analog to Digital Converter 2 base address
#define ADC3_BASEADDR       (APB2_BASEADDR + 0x2200 ) // 0x40012200, Analog to Digital Converter 3 base address
#define SDIO_BASEADDR       (APB2_BASEADDR + 0x2C00 ) // 0x40012C00, Secure Digital Input Output base address
#define SPI1_BASEADDR       (APB2_BASEADDR + 0x3000 ) // 0x40013000, Serial Peripheral Interface 1 base address
#define SPI4_BASEADDR       (APB2_BASEADDR + 0x3400 ) // 0x40013400, Serial Peripheral Interface 4 base address
#define SYSCFG_BASEADDR     (APB2_BASEADDR + 0x3800 ) // 0x40013800, System Configuration Controller base address
#define EXTI_BASEADDR       (APB2_BASEADDR + 0x3C00 ) // 0x40013C00, External Interrupt Controller base address
#define TIM9_BASEADDR       (APB2_BASEADDR + 0x4000 ) // 0x40014000, Timer 9 base address
#define TIM10_BASEADDR      (APB2_BASEADDR + 0x4400 ) // 0x40014400, Timer 10 base address
#define TIM11_BASEADDR      (APB2_BASEADDR + 0x4800 ) // 0x40014800, Timer 11 base address
#define SPI5_BASEADDR       (APB2_BASEADDR + 0x5000 ) // 0x40015000, Serial Peripheral Interface 5 base address
#define SPI6_BASEADDR       (APB2_BASEADDR + 0x5400 ) // 0x40015400, Serial Peripheral Interface 6 base address
#define SAI1_BASEADDR       (APB2_BASEADDR + 0x5800 ) // 0x40015800, Serial Audio Interface 1 base address
#define LTDC_BASEADDR       (APB2_BASEADDR + 0x6800 ) // 0x40016800, Liquid Crystal Display Controller base address

/* AHB1 peripherals */
#define GPIOA_BASEADDR      (AHB1_BASEADDR + 0x0000 ) // 0x40020000, GPIOA base address
#define GPIOB_BASEADDR      (AHB1_BASEADDR + 0x0400 ) // 0x40020400, GPIOB base address
#define GPIOC_BASEADDR      (AHB1_BASEADDR + 0x0800 ) // 0x40020800, GPIOC base address
#define GPIOD_BASEADDR      (AHB1_BASEADDR + 0x0C00 ) // 0x40020C00, GPIOD base address
#define GPIOE_BASEADDR      (AHB1_BASEADDR + 0x1000 ) // 0x40021000, GPIOE base address
#define GPIOF_BASEADDR      (AHB1_BASEADDR + 0x1400 ) // 0x40021400, GPIOF base address
#define GPIOG_BASEADDR      (AHB1_BASEADDR + 0x1800 ) // 0x40021800, GPIOG base address
#define GPIOH_BASEADDR      (AHB1_BASEADDR + 0x1C00 ) // 0x40021C00, GPIOH base address
#define GPIOI_BASEADDR      (AHB1_BASEADDR + 0x2000 ) // 0x40022000, GPIOI base address
#define GPIOJ_BASEADDR      (AHB1_BASEADDR + 0x2400 ) // 0x40022400, GPIOJ base address
#define GPIOK_BASEADDR      (AHB1_BASEADDR + 0x2800 ) // 0x40022800, GPIOK base address
#define CRC_BASEADDR        (AHB1_BASEADDR + 0x3000 ) // 0x40023000, Cycle Redundancy Check base address
#define RCC_BASEADDR        (AHB1_BASEADDR + 0x3800 ) // 0x40023800, Reset and Clock Control base address
#define FLASH_BASEADDR      (AHB1_BASEADDR + 0x3C00 ) // 0x40023C00, Flash Interface base address
#define BKPSRAM_BASEADDR    (AHB1_BASEADDR + 0x4000 ) // 0x40024000, Backup SRAM base address
#define DMA1_BASEADDR       (AHB1_BASEADDR + 0x6000 ) // 0x40026000, Direct Memory Access 1 base address
#define DMA2_BASEADDR       (AHB1_BASEADDR + 0x6400 ) // 0x40026400, Direct Memory Access 2 base address
#define ETHMAC_BASEADDR     (AHB1_BASEADDR + 0x8000 ) // 0x40028000, Ethernet MAC base address
#define DMA2D_BASEADDR      (AHB1_BASEADDR + 0xB000 ) // 0x4002B000, DMA2D base address
#define USBOTGHS_BASEADDR   (AHB1_BASEADDR + 0x20000) // 0x40040000, USB OTG HS base address

/* AHB2 peripherals */
#define USBOTGFS_BASEADDR   (AHB2_BASEADDR + 0x0000 ) // 0x50000000, USB OTG FS base address
#define DCMI_BASEADDR       (AHB2_BASEADDR + 0x50000) // 0x50050000, Digital Camera Interface base address
#define CRYP_BASEADDR       (AHB2_BASEADDR + 0x60000) // 0x50060000, Cryptographic Processor base address
#define HASH_BASEADDR       (AHB2_BASEADDR + 0x60400) // 0x50060400, Hash Processor base address
#define RNG_BASEADDR        (AHB2_BASEADDR + 0x60800) // 0x50060800, Random Number Generator base address

/* AHB3 peripherals */
#define FSMC_BASEADDR       (AHB3_BASEADDR + 0x0000 ) // 0xA0000000, Flexible Static Memory Controller base address

/* GPIO base addresses Definitions */
#define GPIOA               ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB               ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC               ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD               ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE               ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF               ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG               ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH               ((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI               ((GPIO_RegDef_t*)GPIOI_BASEADDR)
// #define GPIOJ               ((GPIO_RegDef_t*)GPIOJ_BASEADDR)
// #define GPIOK               ((GPIO_RegDef_t*)GPIOK_BASEADDR)

/* RCC register addresses definition */
// #define RCC_AHB1RSTR                     (*(volatile uint32_t *) (RCC_BASEADDR + 0x10)) // 0x40023810, AHB1 peripheral reset register
// #define RCC_AHB1ENR                      (*(volatile uint32_t *) (RCC_BASEADDR + 0x30)) // 0x40023830, AHB1 peripheral clock enable register
#define RCC                             ((RCC_RegDef_t*)RCC_BASEADDR)

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

/* GPIO registers definition */
typedef struct
{
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFRL;
    volatile uint32_t AFRH;
}GPIO_RegDef_t;

typedef struct 
{
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    volatile uint32_t AHB3RSTR;
    volatile uint32_t RESERVED0;
    volatile uint32_t APB1RSTR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t RESERVED1[2];
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    volatile uint32_t AHB3ENR;
    volatile uint32_t RESERVED2;
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;
    volatile uint32_t RESERVED3[2];
    volatile uint32_t AHB1LPENR;
    volatile uint32_t AHB2LPENR;
    volatile uint32_t AHB3LPENR;
    volatile uint32_t RESERVED4;
    volatile uint32_t APB1LPENR;
    volatile uint32_t APB2LPENR;
    volatile uint32_t RESERVED5[2];
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
    volatile uint32_t RESERVED6[2];
    volatile uint32_t SSCGR;
    volatile uint32_t PLLI2SCFGR;
}RCC_RegDef_t;


/* RCC registers definition */


#endif // _STM32F407_H_