#include <stdint.h>
#include "gpio.h"
#include "AHB1.h"
#include "stm32f407.h"

uint32_t global_variable = 0xFAFAFAFA;
uint32_t uninit_global_variable;

int main(void)
{
    /* Enable the clock for the GPIOD peripheral */
    GPIOD_ClkCtrl(ENABLE);
    GPIOA_ClkCtrl(ENABLE);

    /* Initialize GPIO that corresponds to the orange LED */
    GPIO_InitHandle_t orange_led_handle;
    orange_led_handle.GPIOx = GPIOD;
    orange_led_handle.pin = GPIO_PIN_13;
    orange_led_handle.mode = MODER_OUTPUT;
    orange_led_handle.otype = OTYPER_PP;
    orange_led_handle.ospeed = OSPEEDR_LOW;
    orange_led_handle.pupd = PUPDR_NONE;

    GPIO_InitHandle_t red_led_handle;
    red_led_handle.GPIOx = GPIOD;
    red_led_handle.pin = GPIO_PIN_14;
    red_led_handle.mode = MODER_OUTPUT;
    red_led_handle.otype = OTYPER_PP;
    red_led_handle.ospeed = OSPEEDR_LOW;
    red_led_handle.pupd = PUPDR_NONE;

    GPIO_InitHandle_t button_handle;
    button_handle.GPIOx = GPIOA;
    button_handle.pin = GPIO_PIN_0;
    button_handle.mode = MODER_INPUT;
    button_handle.otype = OTYPER_PP;
    button_handle.ospeed = OSPEEDR_LOW;
    button_handle.pupd = PUPDR_NONE;

    GPIO_Init(&orange_led_handle);
    GPIO_Init(&red_led_handle);
    GPIO_Init(&button_handle);

    while(1){
        /* Turn on the orange LED */
        GPIO_TogglePin(GPIOD, GPIO_PIN_13);
        for(uint32_t i = 0; i < 400000; i++);
        /* Turn off the orange LED*/
        GPIO_TogglePin(GPIOD, GPIO_PIN_13);
        for(uint32_t i = 0; i < 400000; i++);
        if(GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET){
            GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
        }
        else
        {
            GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
        }
        // GPIO_DeInit(GPIOD);
    }

    return 0;
}