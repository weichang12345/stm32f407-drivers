#include <stdint.h>
#include "module_conf.h"

typedef void (*ISR_Callback_t)(void);
extern void register_isr_callback(ISR_Callback_t callback);

void LED_clockWise(void);
void LED_counterClockWise(void);
void toggle_LED_mode(void);

volatile int LED_mode = 0;
int step = 0;


GPIO_InitHandle_t green_led_handle;
// green_led_handle.GPIOx = GPIOD;
// green_led_handle.pin = GPIO_PIN_12;
// green_led_handle.mode = MODER_OUTPUT;
// green_led_handle.otype = OTYPER_PP;
// green_led_handle.ospeed = OSPEEDR_LOW;
// green_led_handle.pupd = PUPDR_NONE;

GPIO_InitHandle_t orange_led_handle;
// orange_led_handle.GPIOx = GPIOD;
// orange_led_handle.pin = GPIO_PIN_13;
// orange_led_handle.mode = MODER_OUTPUT;
// orange_led_handle.otype = OTYPER_PP;
// orange_led_handle.ospeed = OSPEEDR_LOW;
// orange_led_handle.pupd = PUPDR_NONE;

GPIO_InitHandle_t red_led_handle;
// red_led_handle.GPIOx = GPIOD;
// red_led_handle.pin = GPIO_PIN_14;
// red_led_handle.mode = MODER_OUTPUT;
// red_led_handle.otype = OTYPER_PP;
// red_led_handle.ospeed = OSPEEDR_LOW;
// red_led_handle.pupd = PUPDR_NONE;

GPIO_InitHandle_t blue_led_handle;
// blue_led_handle.GPIOx = GPIOD;
// blue_led_handle.pin = GPIO_PIN_15;
// blue_led_handle.mode = MODER_OUTPUT;
// blue_led_handle.otype = OTYPER_PP;
// blue_led_handle.ospeed = OSPEEDR_LOW;
// blue_led_handle.pupd = PUPDR_NONE;


GPIO_InitHandle_t button_handle;
// button_handle.GPIOx = GPIOA;
// button_handle.pin = GPIO_PIN_0;
// button_handle.mode = MODER_EXTI_RS;
// button_handle.otype = OTYPER_PP;
// button_handle.ospeed = OSPEEDR_LOW;
// button_handle.pupd = PUPDR_NONE;

NVIC_Handle_t button_IR_handle;
// button_IR_handle.IRQ_number = IRQn_EXTI0;
// button_IR_handle.group_priority = 1;
// button_IR_handle.sub_priority = 1;

int main(void)
{
    /* Enable the clock for the GPIOD peripheral */
    GPIOD_ClkCtrl(ENABLE);
    GPIOA_ClkCtrl(ENABLE);

    green_led_handle.GPIOx = GPIOD;
    green_led_handle.pin = GPIO_PIN_12;
    green_led_handle.mode = MODER_OUTPUT;
    green_led_handle.otype = OTYPER_PP;
    green_led_handle.ospeed = OSPEEDR_LOW;
    green_led_handle.pupd = PUPDR_NONE;

    orange_led_handle.GPIOx = GPIOD;
    orange_led_handle.pin = GPIO_PIN_13;
    orange_led_handle.mode = MODER_OUTPUT;
    orange_led_handle.otype = OTYPER_PP;
    orange_led_handle.ospeed = OSPEEDR_LOW;
    orange_led_handle.pupd = PUPDR_NONE;

    red_led_handle.GPIOx = GPIOD;
    red_led_handle.pin = GPIO_PIN_14;
    red_led_handle.mode = MODER_OUTPUT;
    red_led_handle.otype = OTYPER_PP;
    red_led_handle.ospeed = OSPEEDR_LOW;
    red_led_handle.pupd = PUPDR_NONE;

    blue_led_handle.GPIOx = GPIOD;
    blue_led_handle.pin = GPIO_PIN_15;
    blue_led_handle.mode = MODER_OUTPUT;
    blue_led_handle.otype = OTYPER_PP;
    blue_led_handle.ospeed = OSPEEDR_LOW;
    blue_led_handle.pupd = PUPDR_NONE;

    button_handle.GPIOx = GPIOA;
    button_handle.pin = GPIO_PIN_0;
    button_handle.mode = MODER_EXTI_RS;
    button_handle.otype = OTYPER_PP;
    button_handle.ospeed = OSPEEDR_LOW;
    button_handle.pupd = PUPDR_NONE;

    button_IR_handle.IRQ_number = IRQn_EXTI0;
    button_IR_handle.group_priority = 1;
    button_IR_handle.sub_priority = 1;

    GPIO_Init(&green_led_handle);
    GPIO_Init(&orange_led_handle);
    GPIO_Init(&red_led_handle);
    GPIO_Init(&blue_led_handle);
    GPIO_Init(&button_handle);

    NVIC_PriorGroupConfig(GP4_SP0);
    NVIC_SetPriority(&button_IR_handle);
    NVIC_IRQ_Enable(&button_IR_handle);

    register_isr_callback(toggle_LED_mode);

    while(1){
        if(LED_mode == 0) {
            LED_clockWise();
        } else {
            LED_counterClockWise();
        }
        for(uint32_t i = 0; i < 400000; i++);

    }

    return 0;
}

void LED_clockWise(void)
{
    switch(step) {
        case 0:
            GPIO_TogglePin(GPIOD, GPIO_PIN_12);
            break;
        case 1:
            GPIO_TogglePin(GPIOD, GPIO_PIN_13);
            break;
        case 2:
            GPIO_TogglePin(GPIOD, GPIO_PIN_14);
            break;
        case 3:
            GPIO_TogglePin(GPIOD, GPIO_PIN_15);
            break;
    }
    step = (step + 1) % 4;
}

void LED_counterClockWise(void)
{
    switch(step) {
        case 0:
            GPIO_TogglePin(GPIOD, GPIO_PIN_12);
            break;
        case 1:
            GPIO_TogglePin(GPIOD, GPIO_PIN_15);
            break;
        case 2:
            GPIO_TogglePin(GPIOD, GPIO_PIN_14);
            break;
        case 3:
            GPIO_TogglePin(GPIOD, GPIO_PIN_13);
            break;
    }
    step = (step + 1) % 4;
}

void toggle_LED_mode(void) {
    if (LED_mode == 0) {
        LED_mode = 1;
        step = 0;
        for(uint32_t i = 0; i < 100000; i++);
        RCC_AHB1Peri_Reset(RCC_AHB1_GPIOD);
        GPIO_Init(&green_led_handle);
        GPIO_Init(&orange_led_handle);
        GPIO_Init(&red_led_handle);
        GPIO_Init(&blue_led_handle);
        LED_clockWise();
    } else {
        LED_mode = 0; 
        step = 0;
        for(uint32_t i = 0; i < 100000; i++);
        RCC_AHB1Peri_Reset(RCC_AHB1_GPIOD);
        GPIO_Init(&green_led_handle);
        GPIO_Init(&orange_led_handle);
        GPIO_Init(&red_led_handle);
        GPIO_Init(&blue_led_handle);
        LED_counterClockWise();
    }
}

