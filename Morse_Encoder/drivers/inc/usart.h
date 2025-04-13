/* 
 * This file contains all function prototypes of the USART peripheral.
 */


#ifndef _USART_H_
#define _USART_H_


#include <stdint.h>
#include "stm32f407.h"
#include "rcc.h"

#define IS_UART_PERIPH(USARTx) ( ((USARTx) == USART1) || \
                                  ((USARTx) == USART2) || \
                                  ((USARTx) == USART3) || \
                                  ((USARTx) == UART4)  || \
                                  ((USARTx) == UART5)  || \
                                  ((USARTx) == USART6)  )

#define IS_SYNC_UART_PERIPH(USARTx) ( ((USARTx) == USART1) || \
                                      ((USARTx) == USART2) || \
                                      ((USARTx) == USART3) || \
                                      ((USARTx) == USART6)  )

#define IS_USART_DATA(data) ( (data) <= 0x1FF )

typedef enum
{
    USART_OVER8_16 = 0,
    USART_OVER8_8  = 1,
}USART_Over8Rate_t;
#define IS_OVER8_RATE(rate) ( ((rate) == USART_OVER8_16) || ((rate) == USART_OVER8_8) )

/* USART mode definition */
#define USART_RX_MODE         (1 << 2) // 0000 0000 0000 0100
#define USART_TX_MODE         (1 << 3) // 0000 0000 0000 1000
#define IS_USART_MODE(mode)   ((mode) && 0xC)

/* USART baud rate definition */
typedef enum
{
    USART_BAUD_1200   = 1200,
    USART_BAUD_2400   = 2400,
    USART_BAUD_9600   = 9600,
    USART_BAUD_19200  = 19200,
    USART_BAUD_38400  = 38400,
    USART_BAUD_57600  = 57600,
    USART_BAUD_115200 = 115200,
    USART_BAUD_230400 = 230400,
    USART_BAUD_460800 = 460800,
    USART_BAUD_921600 = 921600,
    USART_BAUD_2M     = 2000000,
    USART_BAUD_3M     = 3000000,
}USART_BaudRate_t;
#define IS_USART_BAUDRATE(baud) ( ((baud) == USART_BAUD_1200)   || \
                                  ((baud) == USART_BAUD_2400)   || \
                                  ((baud) == USART_BAUD_9600)   || \
                                  ((baud) == USART_BAUD_19200)  || \
                                  ((baud) == USART_BAUD_38400)  || \
                                  ((baud) == USART_BAUD_57600)  || \
                                  ((baud) == USART_BAUD_115200) || \
                                  ((baud) == USART_BAUD_230400) || \
                                  ((baud) == USART_BAUD_460800) || \
                                  ((baud) == USART_BAUD_921600) || \
                                  ((baud) == USART_BAUD_2M)     || \
                                  ((baud) == USART_BAUD_3M) )

/* USART word length definition */
#define USART_WORDLEN_9BITS      (1 << 12) // 0001 0000 0000 0000
#define USART_WORDLEN_8BITS      0
#define IS_USART_WORDLEN(len)    ( ((len) == USART_WORDLEN_9BITS) || ((len) == USART_WORDLEN_8BITS) )

/* USART stop bits definition */
#define USART_STOPBITS_1        0
#define USART_STOPBITS_0_5      (0x01 << 12) // 0001 0000 0000 0000
#define USART_STOPBITS_2        (0x10 << 12) // 0010 0000 0000 0000
#define USART_STOPBITS_1_5      (0x11 << 12) // 0011 0000 0000 0000
#define IS_USART_STOPBITS(stop) ( ((stop) == USART_STOPBITS_1)   || \
                                  ((stop) == USART_STOPBITS_0_5) || \
                                  ((stop) == USART_STOPBITS_2)   || \
                                  ((stop) == USART_STOPBITS_1_5) )

/* USART parity definition */
#define USART_PARITY_NONE       0
#define USART_PARITY_EVEN       ((1 << 9) | (1 << 10)) // 0000 0110 0000 0000
#define USART_PARITY_ODD        (1 << 10)              // 0000 0100 0000 0000
#define IS_USART_PARITY(parity) ( ((parity) == USART_PARITY_NONE) || \
                                  ((parity) == USART_PARITY_EVEN) || \
                                  ((parity) == USART_PARITY_ODD) )

/* USART flow control definition */
#define USART_FLOW_CTRL_NONE         0
#define USART_FLOW_CTRL_CTS          (1 << 9)              // 0000 0010 0000 0000
#define USART_FLOW_CTRL_RTS          (1 << 8)              // 0000 0001 0000 0000
#define IS_USART_FLOW_CTRL(ctrl)   ( ((ctrl) && 0x300) || ((ctrl) == USART_FLOW_CTRL_NONE))
/* To enable CTS and RTS at the same time, do mode = USART_FLOW_CTRL_CTS | USART_FLOW_CTRL_CTS  */


/* USART flags definition */
#define USART_FLAG_PE       (1 << 0)  // PE, Parity error
#define USART_FLAG_FE       (1 << 1)  // FE, Framing error
#define USART_FLAG_NF       (1 << 2)  // NF, Noise detected flag
#define USART_FLAG_ORE      (1 << 3)  // ORE, Overrun error
#define USART_FLAG_IDLE     (1 << 4)  // IDLE, IDLE line detected
#define USART_FLAG_RXNE     (1 << 5)  // RXNE, Read data register not empty
#define USART_FLAG_TC       (1 << 6)  // TC, Transmission complete
#define USART_FLAG_TXE      (1 << 7)  // TXE, Transmit data register empty
#define USART_FLAG_LBD      (1 << 8)  // LBD, LIN break detection flag
#define USART_FLAG_CTS      (1 << 9)  // CTS, Clear To Send flag
#define IS_USART_FLAG(flag) ( ((flag) == USART_FLAG_PE)   || \
                              ((flag) == USART_FLAG_FE)   || \
                              ((flag) == USART_FLAG_NF)   || \
                              ((flag) == USART_FLAG_ORE)  || \
                              ((flag) == USART_FLAG_IDLE) || \
                              ((flag) == USART_FLAG_RXNE) || \
                              ((flag) == USART_FLAG_TC)   || \
                              ((flag) == USART_FLAG_TXE)  || \
                              ((flag) == USART_FLAG_LBD)  || \
                              ((flag) == USART_FLAG_CTS) )


/* USART initialization handle structure */
typedef struct
{
    USART_RegDef_t    *USARTx;         // USART peripheral
    USART_BaudRate_t   baudrate;       // Baud rate
    uint16_t           word_length;    // Word length
    uint16_t           stop_bits;      // Stop bits
    uint16_t           parity;         // Parity
    uint16_t           mode;           // Mode
    uint16_t           flow_control;   // Flow control
}USART_InitHandle_t;


/* Clock enable inline functions for USART perpheral */
static inline void USART1_ClkCtrl(Function_State_t state)    { RCC_APB2Peri_ClkCtrl(RCC_APB2_USART1, state); }
static inline void USART6_ClkCtrl(Function_State_t state)    { RCC_APB2Peri_ClkCtrl(RCC_APB2_USART6, state); }

static inline void USART2_ClkCtrl(Function_State_t state)    { RCC_APB1Peri_ClkCtrl(RCC_APB1_USART2, state); }
static inline void USART3_ClkCtrl(Function_State_t state)    { RCC_APB1Peri_ClkCtrl(RCC_APB1_USART3, state); }

static inline void UART4_ClkCtrl(Function_State_t state)     { RCC_APB1Peri_ClkCtrl(RCC_APB1_UART4, state); }
static inline void UART5_ClkCtrl(Function_State_t state)     { RCC_APB1Peri_ClkCtrl(RCC_APB1_UART5, state); }


/* 
 * Interfaces
 */

/* USART initialization and deinitialization */
void USART_Init(USART_InitHandle_t *handle);
void USART_DeInit(USART_RegDef_t *USARTx);

/* USART peripheral unable and disable */
void USART_PeriphCtrl(USART_RegDef_t *USARTx, Function_State_t state);

/* USART configurations */
void USART_Over8Config(USART_RegDef_t *USARTx, USART_Over8Rate_t rate);

/* USART transmit and receive */
void     USART_SendData(USART_RegDef_t *USARTx, uint16_t data);
uint16_t USART_ReceiveData(USART_RegDef_t *USARTx);

/* USART interrupt control */
void USART_IRQ_Config(uint8_t IRQn, Function_State_t state);
void USART_IRQ_PriorityConfig(uint8_t IRQn, uint32_t priority);
void USART_IRQ_Handling(USART_RegDef_t *USARTx);

/* USART flag management */
uint8_t USART_GetFlagStatus(USART_RegDef_t *USARTx, uint32_t flag);
void USART_ClearFlag(USART_RegDef_t *USARTx, uint32_t flag);

#endif // _USART_H_