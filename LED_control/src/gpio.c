#include "stm32f407.h"
#include "gpio.h"
#include "AHB1.h"


/* GPIO initialization.
 * Please make sure to enbale AHB1 peripheral clock before initializtion.
 * To initialize the GPIO, a GPIO_InitHandle_t structure is required, which contains the following parameters:
 * 1. GPIOx: The GPIO peripheral base address
 * 2. pin: The pin number to be initialized
 * 3. mode: The mode of the pin (input, output, alternate function, analog)
 * 4. otype: The output type of the pin (push-pull, open-drain)
 * 5. ospeed: The output speed of the pin (low, medium, high, very high)
 * 6. pupd: The pull-up/pull-down configuration of the pin (none, pull-up, pull-down)
 */
void GPIO_Init(GPIO_InitHandle_t *handle)
{
    /* Check the parameters */
    if (handle == (void *)0 || !IS_GPIO_PERIPH(handle->GPIOx) || !IS_GPIO_PIN(handle->pin) || !IS_GPIO_MODE(handle->mode) || !IS_GPIO_OTYPE(handle->otype) || !IS_GPIO_OSPEED(handle->ospeed) || !IS_GPIO_PUPD(handle->pupd))
    {
        // Error handling to be implemented
        return;
    }

    /* Reset the pins */
    handle->GPIOx->MODER    &= ~(0x3 << (2 * handle->pin));
    handle->GPIOx->OTYPER   &= ~(0x1 <<      handle->pin);
    handle->GPIOx->OSPEEDR  &= ~(0x3 << (2 * handle->pin));
    handle->GPIOx->PUPDR    &= ~(0x3 << (2 * handle->pin));

    /* Set the pins */
    handle->GPIOx->OTYPER   |= (handle->otype   <<      handle->pin);
    handle->GPIOx->MODER    |= (handle->mode    << (2 * handle->pin));
    handle->GPIOx->OSPEEDR  |= (handle->ospeed  << (2 * handle->pin));
    handle->GPIOx->PUPDR    |= (handle->pupd    << (2 * handle->pin));
}

/* Set all the GPIOx registers to its reset values */
void GPIO_DeInit(GPIO_RegDef_t *GPIOx)
{
    if(!IS_GPIO_PERIPH(GPIOx)){
        // Error handling to be implemented
        return;
    }

    if (GPIOx == GPIOA)
    {
        RCC_AHB1Peri_Reset(RCC_AHB1_GPIOA);
    }
    else if (GPIOx == GPIOB)
    {
        RCC_AHB1Peri_Reset(RCC_AHB1_GPIOB);
    }
    else if (GPIOx == GPIOC)
    {
        RCC_AHB1Peri_Reset(RCC_AHB1_GPIOC);
    }
    else if (GPIOx == GPIOD)
    {
        RCC_AHB1Peri_Reset(RCC_AHB1_GPIOD);
    }
    else if (GPIOx == GPIOE)
    {
        RCC_AHB1Peri_Reset(RCC_AHB1_GPIOE);
    }
    else if (GPIOx == GPIOF)
    {
        RCC_AHB1Peri_Reset(RCC_AHB1_GPIOF);
    }
    else if (GPIOx == GPIOG)
    {
        RCC_AHB1Peri_Reset(RCC_AHB1_GPIOG);
    }
    else if (GPIOx == GPIOH)
    {
        RCC_AHB1Peri_Reset(RCC_AHB1_GPIOH);
    }
    else if (GPIOx == GPIOI)
    {
        RCC_AHB1Peri_Reset(RCC_AHB1_GPIOI);
    }
};

void GPIO_WritePin(GPIO_RegDef_t *GPIOx, GPIO_PIN_t pin, GPIO_PIN_STATE_t new_state)
{
    if(!IS_GPIO_PERIPH(GPIOx) || !IS_GPIO_PIN(pin) || !IS_GPIO_PIN_STATE(new_state)){
        // Error handling to be implemented
        return;
    }

    if(new_state == GPIO_PIN_SET)
    {
        GPIOx->BSRR = (1 << pin);
    }
    else
    {
        GPIOx->BSRR = (1 << (pin + 16));
    }
}

GPIO_PIN_STATE_t GPIO_ReadPin(GPIO_RegDef_t *GPIOx, GPIO_PIN_t pin)
{
    if(!IS_GPIO_PERIPH(GPIOx) || !IS_GPIO_PIN(pin)){
        // Error handling to be implemented
        return 0;
    }

    if( !((GPIOx->IDR >> pin) & 0x1) ){
        return GPIO_PIN_RESET;
    }
    else
    {
        return GPIO_PIN_SET;
    }
}

void GPIO_TogglePin(GPIO_RegDef_t *GPIOx, GPIO_PIN_t pin)
{
    if(!IS_GPIO_PERIPH(GPIOx) || !IS_GPIO_PIN(pin)){
        // Error handling to be implemented
        return;
    }

    GPIOx->ODR ^= (1 << pin);
}

void GPIO_SetAF(GPIO_RegDef_t *GPIOx, GPIO_PIN_t pin, uint32_t af)
{
    if(!IS_GPIO_PERIPH(GPIOx) || !IS_GPIO_PIN(pin) || af > 0xF){
        // Error handling to be implemented
        return;
    }

    if (pin <= GPIO_PIN_7)
    {
        GPIOx->AFRL &= ~(0xF << (4 * pin));
        GPIOx->AFRL |=  (af  << (4 * pin));
    }
    else
    {
        GPIOx->AFRH &= ~(0xF << (4 * (pin - 8)));
        GPIOx->AFRH |=  (af  << (4 * (pin - 8)));
    }
}
