#include <stdint.h>

uint32_t global_variable = 0xFAFAFAFA;
uint32_t uninit_global_variable;

int main(void)
{
    // Find the address of the registers
    volatile uint32_t *pRCC_AHB1ENR  =  (uint32_t*)0x40023830; // RCC_AHB1ENR
    volatile uint32_t *pGPIOD_MODER  =  (uint32_t*)0x40020C00; // GPIOD_MODER of PD13
	volatile uint32_t *pGPIOx_OTYPER =  (uint32_t*)0x40020C04; // GPIOD_OTYPER of PD13
    volatile uint32_t *pGPIOD_BSRR   =  (uint32_t*)0x40020C18; // GPIOD_BSRR of PD13

    // Enable AHB1 bus clock
    *pRCC_AHB1ENR |= (1 << 3);

    // Set the mode of the IO pin as output
    *pGPIOD_MODER &= ~(0x11 << 26);
    *pGPIOD_MODER |= (1 << 26);

	// Set the output type of the IO pin as push-pull
	*pGPIOx_OTYPER &= ~(1 << 13);

    while(1){
        // Set the 13th bit of GPIOD_BSRR
        *pGPIOD_BSRR = (1 << 13);
        for(uint32_t i = 0; i < 1000000; i++);
        *pGPIOD_BSRR = (1 << (13 + 16));
        for(uint32_t i = 0; i < 1000000; i++);
    }
}