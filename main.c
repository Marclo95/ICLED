 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
*/

/*
© [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include <xc.h>
#include <stdint.h>

#define _XTAL_FREQ 64000000UL  // 64 MHz
#define LED_PIN LATBbits.LATB5
#define LED_TRIS TRISBbits.TRISB5

// Délai pour '1' et '0' en microsecondes, ajustés à 64MHz (approximatif)
void send_bit(uint8_t bit) {
    if (bit) {
        LED_PIN = 1;
        __delay_us(0.7);  // T1H environ 0.7µs
        LED_PIN = 0;
        __delay_us(0.6);  // T1L environ 0.6µs
    } else {
        LED_PIN = 1;
        __delay_us(0.35); // T0H environ 0.35µs
        LED_PIN = 0;
        __delay_us(0.8);  // T0L environ 0.8µs
    }
}

void send_byte(uint8_t byte) {
    for (uint8_t i = 0; i < 8; i++) {
        send_bit(byte & 0x80);
        byte <<= 1;
    }
}

void send_color(uint8_t r, uint8_t g, uint8_t b) {
    send_byte(g);  // WS2812 attend les données en ordre GRB
    send_byte(r);
    send_byte(b);
}

void ws2812_reset() {
    LED_PIN = 0;
    __delay_us(80);  // Reset > 50µs
}

int main(void) {
    LED_TRIS = 0;  // Configure RB5 en sortie
    LED_PIN = 0;

    while(1) {
        send_color(255, 0, 0);  // Rouge plein
        ws2812_reset();
        __delay_ms(1000);

        send_color(0, 255, 0);  // Vert plein
        ws2812_reset();
        __delay_ms(1000);

       send_color(0, 0, 255);  // Bleu plein
        ws2812_reset();
        __delay_ms(1000);
    }

    return 0;
}
