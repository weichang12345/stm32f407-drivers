	.cpu cortex-m4
	.arch armv7e-m
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"startup.c"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.file 1 "startup.c"
	.global	interrupt_vector_table
	.section	.IVT,"a"
	.align	2
	.type	interrupt_vector_table, %object
	.size	interrupt_vector_table, 392
interrupt_vector_table:
	.word	537001984
	.word	Reset_Handler
	.word	NMI_Handler
	.word	HardFault_Handler
	.word	MemManage_Handler
	.word	BusFault_Handler
	.word	UsageFault_Handler
	.word	0
	.word	0
	.word	0
	.word	0
	.word	SVCall_Handler
	.word	DebugMonitor_Handler
	.word	0
	.word	PendSV_Handler
	.word	SysTick_Handler
	.word	WWDG_IRQHandler
	.word	PVD_IRQHandler
	.word	TAMP_STAMP_IRQHandler
	.word	RTC_WKUP_IRQHandler
	.word	FLASH_IRQHandler
	.word	RCC_IRQHandler
	.word	EXTI0_IRQHandler
	.word	EXTI1_IRQHandler
	.word	EXTI2_IRQHandler
	.word	EXTI3_IRQHandler
	.word	EXTI4_IRQHandler
	.word	DMA1_Stream0_IRQHandler
	.word	DMA1_Stream1_IRQHandler
	.word	DMA1_Stream2_IRQHandler
	.word	DMA1_Stream3_IRQHandler
	.word	DMA1_Stream4_IRQHandler
	.word	DMA1_Stream5_IRQHandler
	.word	DMA1_Stream6_IRQHandler
	.word	ADC_IRQHandler
	.word	CAN1_TX_IRQHandler
	.word	CAN1_RX0_IRQHandler
	.word	CAN1_RX1_IRQHandler
	.word	CAN1_SCE_IRQHandler
	.word	EXTI9_5_IRQHandler
	.word	TIM1_BRK_TIM9_IRQHandler
	.word	TIM1_UP_TIM10_IRQHandler
	.word	TIM1_TRG_COM_TIM11_IRQHandler
	.word	TIM1_CC_IRQHandler
	.word	TIM2_IRQHandler
	.word	TIM3_IRQHandler
	.word	TIM4_IRQHandler
	.word	I2C1_EV_IRQHandler
	.word	I2C1_ER_IRQHandler
	.word	I2C2_EV_IRQHandler
	.word	I2C2_ER_IRQHandler
	.word	SPI1_IRQHandler
	.word	SPI2_IRQHandler
	.word	USART1_IRQHandler
	.word	USART2_IRQHandler
	.word	USART3_IRQHandler
	.word	EXTI15_10_IRQHandler
	.word	RTC_Alarm_IRQHandler
	.word	OTG_FS_WKUP_IRQHandler
	.word	TIM8_BRK_TIM12_IRQHandler
	.word	TIM8_UP_TIM13_IRQHandler
	.word	TIM8_TRG_COM_TIM14_IRQHandler
	.word	TIM8_CC_IRQHandler
	.word	DMA1_Stream7_IRQHandler
	.word	FSMC_IRQHandler
	.word	SDIO_IRQHandler
	.word	TIM5_IRQHandler
	.word	SPI3_IRQHandler
	.word	UART4_IRQHandler
	.word	UART5_IRQHandler
	.word	TIM6_DAC_IRQHandler
	.word	TIM7_IRQHandler
	.word	DMA2_Stream0_IRQHandler
	.word	DMA2_Stream1_IRQHandler
	.word	DMA2_Stream2_IRQHandler
	.word	DMA2_Stream3_IRQHandler
	.word	DMA2_Stream4_IRQHandler
	.word	ETH_IRQHandler
	.word	ETH_WKUP_IRQHandler
	.word	CAN2_TX_IRQHandler
	.word	CAN2_RX0_IRQHandler
	.word	CAN2_RX1_IRQHandler
	.word	CAN2_SCE_IRQHandler
	.word	OTG_FS_IRQHandler
	.word	DMA2_Stream5_IRQHandler
	.word	DMA2_Stream6_IRQHandler
	.word	DMA2_Stream7_IRQHandler
	.word	USART6_IRQHandler
	.word	I2C3_EV_IRQHandler
	.word	I2C3_ER_IRQHandler
	.word	OTG_HS_EP1_OUT_IRQHandler
	.word	OTG_HS_EP1_IN_IRQHandler
	.word	OTG_HS_WKUP_IRQHandler
	.word	OTG_HS_IRQHandler
	.word	DCMI_IRQHandler
	.word	CRYP_IRQHandler
	.word	HASH_RNG_IRQHandler
	.word	FPU_IRQHandler
	.text
	.align	1
	.global	Default_Handler
	.syntax unified
	.thumb
	.thumb_func
	.type	Default_Handler, %function
Default_Handler:
.LFB0:
	.loc 1 222 1
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	.cfi_def_cfa_offset 4
	.cfi_offset 7, -4
	add	r7, sp, #0
	.cfi_def_cfa_register 7
.L2:
	.loc 1 223 10
	nop
	b	.L2
	.cfi_endproc
.LFE0:
	.size	Default_Handler, .-Default_Handler
	.weak	FPU_IRQHandler
	.thumb_set FPU_IRQHandler,Default_Handler
	.weak	HASH_RNG_IRQHandler
	.thumb_set HASH_RNG_IRQHandler,Default_Handler
	.weak	CRYP_IRQHandler
	.thumb_set CRYP_IRQHandler,Default_Handler
	.weak	DCMI_IRQHandler
	.thumb_set DCMI_IRQHandler,Default_Handler
	.weak	OTG_HS_IRQHandler
	.thumb_set OTG_HS_IRQHandler,Default_Handler
	.weak	OTG_HS_WKUP_IRQHandler
	.thumb_set OTG_HS_WKUP_IRQHandler,Default_Handler
	.weak	OTG_HS_EP1_IN_IRQHandler
	.thumb_set OTG_HS_EP1_IN_IRQHandler,Default_Handler
	.weak	OTG_HS_EP1_OUT_IRQHandler
	.thumb_set OTG_HS_EP1_OUT_IRQHandler,Default_Handler
	.weak	I2C3_ER_IRQHandler
	.thumb_set I2C3_ER_IRQHandler,Default_Handler
	.weak	I2C3_EV_IRQHandler
	.thumb_set I2C3_EV_IRQHandler,Default_Handler
	.weak	USART6_IRQHandler
	.thumb_set USART6_IRQHandler,Default_Handler
	.weak	DMA2_Stream7_IRQHandler
	.thumb_set DMA2_Stream7_IRQHandler,Default_Handler
	.weak	DMA2_Stream6_IRQHandler
	.thumb_set DMA2_Stream6_IRQHandler,Default_Handler
	.weak	DMA2_Stream5_IRQHandler
	.thumb_set DMA2_Stream5_IRQHandler,Default_Handler
	.weak	OTG_FS_IRQHandler
	.thumb_set OTG_FS_IRQHandler,Default_Handler
	.weak	CAN2_SCE_IRQHandler
	.thumb_set CAN2_SCE_IRQHandler,Default_Handler
	.weak	CAN2_RX1_IRQHandler
	.thumb_set CAN2_RX1_IRQHandler,Default_Handler
	.weak	CAN2_RX0_IRQHandler
	.thumb_set CAN2_RX0_IRQHandler,Default_Handler
	.weak	CAN2_TX_IRQHandler
	.thumb_set CAN2_TX_IRQHandler,Default_Handler
	.weak	ETH_WKUP_IRQHandler
	.thumb_set ETH_WKUP_IRQHandler,Default_Handler
	.weak	ETH_IRQHandler
	.thumb_set ETH_IRQHandler,Default_Handler
	.weak	DMA2_Stream4_IRQHandler
	.thumb_set DMA2_Stream4_IRQHandler,Default_Handler
	.weak	DMA2_Stream3_IRQHandler
	.thumb_set DMA2_Stream3_IRQHandler,Default_Handler
	.weak	DMA2_Stream2_IRQHandler
	.thumb_set DMA2_Stream2_IRQHandler,Default_Handler
	.weak	DMA2_Stream1_IRQHandler
	.thumb_set DMA2_Stream1_IRQHandler,Default_Handler
	.weak	DMA2_Stream0_IRQHandler
	.thumb_set DMA2_Stream0_IRQHandler,Default_Handler
	.weak	TIM7_IRQHandler
	.thumb_set TIM7_IRQHandler,Default_Handler
	.weak	TIM6_DAC_IRQHandler
	.thumb_set TIM6_DAC_IRQHandler,Default_Handler
	.weak	UART5_IRQHandler
	.thumb_set UART5_IRQHandler,Default_Handler
	.weak	UART4_IRQHandler
	.thumb_set UART4_IRQHandler,Default_Handler
	.weak	SPI3_IRQHandler
	.thumb_set SPI3_IRQHandler,Default_Handler
	.weak	TIM5_IRQHandler
	.thumb_set TIM5_IRQHandler,Default_Handler
	.weak	SDIO_IRQHandler
	.thumb_set SDIO_IRQHandler,Default_Handler
	.weak	FSMC_IRQHandler
	.thumb_set FSMC_IRQHandler,Default_Handler
	.weak	DMA1_Stream7_IRQHandler
	.thumb_set DMA1_Stream7_IRQHandler,Default_Handler
	.weak	TIM8_CC_IRQHandler
	.thumb_set TIM8_CC_IRQHandler,Default_Handler
	.weak	TIM8_TRG_COM_TIM14_IRQHandler
	.thumb_set TIM8_TRG_COM_TIM14_IRQHandler,Default_Handler
	.weak	TIM8_UP_TIM13_IRQHandler
	.thumb_set TIM8_UP_TIM13_IRQHandler,Default_Handler
	.weak	TIM8_BRK_TIM12_IRQHandler
	.thumb_set TIM8_BRK_TIM12_IRQHandler,Default_Handler
	.weak	OTG_FS_WKUP_IRQHandler
	.thumb_set OTG_FS_WKUP_IRQHandler,Default_Handler
	.weak	RTC_Alarm_IRQHandler
	.thumb_set RTC_Alarm_IRQHandler,Default_Handler
	.weak	EXTI15_10_IRQHandler
	.thumb_set EXTI15_10_IRQHandler,Default_Handler
	.weak	USART3_IRQHandler
	.thumb_set USART3_IRQHandler,Default_Handler
	.weak	USART2_IRQHandler
	.thumb_set USART2_IRQHandler,Default_Handler
	.weak	USART1_IRQHandler
	.thumb_set USART1_IRQHandler,Default_Handler
	.weak	SPI2_IRQHandler
	.thumb_set SPI2_IRQHandler,Default_Handler
	.weak	SPI1_IRQHandler
	.thumb_set SPI1_IRQHandler,Default_Handler
	.weak	I2C2_ER_IRQHandler
	.thumb_set I2C2_ER_IRQHandler,Default_Handler
	.weak	I2C2_EV_IRQHandler
	.thumb_set I2C2_EV_IRQHandler,Default_Handler
	.weak	I2C1_ER_IRQHandler
	.thumb_set I2C1_ER_IRQHandler,Default_Handler
	.weak	I2C1_EV_IRQHandler
	.thumb_set I2C1_EV_IRQHandler,Default_Handler
	.weak	TIM4_IRQHandler
	.thumb_set TIM4_IRQHandler,Default_Handler
	.weak	TIM3_IRQHandler
	.thumb_set TIM3_IRQHandler,Default_Handler
	.weak	TIM2_IRQHandler
	.thumb_set TIM2_IRQHandler,Default_Handler
	.weak	TIM1_CC_IRQHandler
	.thumb_set TIM1_CC_IRQHandler,Default_Handler
	.weak	TIM1_TRG_COM_TIM11_IRQHandler
	.thumb_set TIM1_TRG_COM_TIM11_IRQHandler,Default_Handler
	.weak	TIM1_UP_TIM10_IRQHandler
	.thumb_set TIM1_UP_TIM10_IRQHandler,Default_Handler
	.weak	TIM1_BRK_TIM9_IRQHandler
	.thumb_set TIM1_BRK_TIM9_IRQHandler,Default_Handler
	.weak	EXTI9_5_IRQHandler
	.thumb_set EXTI9_5_IRQHandler,Default_Handler
	.weak	CAN1_SCE_IRQHandler
	.thumb_set CAN1_SCE_IRQHandler,Default_Handler
	.weak	CAN1_RX1_IRQHandler
	.thumb_set CAN1_RX1_IRQHandler,Default_Handler
	.weak	CAN1_RX0_IRQHandler
	.thumb_set CAN1_RX0_IRQHandler,Default_Handler
	.weak	CAN1_TX_IRQHandler
	.thumb_set CAN1_TX_IRQHandler,Default_Handler
	.weak	ADC_IRQHandler
	.thumb_set ADC_IRQHandler,Default_Handler
	.weak	DMA1_Stream6_IRQHandler
	.thumb_set DMA1_Stream6_IRQHandler,Default_Handler
	.weak	DMA1_Stream5_IRQHandler
	.thumb_set DMA1_Stream5_IRQHandler,Default_Handler
	.weak	DMA1_Stream4_IRQHandler
	.thumb_set DMA1_Stream4_IRQHandler,Default_Handler
	.weak	DMA1_Stream3_IRQHandler
	.thumb_set DMA1_Stream3_IRQHandler,Default_Handler
	.weak	DMA1_Stream2_IRQHandler
	.thumb_set DMA1_Stream2_IRQHandler,Default_Handler
	.weak	DMA1_Stream1_IRQHandler
	.thumb_set DMA1_Stream1_IRQHandler,Default_Handler
	.weak	DMA1_Stream0_IRQHandler
	.thumb_set DMA1_Stream0_IRQHandler,Default_Handler
	.weak	EXTI4_IRQHandler
	.thumb_set EXTI4_IRQHandler,Default_Handler
	.weak	EXTI3_IRQHandler
	.thumb_set EXTI3_IRQHandler,Default_Handler
	.weak	EXTI2_IRQHandler
	.thumb_set EXTI2_IRQHandler,Default_Handler
	.weak	EXTI1_IRQHandler
	.thumb_set EXTI1_IRQHandler,Default_Handler
	.weak	EXTI0_IRQHandler
	.thumb_set EXTI0_IRQHandler,Default_Handler
	.weak	RCC_IRQHandler
	.thumb_set RCC_IRQHandler,Default_Handler
	.weak	FLASH_IRQHandler
	.thumb_set FLASH_IRQHandler,Default_Handler
	.weak	RTC_WKUP_IRQHandler
	.thumb_set RTC_WKUP_IRQHandler,Default_Handler
	.weak	TAMP_STAMP_IRQHandler
	.thumb_set TAMP_STAMP_IRQHandler,Default_Handler
	.weak	PVD_IRQHandler
	.thumb_set PVD_IRQHandler,Default_Handler
	.weak	WWDG_IRQHandler
	.thumb_set WWDG_IRQHandler,Default_Handler
	.weak	SysTick_Handler
	.thumb_set SysTick_Handler,Default_Handler
	.weak	PendSV_Handler
	.thumb_set PendSV_Handler,Default_Handler
	.weak	DebugMonitor_Handler
	.thumb_set DebugMonitor_Handler,Default_Handler
	.weak	SVCall_Handler
	.thumb_set SVCall_Handler,Default_Handler
	.weak	UsageFault_Handler
	.thumb_set UsageFault_Handler,Default_Handler
	.weak	BusFault_Handler
	.thumb_set BusFault_Handler,Default_Handler
	.weak	MemManage_Handler
	.thumb_set MemManage_Handler,Default_Handler
	.weak	HardFault_Handler
	.thumb_set HardFault_Handler,Default_Handler
	.weak	NMI_Handler
	.thumb_set NMI_Handler,Default_Handler
	.align	1
	.global	Reset_Handler
	.syntax unified
	.thumb
	.thumb_func
	.type	Reset_Handler, %function
Reset_Handler:
.LFB1:
	.loc 1 229 1
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	.cfi_offset 14, -4
	sub	sp, sp, #24
	.cfi_def_cfa_offset 32
	add	r7, sp, #0
	.cfi_def_cfa_register 7
	.loc 1 232 21
	ldr	r2, .L9
	.loc 1 232 41
	ldr	r3, .L9+4
	.loc 1 232 14
	subs	r3, r2, r3
	str	r3, [r7, #4]
	.loc 1 234 14
	ldr	r3, .L9+8
	str	r3, [r7, #20]
	.loc 1 235 14
	ldr	r3, .L9+4
	str	r3, [r7, #16]
.LBB2:
	.loc 1 237 18
	movs	r3, #0
	str	r3, [r7, #12]
	.loc 1 237 5
	b	.L4
.L5:
	.loc 1 239 24
	ldr	r2, [r7, #20]
	adds	r3, r2, #1
	str	r3, [r7, #20]
	.loc 1 239 14
	ldr	r3, [r7, #16]
	adds	r1, r3, #1
	str	r1, [r7, #16]
	.loc 1 239 19
	ldrb	r2, [r2]	@ zero_extendqisi2
	.loc 1 239 17
	strb	r2, [r3]
	.loc 1 237 36 discriminator 3
	ldr	r3, [r7, #12]
	adds	r3, r3, #1
	str	r3, [r7, #12]
.L4:
	.loc 1 237 27 discriminator 1
	ldr	r2, [r7, #12]
	ldr	r3, [r7, #4]
	cmp	r2, r3
	bcc	.L5
.LBE2:
	.loc 1 244 12
	ldr	r2, .L9+12
	.loc 1 244 31
	ldr	r3, .L9+16
	.loc 1 244 10
	subs	r3, r2, r3
	str	r3, [r7, #4]
	.loc 1 246 10
	ldr	r3, .L9+16
	str	r3, [r7, #16]
.LBB3:
	.loc 1 248 18
	movs	r3, #0
	str	r3, [r7, #8]
	.loc 1 248 5
	b	.L6
.L7:
	.loc 1 250 14
	ldr	r3, [r7, #16]
	adds	r2, r3, #1
	str	r2, [r7, #16]
	.loc 1 250 17
	movs	r2, #0
	strb	r2, [r3]
	.loc 1 248 36 discriminator 3
	ldr	r3, [r7, #8]
	adds	r3, r3, #1
	str	r3, [r7, #8]
.L6:
	.loc 1 248 27 discriminator 1
	ldr	r2, [r7, #8]
	ldr	r3, [r7, #4]
	cmp	r2, r3
	bcc	.L7
.LBE3:
	.loc 1 255 5
	bl	main
.L8:
	.loc 1 257 10
	nop
	b	.L8
.L10:
	.align	2
.L9:
	.word	_edata
	.word	_sdata
	.word	_etext
	.word	_ebss
	.word	_sbss
	.cfi_endproc
.LFE1:
	.size	Reset_Handler, .-Reset_Handler
.Letext0:
	.file 2 "/usr/lib/gcc/arm-none-eabi/13.2.1/include/stdint.h"
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0x16d
	.2byte	0x5
	.byte	0x1
	.byte	0x4
	.4byte	.Ldebug_abbrev0
	.uleb128 0x7
	.4byte	.LASF20
	.byte	0x1d
	.4byte	.LASF21
	.4byte	.LASF22
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	.Ldebug_line0
	.uleb128 0x1
	.byte	0x1
	.byte	0x6
	.4byte	.LASF0
	.uleb128 0x1
	.byte	0x2
	.byte	0x5
	.4byte	.LASF1
	.uleb128 0x1
	.byte	0x4
	.byte	0x5
	.4byte	.LASF2
	.uleb128 0x1
	.byte	0x8
	.byte	0x5
	.4byte	.LASF3
	.uleb128 0x4
	.4byte	.LASF6
	.byte	0x2e
	.byte	0x18
	.4byte	0x4d
	.uleb128 0x1
	.byte	0x1
	.byte	0x8
	.4byte	.LASF4
	.uleb128 0x1
	.byte	0x2
	.byte	0x7
	.4byte	.LASF5
	.uleb128 0x4
	.4byte	.LASF7
	.byte	0x34
	.byte	0x19
	.4byte	0x6b
	.uleb128 0x5
	.4byte	0x5b
	.uleb128 0x1
	.byte	0x4
	.byte	0x7
	.4byte	.LASF8
	.uleb128 0x1
	.byte	0x8
	.byte	0x7
	.4byte	.LASF9
	.uleb128 0x8
	.byte	0x4
	.byte	0x5
	.ascii	"int\000"
	.uleb128 0x1
	.byte	0x4
	.byte	0x7
	.4byte	.LASF10
	.uleb128 0x2
	.4byte	.LASF11
	.byte	0xb
	.4byte	0x5b
	.uleb128 0x2
	.4byte	.LASF12
	.byte	0xd
	.4byte	0x5b
	.uleb128 0x2
	.4byte	.LASF13
	.byte	0xe
	.4byte	0x5b
	.uleb128 0x2
	.4byte	.LASF14
	.byte	0xf
	.4byte	0x5b
	.uleb128 0x2
	.4byte	.LASF15
	.byte	0x10
	.4byte	0x5b
	.uleb128 0x9
	.4byte	0x66
	.4byte	0xc9
	.uleb128 0xa
	.4byte	0x80
	.byte	0x61
	.byte	0
	.uleb128 0x5
	.4byte	0xb9
	.uleb128 0xb
	.4byte	.LASF16
	.byte	0x1
	.byte	0x75
	.byte	0x10
	.4byte	0xc9
	.uleb128 0x5
	.byte	0x3
	.4byte	interrupt_vector_table
	.uleb128 0xc
	.4byte	.LASF23
	.byte	0x1
	.byte	0x13
	.byte	0xc
	.4byte	0x79
	.uleb128 0xd
	.4byte	.LASF24
	.byte	0x1
	.byte	0xe4
	.byte	0x6
	.4byte	.LFB1
	.4byte	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x158
	.uleb128 0x3
	.4byte	.LASF17
	.byte	0xe8
	.4byte	0x5b
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x3
	.4byte	.LASF18
	.byte	0xea
	.4byte	0x158
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0x3
	.4byte	.LASF19
	.byte	0xeb
	.4byte	0x158
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0xe
	.4byte	.LBB2
	.4byte	.LBE2-.LBB2
	.4byte	0x142
	.uleb128 0x6
	.ascii	"i\000"
	.byte	0xed
	.4byte	0x5b
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.uleb128 0xf
	.4byte	.LBB3
	.4byte	.LBE3-.LBB3
	.uleb128 0x6
	.ascii	"i\000"
	.byte	0xf8
	.4byte	0x5b
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.byte	0
	.uleb128 0x10
	.byte	0x4
	.4byte	0x42
	.uleb128 0x11
	.4byte	.LASF25
	.byte	0x1
	.byte	0xdd
	.byte	0x6
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.byte	0
	.section	.debug_abbrev,"",%progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0x21
	.sleb128 17
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0x21
	.sleb128 14
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 2
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0x21
	.sleb128 18
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7a
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",%progbits
	.4byte	0x1c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x4
	.byte	0
	.2byte	0
	.2byte	0
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	0
	.4byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF21:
	.ascii	"startup.c\000"
.LASF12:
	.ascii	"_sdata\000"
.LASF14:
	.ascii	"_sbss\000"
.LASF15:
	.ascii	"_ebss\000"
.LASF24:
	.ascii	"Reset_Handler\000"
.LASF20:
	.ascii	"GNU C17 13.2.1 20231009 -mcpu=cortex-m4 -mthumb -ml"
	.ascii	"ittle-endian -mfloat-abi=soft -march=armv7e-m -g\000"
.LASF4:
	.ascii	"unsigned char\000"
.LASF13:
	.ascii	"_edata\000"
.LASF22:
	.ascii	"/home/winstonchang/workspace/projects/minimal_syste"
	.ascii	"m\000"
.LASF8:
	.ascii	"long unsigned int\000"
.LASF5:
	.ascii	"short unsigned int\000"
.LASF19:
	.ascii	"pDst\000"
.LASF23:
	.ascii	"main\000"
.LASF10:
	.ascii	"unsigned int\000"
.LASF9:
	.ascii	"long long unsigned int\000"
.LASF6:
	.ascii	"uint8_t\000"
.LASF11:
	.ascii	"_etext\000"
.LASF3:
	.ascii	"long long int\000"
.LASF25:
	.ascii	"Default_Handler\000"
.LASF1:
	.ascii	"short int\000"
.LASF7:
	.ascii	"uint32_t\000"
.LASF2:
	.ascii	"long int\000"
.LASF0:
	.ascii	"signed char\000"
.LASF18:
	.ascii	"pSrc\000"
.LASF17:
	.ascii	"size\000"
.LASF16:
	.ascii	"interrupt_vector_table\000"
	.ident	"GCC: (15:13.2.rel1-2) 13.2.1 20231009"
