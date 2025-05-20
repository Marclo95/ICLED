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
#include "mcc_generated_files/system/system.h"
#include "main.h"

#define _XTAL_FREQ 64000000UL  // 64 MHz
#define LED_PIN LATBbits.LATB5
#define LED_TRIS TRISBbits.TRISB5
#define NUM_LEDS 144
#define COLORS 3
#define LIGNE 12   // LIGNE for matrix
#define COLUMN 12 // COLUMN for matrix 


typedef struct GRB {
      union{ 
        struct {
           uint8_t green ; 
           uint8_t red;
           uint8_t blue;
           
        };
        uint8_t colors[COLORS];
        uint24_t color;
    };
}GRB;

GRB matrix_tab [LIGNE][COLUMN];  // matrix to use for each module 

bool flag_start = false ;



void off_leds(void){
    uint8_t i = 0;
     uint8_t j = 0;
    
    for(i = 0 ; i< LIGNE ; i++ ){
        for(j= 0 ; j< COLUMN ; j++ ){  
            matrix_tab[i][j].red = 0;
            matrix_tab[i][j].green = 0;
            matrix_tab[i][j].blue = 0;
        }
    }
     
}

void on_leds(void){
    uint8_t i = 0;
     uint8_t j = 0;
    
    for(i = 0 ; i< LIGNE ; i++ ){
        for(j= 0 ; j< COLUMN ; j++ ){  
            matrix_tab[i][j].red = 60;
            matrix_tab[i][j].green = 20;
            matrix_tab[i][j].blue = 0;
        }
    }
     
}


void send_leds ( void){
    uint8_t i = 0;
     uint8_t j = 0;
     
    for(i = 0 ; i< LIGNE ; i++ ){
        for(j= 0 ; j< COLUMN ; j++ ){
            send_color(matrix_tab[i][j].red,matrix_tab[i][j].green, matrix_tab[i][j].blue);
        }       
    }
     ws2812_reset();
}

void TMR1_handler( void){
     
    
    static uint16_t timer_1s = 0;
    
    if( timer_1s ++ > 20){
        timer_1s = 0;
        flag_start = !flag_start;
    }
     
}


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
    
    SYSTEM_Initialize();
    
    TMR1_OverflowCallbackRegister(TMR1_handler);
    
    INTERRUPT_GlobalInterruptEnable();
    LED_TRIS = 0;  // Configure RB5 en sortie
    LED_PIN = 0;

    uint8_t position = 0;
    
    while(1) {
        
        if( flag_start == true){
            on_leds();
        }else{
            off_leds();
        }
        INTERRUPT_GlobalInterruptDisable();
        send_leds();
        INTERRUPT_GlobalInterruptEnable();
        
        
        //__delay_ms(500);
        /*for (uint8_t i = 0; i < NUM_LEDS; i++) {
            if (i == position) {
                send_color(0, 0, 0);  // Rouge
                //send_color(0, 0, 255);  // Rouge
            } else {
                send_color(0, 50, 0);    // Éteint
                send_color(0, 0, 50);
            }
        }

        ws2812_reset();
        __delay_ms(50);  // Vitesse du chenillard

        position++;
        if (position >= NUM_LEDS) {
            position = 0;
        }*/
       //send_color(255, 0, 0);  // LED 0 : Rouge
       /*  send_color(0, 0, 255);  // LED 1 : Bleu
        send_color(0, 255, 0);  // LED 2 : Vert
        __delay_ms(500);
        send_color(0, 255, 0);  // LED 1 : Vert
        send_color(0, 0, 255);  // LED 2 : Bleu
        send_color(0, 0, 255);  // LED 0 : Bleu
        send_color(255, 0, 0);  // LED 1 : Rouge
        send_color(0, 255, 0);  // LED 2 : Vert
        send_color(0, 255, 0);  // LED 0 : vert
        send_color(0, 0, 255);  // LED 1 : Bleu
        send_color(255, 0, 0);  // LED 2 : rouge
        ws2812_reset();
        __delay_ms(500);

        send_color(0, 0, 255);  // LED 0 : Bleu
        send_color(255, 0, 0);  // LED 1 : Rouge
        send_color(0, 255, 0);  // LED 2 : Vert
        send_color(0, 255, 0);  // LED 0 : vert
        send_color(0, 0, 255);  // LED 1 : Bleu
        send_color(255, 0, 0);  // LED 2 : rouge
        send_color(255, 0, 0);  // LED 0 : Rouge
        send_color(0, 255, 0);  // LED 1 : Vert
        send_color(0, 0, 255);  // LED 2 : Bleu
        ws2812_reset();
        __delay_ms(500);

        send_color(0, 255, 0);  // LED 0 : vert
        send_color(0, 0, 255);  // LED 1 : Bleu
        send_color(255, 0, 0);  // LED 2 : rouge
        send_color(255, 0, 0);  // LED 0 : Rouge
        send_color(0, 255, 0);  // LED 1 : Vert
        send_color(0, 0, 255);  // LED 2 : Bleu
        send_color(0, 0, 255);  // LED 0 : Bleu
        send_color(255, 0, 0);  // LED 1 : Rouge
        send_color(0, 255, 0);  // LED 2 : Vert
        ws2812_reset();
        __delay_ms(500);*/
    }

    return 0;
}
