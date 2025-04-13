
#include <stdint.h>
#include "morse.h"
#include "module_conf.h"

extern volatile uint32_t msTicks;
static void delay_ms(uint32_t ms)
{
    msTicks = ms;
    while(msTicks);
}

static void Morse_dot(void)
{
    GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
    delay_ms(100);
    GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
    delay_ms(100);
}

static void Morse_dash(void)
{
    GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
    delay_ms(300);
    GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
    delay_ms(100);
}


static void Morse_A (void) { Morse_dot(); Morse_dash(); }
static void Morse_B (void) { Morse_dash(); Morse_dot(); Morse_dot(); Morse_dot(); }
static void Morse_C (void) { Morse_dash(); Morse_dot(); Morse_dash(); Morse_dot(); }
static void Morse_D (void) { Morse_dash(); Morse_dot(); Morse_dot(); }
static void Morse_E (void) { Morse_dot(); }
static void Morse_F (void) { Morse_dot(); Morse_dot(); Morse_dash(); Morse_dot(); }
static void Morse_G (void) { Morse_dash(); Morse_dash(); Morse_dot(); }
static void Morse_H (void) { Morse_dot(); Morse_dot(); Morse_dot(); Morse_dot(); }
static void Morse_I (void) { Morse_dot(); Morse_dot(); }
static void Morse_J (void) { Morse_dot(); Morse_dash(); Morse_dash(); Morse_dash(); }
static void Morse_K (void) { Morse_dash(); Morse_dot(); Morse_dash(); }
static void Morse_L (void) { Morse_dot(); Morse_dash(); Morse_dot(); Morse_dot(); }
static void Morse_M (void) { Morse_dash(); Morse_dash(); }
static void Morse_N (void) { Morse_dash(); Morse_dot(); }
static void Morse_O (void) { Morse_dash(); Morse_dash(); Morse_dash(); }
static void Morse_P (void) { Morse_dot(); Morse_dash(); Morse_dash(); Morse_dot(); }
static void Morse_Q (void) { Morse_dash(); Morse_dash(); Morse_dot(); Morse_dash(); }
static void Morse_R (void) { Morse_dot(); Morse_dash(); Morse_dot(); }
static void Morse_S (void) { Morse_dot(); Morse_dot(); Morse_dot(); }
static void Morse_T (void) { Morse_dash(); }
static void Morse_U (void) { Morse_dot(); Morse_dot(); Morse_dash(); }
static void Morse_V (void) { Morse_dot(); Morse_dot(); Morse_dot(); Morse_dash(); }
static void Morse_W (void) { Morse_dot(); Morse_dash(); Morse_dash(); }
static void Morse_X (void) { Morse_dash(); Morse_dot(); Morse_dot(); Morse_dash(); }
static void Morse_Y (void) { Morse_dash(); Morse_dot(); Morse_dash(); Morse_dash(); }
static void Morse_Z (void) { Morse_dash(); Morse_dash(); Morse_dot(); Morse_dot(); }
static void Morse_0 (void) { Morse_dash(); Morse_dash(); Morse_dash(); Morse_dash(); Morse_dash(); }
static void Morse_1 (void) { Morse_dot(); Morse_dash(); Morse_dash(); Morse_dash(); Morse_dash(); }
static void Morse_2 (void) { Morse_dot(); Morse_dot(); Morse_dash(); Morse_dash(); Morse_dash(); }
static void Morse_3 (void) { Morse_dot(); Morse_dot(); Morse_dot(); Morse_dash(); Morse_dash(); }
static void Morse_4 (void) { Morse_dot(); Morse_dot(); Morse_dot(); Morse_dot(); Morse_dash(); }
static void Morse_5 (void) { Morse_dot(); Morse_dot(); Morse_dot(); Morse_dot(); Morse_dot(); }
static void Morse_6 (void) { Morse_dash(); Morse_dot(); Morse_dot(); Morse_dot(); Morse_dot(); }
static void Morse_7 (void) { Morse_dash(); Morse_dash(); Morse_dot(); Morse_dot(); Morse_dot(); }
static void Morse_8 (void) { Morse_dash(); Morse_dash(); Morse_dash(); Morse_dot(); Morse_dot(); }
static void Morse_9 (void) { Morse_dash(); Morse_dash(); Morse_dash(); Morse_dash(); Morse_dot(); }


static const void (*MorseCode_Alphabet[36])(void) = {
    Morse_A,
    Morse_B,
    Morse_C,
    Morse_D,
    Morse_E,
    Morse_F,
    Morse_G,
    Morse_H,
    Morse_I,
    Morse_J,
    Morse_K,
    Morse_L,
    Morse_M,
    Morse_N,
    Morse_O,
    Morse_P,
    Morse_Q,
    Morse_R,
    Morse_S,
    Morse_T,
    Morse_U,
    Morse_V,
    Morse_W,
    Morse_X,
    Morse_Y,
    Morse_Z,
    Morse_0, // Index 26
    Morse_1,
    Morse_2,
    Morse_3,
    Morse_4,
    Morse_5,
    Morse_6,
    Morse_7,
    Morse_8,
    Morse_9,
};

void Morse_LED (uint8_t data)
{
    if(data >= 'A' && data <= 'Z')
    {
        MorseCode_Alphabet[data - 'A']();
    }
    else if(data >= 'a' && data <= 'z')
    {
        MorseCode_Alphabet[data - 'a']();
    }
    else if(data >= '0' && data <= '9')
    {
        MorseCode_Alphabet[data - '0' + 26]();
    }
    else
    {
        // Error handling to be implemented
    }
}


