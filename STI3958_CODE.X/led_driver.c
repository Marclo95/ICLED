/*
 * File:   led_driver.c
 * Author: maserne
 *
 * Created on 23 avril 2025, 16:34
 */
// led_driver.c - Pilotage de LED ICLED depuis un PIC18F26K42

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

// Dépendances du projet (configuré avec MCC)
#include "led_driver.h"
#include "mcc_generated_files/system/system.h"

// NOP pour timing précis
#define NOP() asm("nop")

// Timing pour 64 MHz Fosc => 16 MIPS (62.5 ns par instruction)
#define T1 NOP();NOP();NOP();NOP() // ~250ns
#define DELAY_T0H T1;T1             // ~500ns HIGH pour 0
#define DELAY_T0L T1;T1;T1;T1;T1    // ~750ns LOW pour 0
#define DELAY_T1H T1;T1;T1;T1;T1;T1 // ~750ns HIGH pour 1
#define DELAY_T1L T1;T1             // ~250ns LOW pour 1

static inline void sendBit(uint8_t bit, volatile uint8_t *lat, uint8_t mask)
{
    *lat |= mask; // HIGH
    if (bit)
    {
        DELAY_T1H;
        *lat &= ~mask; // LOW
        DELAY_T1L;
    }
    else
    {
        DELAY_T0H;
        *lat &= ~mask;
        DELAY_T0L;
    }
}

static void sendByte(uint8_t byte, volatile uint8_t *lat, uint8_t mask)
{
    for (int8_t i = 7; i >= 0; i--)
    {
        sendBit((byte >> i) & 0x01, lat, mask);
    }
}

static void sendColor(uint8_t r, uint8_t g, uint8_t b, volatile uint8_t *lat, uint8_t mask)
{
    // Ordre GRB
    sendByte(g, lat, mask);
    sendByte(r, lat, mask);
    sendByte(b, lat, mask);
}

// API utilisateur : fonctions pour chaque broche
void ICLED_SendColor_DIN1(uint8_t r, uint8_t g, uint8_t b)
{
    sendColor(r, g, b, &LATB, 1 << 5); // RB5
}

void ICLED_SendColor_DIN2(uint8_t r, uint8_t g, uint8_t b)
{
    sendColor(r, g, b, &LATB, 1 << 4); // RB4
}

void ICLED_SendColor_DIN3(uint8_t r, uint8_t g, uint8_t b)
{
    sendColor(r, g, b, &LATB, 1 << 3); // RB3
}

// Exemple d'utilisation dans main.c
/*
int main(void)
{
    SYSTEM_Initialize();

    while (1)
    {
        ICLED_SendColor_DIN1(255, 0, 0); // Rouge
        __delay_ms(500);
        ICLED_SendColor_DIN1(0, 255, 0); // Vert
        __delay_ms(500);
        ICLED_SendColor_DIN1(0, 0, 255); // Bleu
        __delay_ms(500);
    }
}
*/
