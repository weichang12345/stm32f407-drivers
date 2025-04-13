
#include "module_conf.h"
#include "morse.h"

#define MAX_TMSG_LENGTH 100

uint8_t hello_msg[] = "Hello World!\r\n";
uint8_t enter_msg[] = "\r\nThe green LED is displaying the Morse code of the message\r\n";
uint8_t trans_msg[MAX_TMSG_LENGTH];
volatile uint32_t msTicks;


void USART3_Init(void)
{
    /* Enable the GPIO & USART3 peripheral clock */
    GPIOC_ClkCtrl(ENABLE);
    GPIOA_ClkCtrl(ENABLE);
    USART3_ClkCtrl(ENABLE);

    /* USART1 GPIO configuration */
    GPIO_InitHandle_t gpio_handle = {
        .GPIOx = GPIOC,
        .pin = GPIO_PIN_10,
        .mode = MODER_ALT,
        .otype = OTYPER_PP,
        .ospeed = OSPEEDR_HIGH,
        .pupd = PUPDR_PU,
    };
    GPIO_Init(&gpio_handle);
    GPIO_SetAF(GPIOC, GPIO_PIN_10, 7); // USART3 TX

    gpio_handle.pin = GPIO_PIN_11;
    GPIO_Init(&gpio_handle);
    GPIO_SetAF(GPIOC, GPIO_PIN_11, 7); // USART3 RX

    /* USART1 peripheral configuration */
    USART_InitHandle_t usart_handle = {
        .USARTx = USART3,
        .mode = USART_RX_MODE | USART_TX_MODE,
        .word_length = USART_WORDLEN_8BITS,
        .stop_bits = USART_STOPBITS_1,
        .parity = USART_PARITY_NONE,
        .baudrate = USART_BAUD_9600,
        .flow_control = USART_FLOW_CTRL_NONE,
    };
    USART_Init(&usart_handle);

    /* Enable the USART3 peripheral */
    USART_PeriphCtrl(USART3, ENABLE);

}

void Button_IT_Init(void)
{
    GPIO_InitHandle_t gpio_button_handle = {
        .GPIOx = GPIOA,
        .pin = GPIO_PIN_0,
        .mode = MODER_EXTI_RS,
        .otype = OTYPER_PP,
        .ospeed = OSPEEDR_HIGH,
        .pupd = PUPDR_NONE,
    };
    GPIO_Init(&gpio_button_handle); // Button

    NVIC_Handle_t button_IR_handle = {
        .IRQ_number = IRQn_EXTI0,
        .group_priority = 1,
        .sub_priority = 1,
    };

    NVIC_PriorGroupConfig(GP4_SP0);
    NVIC_SetPriority(&button_IR_handle);
    NVIC_IRQ_Enable(&button_IR_handle);
}

void Timer_Init(void)
{
    SysTick_Config(SystemCoreClock / 1000);

    NVIC_Handle_t timer_IR_handle = {
        .IRQ_number = IRQn_SysTick,
        .group_priority = 0,
        .sub_priority = 0,
    };

    NVIC_SetPriority(&timer_IR_handle);
    NVIC_IRQ_Enable(&timer_IR_handle);
}

void Green_LED_Init(void)
{
    GPIOD_ClkCtrl(ENABLE);

    GPIO_InitHandle_t gpio_led_handle = {
        .GPIOx = GPIOD,
        .pin = GPIO_PIN_12,
        .mode = MODER_OUTPUT,
        .otype = OTYPER_PP,
        .ospeed = OSPEEDR_HIGH,
        .pupd = PUPDR_NONE,
    };
    GPIO_Init(&gpio_led_handle); // Green LED
}

void usart_puts(uint8_t *s)
{
    while(*s != '\0'){
        while (!USART_GetFlagStatus(USART3, USART_FLAG_TXE));
        USART_SendData(USART3, *s);
        s++;
    }
}

void usart_gets()
{   
    uint8_t i = 0, data = 0;
    while(i < MAX_TMSG_LENGTH){
        while(!USART_GetFlagStatus(USART3, USART_FLAG_RXNE)){};
            data = USART_ReceiveData(USART3);
            trans_msg[i] = data;
            if(data == '\r') {
                usart_puts(enter_msg);
                break;
            }
            USART_SendData(USART3, data);
            i++;
    }
}

void usart_puts_IT(void)
{
    usart_puts(hello_msg);

    uint8_t i = 0;
    while (hello_msg[i] != '\r') {
        Morse_LED(hello_msg[i]);
        i++;
    }    

    /* Test decoder logic */
    // uint8_t SOS_msg[] = {1, 1, 1, 2, 0, mn0, 0, 2, 1, 1, 1, 2};
    // uint8_t SOS_msg_len = sizeof(SOS_msg)/sizeof(uint8_t);
    // uint8_t mid = 31, low = 0, high = 62;
    // for(uint8_t i = 0; i < SOS_msg_len; i++){
    //     if(SOS_msg[i] == 1){
    //         high = mid;
    //         mid = low + (high - low)/2;
    //     } else  if (SOS_msg[i] == 0){
    //         low = mid;
    //         mid = low + (high - low)/2 + 1; 
    //     } else {
    //         while (!USART_GetFlagStatus(USART3, USART_FLAG_TXE));
    //         USART_SendData(USART3, morse_decoder_table[mid]);
    //         mid = 31, low = 0, high = 62;
    //     }
    // }
    /*********************************** */
}


void clear_buffer(uint8_t *s, uint8_t size)
{
    for(uint8_t i = 0; i < size; i++){
        s[i] = 0;
    }
}

int main(void)
{

    USART3_Init();
    Button_IT_Init();
    Timer_Init();
    Green_LED_Init();
    

    register_EXTI0_callback(usart_puts_IT);

    // usart_puts(hello_msg);


    while(1){
        usart_gets();
        uint8_t i = 0;
        while (trans_msg[i] != '\r') {
            Morse_LED(trans_msg[i]);
            i++;
        }
        clear_buffer(trans_msg, sizeof(trans_msg)/sizeof(uint8_t));
    }

    return 0;
}
