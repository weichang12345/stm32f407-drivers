/* 
 * This file contains all function prototypes of the GPIO peripheral.
 */


# ifndef _GPIO_H_
# define _GPIO_H_


#include <stdint.h>
#include "rcc.h"
#include "stm32f407.h"  

typedef enum
{
    MODER_INPUT      = 0x00, // Input
    MODER_OUTPUT     = 0x01, // Output
    MODER_ALT        = 0x02, // Alternate Function
    MODER_ANALOG     = 0x03, // Analog
    /* Interrupt modes */
    MODER_EXTI_RS    = 0x04, // External interrupt mode with rising edge trigger
    MODER_EXTI_FS    = 0x05, // External interrupt mode with falling edge trigger
    MODER_EXTI_RSFS  = 0x06, // External interrupt mode with rising and falling edge trigger
}MODER_t;

typedef enum
{
    OTYPER_PP = 0x00, // Push-Pull
    OTYPER_OD = 0x01  // Open-Drain
}OTYPER_t;

typedef enum
{
    OSPEEDR_LOW  = 0x00, // Low Speed (2~8MHz)
    OSPEEDR_MED  = 0x01, // Medium Speed (12.5~50MHz)
    OSPEEDR_FAST = 0x02, // Fast Speed (25~100MHz)
    OSPEEDR_HIGH = 0x03  // High Speed (50~180MHz)
}OSPEEDR_t;

typedef enum
{
    PUPDR_NONE = 0x00, // No Pull-up/Pull-down
    PUPDR_PU   = 0x01, // Pull-up
    PUPDR_PD   = 0x02  // Pull-down
}PUPDR_t;

typedef enum
{
    GPIO_PIN_RESET = 0x00,
    GPIO_PIN_SET   = 0x01
}GPIO_PIN_STATE_t;

typedef enum
{
    GPIO_PIN_0  = 0,
    GPIO_PIN_1  = 1,
    GPIO_PIN_2  = 2,
    GPIO_PIN_3  = 3,
    GPIO_PIN_4  = 4,
    GPIO_PIN_5  = 5,
    GPIO_PIN_6  = 6,
    GPIO_PIN_7  = 7,
    GPIO_PIN_8  = 8,
    GPIO_PIN_9  = 9,
    GPIO_PIN_10 = 10,
    GPIO_PIN_11 = 11,
    GPIO_PIN_12 = 12,
    GPIO_PIN_13 = 13,
    GPIO_PIN_14 = 14,
    GPIO_PIN_15 = 15
}GPIO_PIN_t;

typedef struct
{
    GPIO_RegDef_t *GPIOx;
    GPIO_PIN_t     pin;
    MODER_t        mode;
    OTYPER_t       otype;
    OSPEEDR_t      ospeed;
    PUPDR_t        pupd;
}GPIO_InitHandle_t;


/* Clock enable inline functions for GPIO ports */
static inline void GPIOA_ClkCtrl(Function_State_t state)    { RCC_AHB1Peri_ClkCtrl(RCC_AHB1_GPIOA, state); }
static inline void GPIOB_ClkCtrl(Function_State_t state)    { RCC_AHB1Peri_ClkCtrl(RCC_AHB1_GPIOB, state); }
static inline void GPIOC_ClkCtrl(Function_State_t state)    { RCC_AHB1Peri_ClkCtrl(RCC_AHB1_GPIOC, state); }
static inline void GPIOD_ClkCtrl(Function_State_t state)    { RCC_AHB1Peri_ClkCtrl(RCC_AHB1_GPIOD, state); }
static inline void GPIOE_ClkCtrl(Function_State_t state)    { RCC_AHB1Peri_ClkCtrl(RCC_AHB1_GPIOE, state); }
static inline void GPIOF_ClkCtrl(Function_State_t state)    { RCC_AHB1Peri_ClkCtrl(RCC_AHB1_GPIOF, state); }
static inline void GPIOG_ClkCtrl(Function_State_t state)    { RCC_AHB1Peri_ClkCtrl(RCC_AHB1_GPIOG, state); }
static inline void GPIOH_ClkCtrl(Function_State_t state)    { RCC_AHB1Peri_ClkCtrl(RCC_AHB1_GPIOH, state); }
static inline void GPIOI_ClkCtrl(Function_State_t state)    { RCC_AHB1Peri_ClkCtrl(RCC_AHB1_GPIOI, state); }

/* Check the validity of the initialization parameters */
static inline uint8_t IS_GPIO_PERIPH(GPIO_RegDef_t *GPIOx)      { return ( (GPIOx == GPIOA) || \
                                                                           (GPIOx == GPIOB) || \
                                                                           (GPIOx == GPIOC) || \
                                                                           (GPIOx == GPIOD) || \
                                                                           (GPIOx == GPIOE) || \
                                                                           (GPIOx == GPIOF) || \
                                                                           (GPIOx == GPIOG) || \
                                                                           (GPIOx == GPIOH) || \
                                                                           (GPIOx == GPIOI) ); }
static inline uint8_t IS_GPIO_PIN(GPIO_PIN_t pin)               { return (pin <= GPIO_PIN_15);     }
static inline uint8_t IS_GPIO_MODE(MODER_t mode)                { return ( (mode == MODER_INPUT  ) || \
                                                                           (mode == MODER_OUTPUT ) || \
                                                                           (mode == MODER_ALT    ) || \
                                                                           (mode == MODER_ANALOG ) || \
                                                                           (mode == MODER_EXTI_RS  ) || \
                                                                           (mode == MODER_EXTI_FS  ) || \
                                                                           (mode == MODER_EXTI_RSFS)  );}
static inline uint8_t IS_GPIO_EXIT_MODE(MODER_t mode)           { return ( (mode == MODER_EXTI_RS  ) || \
                                                                           (mode == MODER_EXTI_FS  ) || \
                                                                           (mode == MODER_EXTI_RSFS)  );} 
static inline uint8_t IS_GPIO_OTYPE(OTYPER_t otype)             { return ( (otype == OTYPER_PP) || (otype == OTYPER_OD) ); }
static inline uint8_t IS_GPIO_OSPEED(OSPEEDR_t ospeed)          { return ( (ospeed == OSPEEDR_LOW ) || \
                                                                           (ospeed == OSPEEDR_MED ) || \
                                                                           (ospeed == OSPEEDR_FAST) || \
                                                                           (ospeed == OSPEEDR_HIGH) ); }
static inline uint8_t IS_GPIO_PUPD(PUPDR_t pupd)                { return ( (pupd == PUPDR_NONE) || \
                                                                           (pupd == PUPDR_PU  ) || \
                                                                           (pupd == PUPDR_PD  ) ); }
static inline uint8_t IS_GPIO_PIN_STATE(GPIO_PIN_STATE_t state) { return ( (state == GPIO_PIN_RESET) || (state == GPIO_PIN_SET) ); }

/* Convert the EXTI line into IRQ number  4444444*/
static inline IRQn_t GPIO_EXTI_to_IRQn(GPIO_InitHandle_t *handle)
{        if(( 0 <= handle->pin) && (handle->pin <=  4)) return (IRQn_t) (handle->pin + 6);
    else if(( 5 <= handle->pin) && (handle->pin <=  9)) return IRQn_EXTI9_5;
    else if((10 <= handle->pin) && (handle->pin <= 15)) return IRQn_EXTI15_10;
    else                                                return IRQn_default; };

uint32_t GPIOx_to_SYSCFG_data(GPIO_RegDef_t *GPIOx);

/* 
 * Interfaces
 */

/* GPIO initialization and deinitialization */
void GPIO_Init(GPIO_InitHandle_t *handle);
void GPIO_DeInit(GPIO_RegDef_t *GPIOx);

/* Pin control */
void             GPIO_WritePin(GPIO_RegDef_t *GPIOx, GPIO_PIN_t pin, GPIO_PIN_STATE_t new_state);
GPIO_PIN_STATE_t GPIO_ReadPin(GPIO_RegDef_t *GPIOx, GPIO_PIN_t pin);
void             GPIO_TogglePin(GPIO_RegDef_t *GPIOx, GPIO_PIN_t pin);

/* Alternate function configuration */
void GPIO_SetAF(GPIO_RegDef_t *GPIOx, GPIO_PIN_t pin, uint32_t af);


# endif // _GPIO_H_