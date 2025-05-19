/*
 * File:   led_driver.c
 * Author: maserne
 *
 * Created on May 13, 2025, 2:09 PM
 */
/*#include <xc.h>
#include "led_driver.h"

#define _XTAL_FREQ 64000000UL

#define LED_PIN LATBbits.LATB5
#define LED_TRIS TRISBbits.TRISB5

uint8_t led_colors[NUM_LEDS * 3];

void send_bit(uint8_t bit) {
    if (bit) {
        // WS2812B '1' : ~0.8 탎 High, ~0.45 탎 Low
        LED_PIN = 1;
        NOP(); NOP(); NOP(); NOP(); 
        LED_PIN = 0;
        NOP();NOP(); // low plus court
    } else {
        // WS2812B '0' : ~0.4 탎 High, ~0.85 탎 Low
        LED_PIN = 1;
        NOP(); NOP(); 
        LED_PIN = 0;
        NOP(); NOP(); NOP(); NOP();
    }
}

void send_byte(uint8_t byte) {
    for (uint8_t i = 0; i < 8; i++) {
        send_bit(byte & 0x80);
        byte <<= 1;
    }
}

void send_color(uint8_t r, uint8_t g, uint8_t b) {
    send_byte(g); // WS2812B uses GRB order
    send_byte(r);
    send_byte(b);
}

void send_all_leds(void) {
    uint8_t gie = INTCON0bits.GIE;
    INTCON0bits.GIE = 0;

    LED_TRIS = 0;
    LED_PIN = 0;

    for (uint8_t i = 0; i < NUM_LEDS; i++) {
        send_color(
            led_colors[i * 3 + 1], // R
            led_colors[i * 3 + 0], // G
            led_colors[i * 3 + 2]  // B
        );
    }

    __delay_us(80); // Reset time
    INTCON0bits.GIE = gie;
}

void set_led_color(uint8_t led_index, uint8_t g, uint8_t r, uint8_t b) {
    if (led_index < NUM_LEDS) {
        led_colors[led_index * 3 + 0] = g;
        led_colors[led_index * 3 + 1] = r;
        led_colors[led_index * 3 + 2] = b;
    }
}
*/