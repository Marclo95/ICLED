/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.1.1
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

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 aliases
#define LED_DEBUG_TRIS                 TRISAbits.TRISA0
#define LED_DEBUG_LAT                  LATAbits.LATA0
#define LED_DEBUG_PORT                 PORTAbits.RA0
#define LED_DEBUG_WPU                  WPUAbits.WPUA0
#define LED_DEBUG_OD                   ODCONAbits.ODCA0
#define LED_DEBUG_ANS                  ANSELAbits.ANSELA0
#define LED_DEBUG_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define LED_DEBUG_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define LED_DEBUG_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define LED_DEBUG_GetValue()           PORTAbits.RA0
#define LED_DEBUG_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define LED_DEBUG_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define LED_DEBUG_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define LED_DEBUG_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define LED_DEBUG_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define LED_DEBUG_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define LED_DEBUG_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define LED_DEBUG_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set RA1 aliases
#define BP1_TRIS                 TRISAbits.TRISA1
#define BP1_LAT                  LATAbits.LATA1
#define BP1_PORT                 PORTAbits.RA1
#define BP1_WPU                  WPUAbits.WPUA1
#define BP1_OD                   ODCONAbits.ODCA1
#define BP1_ANS                  ANSELAbits.ANSELA1
#define BP1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define BP1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define BP1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define BP1_GetValue()           PORTAbits.RA1
#define BP1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define BP1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define BP1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define BP1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define BP1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define BP1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define BP1_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define BP1_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set RA2 aliases
#define BP2_TRIS                 TRISAbits.TRISA2
#define BP2_LAT                  LATAbits.LATA2
#define BP2_PORT                 PORTAbits.RA2
#define BP2_WPU                  WPUAbits.WPUA2
#define BP2_OD                   ODCONAbits.ODCA2
#define BP2_ANS                  ANSELAbits.ANSELA2
#define BP2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define BP2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define BP2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define BP2_GetValue()           PORTAbits.RA2
#define BP2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define BP2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define BP2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define BP2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define BP2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define BP2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define BP2_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define BP2_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set RA3 aliases
#define BP3_TRIS                 TRISAbits.TRISA3
#define BP3_LAT                  LATAbits.LATA3
#define BP3_PORT                 PORTAbits.RA3
#define BP3_WPU                  WPUAbits.WPUA3
#define BP3_OD                   ODCONAbits.ODCA3
#define BP3_ANS                  ANSELAbits.ANSELA3
#define BP3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define BP3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define BP3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define BP3_GetValue()           PORTAbits.RA3
#define BP3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define BP3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define BP3_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define BP3_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define BP3_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define BP3_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define BP3_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define BP3_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set RA4 aliases
#define V_Iled_TRIS                 TRISAbits.TRISA4
#define V_Iled_LAT                  LATAbits.LATA4
#define V_Iled_PORT                 PORTAbits.RA4
#define V_Iled_WPU                  WPUAbits.WPUA4
#define V_Iled_OD                   ODCONAbits.ODCA4
#define V_Iled_ANS                  ANSELAbits.ANSELA4
#define V_Iled_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define V_Iled_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define V_Iled_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define V_Iled_GetValue()           PORTAbits.RA4
#define V_Iled_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define V_Iled_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define V_Iled_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define V_Iled_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define V_Iled_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define V_Iled_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define V_Iled_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define V_Iled_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set RB0 aliases
#define LCD_E_TRIS                 TRISBbits.TRISB0
#define LCD_E_LAT                  LATBbits.LATB0
#define LCD_E_PORT                 PORTBbits.RB0
#define LCD_E_WPU                  WPUBbits.WPUB0
#define LCD_E_OD                   ODCONBbits.ODCB0
#define LCD_E_ANS                  ANSELBbits.ANSELB0
#define LCD_E_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define LCD_E_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define LCD_E_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define LCD_E_GetValue()           PORTBbits.RB0
#define LCD_E_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define LCD_E_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define LCD_E_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define LCD_E_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define LCD_E_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define LCD_E_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define LCD_E_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define LCD_E_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set RB1 aliases
#define LCD_RS_TRIS                 TRISBbits.TRISB1
#define LCD_RS_LAT                  LATBbits.LATB1
#define LCD_RS_PORT                 PORTBbits.RB1
#define LCD_RS_WPU                  WPUBbits.WPUB1
#define LCD_RS_OD                   ODCONBbits.ODCB1
#define LCD_RS_ANS                  ANSELBbits.ANSELB1
#define LCD_RS_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define LCD_RS_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define LCD_RS_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define LCD_RS_GetValue()           PORTBbits.RB1
#define LCD_RS_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define LCD_RS_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define LCD_RS_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define LCD_RS_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define LCD_RS_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define LCD_RS_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define LCD_RS_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define LCD_RS_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RB3 aliases
#define DIN3_LED_TRIS                 TRISBbits.TRISB3
#define DIN3_LED_LAT                  LATBbits.LATB3
#define DIN3_LED_PORT                 PORTBbits.RB3
#define DIN3_LED_WPU                  WPUBbits.WPUB3
#define DIN3_LED_OD                   ODCONBbits.ODCB3
#define DIN3_LED_ANS                  ANSELBbits.ANSELB3
#define DIN3_LED_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define DIN3_LED_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define DIN3_LED_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define DIN3_LED_GetValue()           PORTBbits.RB3
#define DIN3_LED_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define DIN3_LED_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define DIN3_LED_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define DIN3_LED_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define DIN3_LED_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define DIN3_LED_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define DIN3_LED_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define DIN3_LED_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RB4 aliases
#define DIN2_LED_TRIS                 TRISBbits.TRISB4
#define DIN2_LED_LAT                  LATBbits.LATB4
#define DIN2_LED_PORT                 PORTBbits.RB4
#define DIN2_LED_WPU                  WPUBbits.WPUB4
#define DIN2_LED_OD                   ODCONBbits.ODCB4
#define DIN2_LED_ANS                  ANSELBbits.ANSELB4
#define DIN2_LED_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define DIN2_LED_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define DIN2_LED_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define DIN2_LED_GetValue()           PORTBbits.RB4
#define DIN2_LED_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define DIN2_LED_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define DIN2_LED_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define DIN2_LED_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define DIN2_LED_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define DIN2_LED_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define DIN2_LED_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define DIN2_LED_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RB5 aliases
#define DIN1_LED_TRIS                 TRISBbits.TRISB5
#define DIN1_LED_LAT                  LATBbits.LATB5
#define DIN1_LED_PORT                 PORTBbits.RB5
#define DIN1_LED_WPU                  WPUBbits.WPUB5
#define DIN1_LED_OD                   ODCONBbits.ODCB5
#define DIN1_LED_ANS                  ANSELBbits.ANSELB5
#define DIN1_LED_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define DIN1_LED_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define DIN1_LED_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define DIN1_LED_GetValue()           PORTBbits.RB5
#define DIN1_LED_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define DIN1_LED_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define DIN1_LED_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define DIN1_LED_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define DIN1_LED_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define DIN1_LED_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define DIN1_LED_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define DIN1_LED_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set RC0 aliases
#define LCD_DB0_TRIS                 TRISCbits.TRISC0
#define LCD_DB0_LAT                  LATCbits.LATC0
#define LCD_DB0_PORT                 PORTCbits.RC0
#define LCD_DB0_WPU                  WPUCbits.WPUC0
#define LCD_DB0_OD                   ODCONCbits.ODCC0
#define LCD_DB0_ANS                  ANSELCbits.ANSELC0
#define LCD_DB0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define LCD_DB0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define LCD_DB0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define LCD_DB0_GetValue()           PORTCbits.RC0
#define LCD_DB0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define LCD_DB0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define LCD_DB0_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define LCD_DB0_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define LCD_DB0_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define LCD_DB0_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define LCD_DB0_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define LCD_DB0_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RC1 aliases
#define LCD_DB1_TRIS                 TRISCbits.TRISC1
#define LCD_DB1_LAT                  LATCbits.LATC1
#define LCD_DB1_PORT                 PORTCbits.RC1
#define LCD_DB1_WPU                  WPUCbits.WPUC1
#define LCD_DB1_OD                   ODCONCbits.ODCC1
#define LCD_DB1_ANS                  ANSELCbits.ANSELC1
#define LCD_DB1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define LCD_DB1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define LCD_DB1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define LCD_DB1_GetValue()           PORTCbits.RC1
#define LCD_DB1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define LCD_DB1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define LCD_DB1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define LCD_DB1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define LCD_DB1_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define LCD_DB1_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define LCD_DB1_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define LCD_DB1_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set RC2 aliases
#define LCD_DB2_TRIS                 TRISCbits.TRISC2
#define LCD_DB2_LAT                  LATCbits.LATC2
#define LCD_DB2_PORT                 PORTCbits.RC2
#define LCD_DB2_WPU                  WPUCbits.WPUC2
#define LCD_DB2_OD                   ODCONCbits.ODCC2
#define LCD_DB2_ANS                  ANSELCbits.ANSELC2
#define LCD_DB2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define LCD_DB2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define LCD_DB2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define LCD_DB2_GetValue()           PORTCbits.RC2
#define LCD_DB2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define LCD_DB2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define LCD_DB2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define LCD_DB2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define LCD_DB2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define LCD_DB2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define LCD_DB2_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define LCD_DB2_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC3 aliases
#define LCD_DB3_TRIS                 TRISCbits.TRISC3
#define LCD_DB3_LAT                  LATCbits.LATC3
#define LCD_DB3_PORT                 PORTCbits.RC3
#define LCD_DB3_WPU                  WPUCbits.WPUC3
#define LCD_DB3_OD                   ODCONCbits.ODCC3
#define LCD_DB3_ANS                  ANSELCbits.ANSELC3
#define LCD_DB3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define LCD_DB3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define LCD_DB3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define LCD_DB3_GetValue()           PORTCbits.RC3
#define LCD_DB3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define LCD_DB3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define LCD_DB3_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define LCD_DB3_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define LCD_DB3_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define LCD_DB3_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define LCD_DB3_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define LCD_DB3_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 aliases
#define LCD_DB4_TRIS                 TRISCbits.TRISC4
#define LCD_DB4_LAT                  LATCbits.LATC4
#define LCD_DB4_PORT                 PORTCbits.RC4
#define LCD_DB4_WPU                  WPUCbits.WPUC4
#define LCD_DB4_OD                   ODCONCbits.ODCC4
#define LCD_DB4_ANS                  ANSELCbits.ANSELC4
#define LCD_DB4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define LCD_DB4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define LCD_DB4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define LCD_DB4_GetValue()           PORTCbits.RC4
#define LCD_DB4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define LCD_DB4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define LCD_DB4_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define LCD_DB4_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define LCD_DB4_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define LCD_DB4_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define LCD_DB4_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define LCD_DB4_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC5 aliases
#define LCD_DB5_TRIS                 TRISCbits.TRISC5
#define LCD_DB5_LAT                  LATCbits.LATC5
#define LCD_DB5_PORT                 PORTCbits.RC5
#define LCD_DB5_WPU                  WPUCbits.WPUC5
#define LCD_DB5_OD                   ODCONCbits.ODCC5
#define LCD_DB5_ANS                  ANSELCbits.ANSELC5
#define LCD_DB5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define LCD_DB5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define LCD_DB5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define LCD_DB5_GetValue()           PORTCbits.RC5
#define LCD_DB5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define LCD_DB5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define LCD_DB5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define LCD_DB5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define LCD_DB5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define LCD_DB5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define LCD_DB5_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define LCD_DB5_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 aliases
#define LCD_DB6_TRIS                 TRISCbits.TRISC6
#define LCD_DB6_LAT                  LATCbits.LATC6
#define LCD_DB6_PORT                 PORTCbits.RC6
#define LCD_DB6_WPU                  WPUCbits.WPUC6
#define LCD_DB6_OD                   ODCONCbits.ODCC6
#define LCD_DB6_ANS                  ANSELCbits.ANSELC6
#define LCD_DB6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define LCD_DB6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define LCD_DB6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define LCD_DB6_GetValue()           PORTCbits.RC6
#define LCD_DB6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define LCD_DB6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define LCD_DB6_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define LCD_DB6_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define LCD_DB6_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define LCD_DB6_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define LCD_DB6_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define LCD_DB6_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 aliases
#define LCD_DB7_TRIS                 TRISCbits.TRISC7
#define LCD_DB7_LAT                  LATCbits.LATC7
#define LCD_DB7_PORT                 PORTCbits.RC7
#define LCD_DB7_WPU                  WPUCbits.WPUC7
#define LCD_DB7_OD                   ODCONCbits.ODCC7
#define LCD_DB7_ANS                  ANSELCbits.ANSELC7
#define LCD_DB7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define LCD_DB7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define LCD_DB7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define LCD_DB7_GetValue()           PORTCbits.RC7
#define LCD_DB7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define LCD_DB7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define LCD_DB7_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define LCD_DB7_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define LCD_DB7_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define LCD_DB7_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define LCD_DB7_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define LCD_DB7_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/