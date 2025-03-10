#include "syscfg.h"

/* SYSCFG_Config_EXTI
 * Selects one of the GPIOx to be the input of the EXTI multiplexer.
 *
 * The possible EXTIx multiplexer inputs are PAx, PBx,..., PIx,
 * where x = 0 ~ 15.
 * 
 * EXTICR1 register controls EXTI0 ~ EXTI3, each assigned 4 bits.
 * EXTICR2 register controls EXTI4 ~ EXTI7, each assigned 4 bits.
 * EXTICR3 register controls EXTI8 ~ EXTI11, each assigned 4 bits.
 * EXTICR4 register controls EXTI12 ~ EXTI15, each assigned 4 bits.
 */
void SYSCFG_Config_EXTI(uint8_t exti_line, GPIO_RegDef_t *port)
{
    uint32_t EXTICR_reg_num   = exti_line >> 2;        // Equivalent to  pin / 4
    uint32_t reg_offset      = (exti_line & 0x3) << 2; // Equivalent to (pin % 4) * 4
    SYSCFG->EXTICR[EXTICR_reg_num] |= GPIOx_to_SYSCFG_data(port) << reg_offset;
}

/* GPIOx_to_SYSCFG_data
 * Translation from GPIO port address to SYSCFG_EXTICR 4-bit register data.
 *
 * What the function actually does is extract the 11th~14th bit of GPIOx, since
 * 
 * GPIOA_BASEADDR: 0x40020000 = 0100 0000 0000 0010 0000 0000 0000 0000
 * GPIOB_BASEADDR: 0x40020400 = 0100 0000 0000 0010 0000 0100 0000 0000
 * GPIOC_BASEADDR: 0x40020800 = 0100 0000 0000 0010 0000 1000 0000 0000
 * GPIOD_BASEADDR: 0x40020C00 = 0100 0000 0000 0010 0000 1100 0000 0000
 * GPIOE_BASEADDR: 0x40021000 = 0100 0000 0000 0010 0001 0000 0000 0000
 * .
 * .
 * GPIOI_BASEADDR: 0x40022000 = 0100 0000 0000 0010 0010 0000 0000 0000
 * 
 * After extraction, we have:
 * GPIOA_BASEADDR => 0000
 * GPIOB_BASEADDR => 0001
 * GPIOC_BASEADDR => 0010
 * .
 * .
 * GPIOI_BASEADDR => 1000
 */
uint32_t GPIOx_to_SYSCFG_data(GPIO_RegDef_t *port)
{
    return (((uint32_t) port >> 10) & 0xF);
}
