
#include "usart.h"
#include "rcc.h"

/* USART_Init
 * USART initialization.
 * Please make sure to enable USART peripheral clock before initializtion.
 * To initialize the USART, a GPIO_InitHandle_t structure is required, which contains the following parameters:
 * 1. USARTx: The USART peripheral base address
 * 2. mode: Tx mode, Rx mode, or Tx/Rx mode
 * 3. Word length: The information length in every frame (8 bits, 9 bits)
 * 4. Stop bits: The number of stop bits (1 bit, 0.5 bit, 2 bits, 1.5 bits)
 * 5. Parity: The parity bit (none, even, odd)
 * 6. Baud rate: The baud rate of the USART
 * 7. Flow control: The flow control of the USART (none, CTS, RTS, CTS/RTS) */
void USART_Init(USART_InitHandle_t *handle)
{
    RCC_ClocksTypeDef RCC_clock;
    uint32_t f_CK = 0, usartdiv = 0, mantissa = 0, fraction = 0;
    uint32_t tempreg = 0x00;

    if(!IS_UART_PERIPH(handle->USARTx) || !IS_USART_BAUDRATE(handle->baudrate) || !IS_USART_WORDLEN(handle->word_length) || !IS_USART_STOPBITS(handle->stop_bits) || !IS_USART_PARITY(handle->parity) || !IS_USART_MODE(handle->mode) || !IS_USART_FLOW_CTRL(handle->flow_control)){
        // Error handling to be implemented
        return;
    }

    /* Register CR1 configuration.
     * The initialization paramters in the CR1 register are:
     * 1. Word length (Bit 12)
     * 2. Parity (Bit [9:10])
     * 3. Mode (Bit [2:3])
     */

    tempreg = handle->USARTx->CR1;
    tempreg &= 0xE9F3; // 1110 1001 1111 0011, clear the CR1 register
    tempreg |= (handle->word_length | handle->parity | handle->mode);
    handle->USARTx->CR1 = tempreg;

    /* Register CR2 configuration.
     * The initialization paramters in the CR2 register are:
     * 1. Stop bits (Bit [12:13])
     */
    handle->USARTx->CR2 &= 0xCFFF; // 1100 1111 1111 1111, clear the CR2 register

    handle->USARTx->CR2 |= handle->stop_bits;


    /* Register CR3 configuration.
     * The initialization paramters in the CR3 register are:
     * 1. Flow control (Bit [8:9])
     */
    handle->USARTx->CR3 &= 0xFCFF; // 1111 1100 1111 1111, clear the CR3 register

    handle->USARTx->CR3 |= handle->flow_control;

    /* Baud rate configuration */
    RCC_GetClkFreq(&RCC_clock);
    if(handle->USARTx == USART1 || handle->USARTx == USART6)
    {
        f_CK = (RCC_clock.PCLK2_Frequency);
    }
    else
    {
        f_CK = (RCC_clock.PCLK1_Frequency);
    }

    if(handle->USARTx->CR1 & (1 << 15)) // 8x oversampling rate
    {
        usartdiv = (25 * f_CK) / (2 * handle->baudrate);
    }
    else // 16x oversampling rate
    {
        usartdiv = (25 * f_CK) / (4 * handle->baudrate);
    }

    mantissa = usartdiv / 100;
    fraction = (usartdiv - (mantissa * 100));

    if(handle->USARTx->CR1 & (1 << 15)) // 8x oversampling rate
    {
        fraction = ((fraction * 8 + 50) / 100) & 0x07;
    }
    else // 16x oversampling rate
    {
        fraction = ((fraction * 16 + 50) / 100) & 0x0F;
    }

    tempreg = (mantissa << 4) | fraction;
    handle->USARTx->BRR = tempreg;
}


/* USART_DeInit
 * USART deinitialization.
 * Set all the USARTx registers to its reset values */
void USART_DeInit(USART_RegDef_t *USARTx)
{
    if(!IS_UART_PERIPH(USARTx)){
        // Error handling to be implemented
        return;
    }

    if(USARTx == USART1)
    {
        RCC_APB2Peri_Reset(RCC_APB2_USART1);
    }
    else if(USARTx == USART2)
    {
        RCC_APB1Peri_Reset(RCC_APB1_USART2);
    }
    else if(USARTx == USART3)
    {
        RCC_APB1Peri_Reset(RCC_APB1_USART3);
    }
    else if(USARTx == UART4)
    {
        RCC_APB1Peri_Reset(RCC_APB1_UART4);
    }
    else if(USARTx == UART5)
    {
        RCC_APB1Peri_Reset(RCC_APB1_UART5);
    }
    else if(USARTx == USART6)
    {
        RCC_APB2Peri_Reset(RCC_APB2_USART6);
    }
}

/* USART_PeriphCtrl
 * Unable the whole USART peripheral through the 13th bit of the CR1 register.
 * If the peripheral is not enabled, then the communication will not be valid. */
void USART_PeriphCtrl(USART_RegDef_t *USARTx, Function_State_t state)
{
    if(!IS_UART_PERIPH(USARTx) || !IS_FunctionState(state)){
        // Error handling to be implemented
        return;
    }

    if(state != ENABLE)
    {
        USARTx->CR1 &= ~(1 << 13);
    }
    else
    {
        USARTx->CR1 |= (1 << 13);
    }
}

/* USART_Over8Config
 * Configure the oversampling rate at the receiver (8x/16x) via OVER8 bit in CR1 register.
 * If 8x is adopted, high baud rate is avaliable, but the receiver more sensitive to clock deviation.
 * If 16x is adopted, the receiver will be more tolerate to clock deviation, but less baud rate is avaliable. */
void USART_Over8Config(USART_RegDef_t *USARTx, USART_Over8Rate_t rate)
{
    if(!IS_UART_PERIPH(USARTx) || !IS_OVER8_RATE(rate)){
        // Error handling to be implemented
        return;
    }

    if(rate == USART_OVER8_8)
    {
        USARTx->CR1 |= (1 << 15);
    }
    else
    {
        USARTx->CR1 &= ~(1 << 15);
    }
}

/* USART_SendData
 * Send data through the USART */
void USART_SendData(USART_RegDef_t *USARTx, uint16_t data)
{
    if(!IS_UART_PERIPH(USARTx) || !IS_USART_DATA(data)){
        // Error handling to be implemented
        return;
    }

    if(USARTx->CR1 & (1 << 12)) // Check if the word length is 9 bits
    {
        USARTx->DR = (data & 0x01FF); // 0x01FF = 0000 0001 1111 1111
    }
    else
    {
        USARTx->DR = (data & 0x00FF); // 0x00FF = 0000 0000 1111 1111
    }
}

uint16_t USART_ReceiveData(USART_RegDef_t *USARTx)
{
    if(!IS_UART_PERIPH(USARTx)){
        // Error handling to be implemented
        return 0xFFFF;
    }

    if(USARTx->CR1 & (1 << 12)) // Check if the word length is 9 bits
    {
        return (USARTx->DR & 0x01FF); // 0x01FF = 0000 0001 1111 1111
    }
    else
    {
        return (USARTx->DR & 0x00FF); // 0x00FF = 0000 0000 1111 1111
    }
}

/* USART_GetFlagStatus
 * Get all status of the USART flags. */
uint8_t USART_GetFlagStatus(USART_RegDef_t *USARTx, uint32_t flag)
{
    if(!IS_UART_PERIPH(USARTx) || !IS_USART_FLAG(flag)){
        // Error handling to be implemented
        return 0;
    }

    return (USARTx->SR & flag);
}
