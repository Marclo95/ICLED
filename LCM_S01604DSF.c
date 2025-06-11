/*
 * File:   LCM_S01604DSF.c
 * Author: maserne
 *
 * Created on May 27, 2025, 4:22 PM
 */

#include "LCMS01604DSF.h"
#include <xc.h>
#include "mcc_generated_files/system/system.h"

#define _XTAL_FREQ 64000000UL  // 64 MHz

static void LCD_EnablePulse(void) {
     E_SetHigh();
    __delay_us(1);
    E_SetLow();
    __delay_us(100); // délai après pulse
}

void LCD_Command(uint8_t cmd) {
    RS_SetLow();
    LCD_DATA_LAT = cmd;
    LCD_EnablePulse();
    __delay_ms(2);
}

void LCD_Char(char data) {
    RS_SetHigh();
    LCD_DATA_LAT = data;
    LCD_EnablePulse();
    __delay_ms(1);
}

void LCD_String(const char *str) {
    while (*str) {
        LCD_Char(*str++);
    }
}

void LCD_SetCursor(uint8_t row, uint8_t column) {
    const uint8_t row_offsets[] = {0x00, 0x40, 0x10, 0x50};  // pour écran 16x4
    if (row > 3) row = 3;
    LCD_Command(0x80 | (row_offsets[row] + column));
}

void LCD_Clear(void) {
    LCD_Command(0x01);
    __delay_ms(2);
}

void LCD_Init(void) {
    // Configurer les directions
    RS_SetLow(); /* RS low */
    E_SetLow(); /* EN low */
    __delay_ms(20); // temps d?attente après la mise sous tension

    LCD_Command(0x38); // mode 8 bits, 2 lignes, 5x8 dots
    LCD_Command(0x0C); // affichage ON, curseur OFF
    LCD_Command(0x06); // incrémentation automatique du curseur
    LCD_Clear();
}

//void LCD_createdChar(void) {
//const LCD_droite[] = {
//  B00100,
//  B01110,
//  B10101,
//  B00100,
//  B00100,
//  B00100,
//  B00000,
//  B00000
//};
    
//}