# ifndef _GPIO_H_
# define _GPIO_H_


#include <stdint.h>
#include "AHB1.h"
#include "stm32f407.h"

typedef enum
{
    MODER_INPUT  = 0x00, // Input
    MODER_OUTPUT = 0x01, // Output
    MODER_ALT    = 0x02, // Alternate Function
    MODER_ANALOG = 0x03  // Analog
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


/* Clock enable inline functions fo GPIO ports */
static inline void GPIOA_ClkCtrl(RCC_ClockState_t state)    { RCC_AHB1Peri_ClkCtrl(RCC_AHB1_GPIOA, state); }
static inline void GPIOB_ClkCtrl(RCC_ClockState_t state)    { RCC_AHB1Peri_ClkCtrl(RCC_AHB1_GPIOB, state); }
static inline void GPIOC_ClkCtrl(RCC_ClockState_t state)    { RCC_AHB1Peri_ClkCtrl(RCC_AHB1_GPIOC, state); }
static inline void GPIOD_ClkCtrl(RCC_ClockState_t state)    { RCC_AHB1Peri_ClkCtrl(RCC_AHB1_GPIOD, state); }
static inline void GPIOE_ClkCtrl(RCC_ClockState_t state)    { RCC_AHB1Peri_ClkCtrl(RCC_AHB1_GPIOE, state); }
static inline void GPIOF_ClkCtrl(RCC_ClockState_t state)    { RCC_AHB1Peri_ClkCtrl(RCC_AHB1_GPIOF, state); }
static inline void GPIOG_ClkCtrl(RCC_ClockState_t state)    { RCC_AHB1Peri_ClkCtrl(RCC_AHB1_GPIOG, state); }
static inline void GPIOH_ClkCtrl(RCC_ClockState_t state)    { RCC_AHB1Peri_ClkCtrl(RCC_AHB1_GPIOH, state); }
static inline void GPIOI_ClkCtrl(RCC_ClockState_t state)    { RCC_AHB1Peri_ClkCtrl(RCC_AHB1_GPIOI, state); }

/* Check the validity of the initialization parameters */
static inline uint32_t IS_GPIO_PERIPH(GPIO_RegDef_t *GPIOx) { return (GPIOx == GPIOA || \
                                                                      GPIOx == GPIOB || \
                                                                      GPIOx == GPIOC || \
                                                                      GPIOx == GPIOD || \
                                                                      GPIOx == GPIOE || \
                                                                      GPIOx == GPIOF || \
                                                                      GPIOx == GPIOG || \
                                                                      GPIOx == GPIOH || \
                                                                      GPIOx == GPIOI); }
static inline uint32_t IS_GPIO_PIN(GPIO_PIN_t pin)               { return (pin <= GPIO_PIN_15);     }
static inline uint32_t IS_GPIO_MODE(MODER_t mode)                { return (mode <= MODER_ANALOG);   }
static inline uint32_t IS_GPIO_OTYPE(OTYPER_t otype)             { return (otype <= OTYPER_OD);     }
static inline uint32_t IS_GPIO_OSPEED(OSPEEDR_t ospeed)          { return (ospeed <= OSPEEDR_HIGH); }
static inline uint32_t IS_GPIO_PUPD(PUPDR_t pupd)                { return (pupd <= PUPDR_PD);       }
static inline uint32_t IS_GPIO_PIN_STATE(GPIO_PIN_STATE_t state) { return (state == GPIO_PIN_RESET || state == GPIO_PIN_SET); }


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