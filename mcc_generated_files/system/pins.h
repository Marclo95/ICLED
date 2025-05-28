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
#define RA1_SetInterruptHandler  BP1_SetInterruptHandler

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
#define RA2_SetInterruptHandler  BP2_SetInterruptHandler

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
#define RA3_SetInterruptHandler  BP3_SetInterruptHandler

// get/set RB0 aliases
#define E_TRIS                 TRISBbits.TRISB0
#define E_LAT                  LATBbits.LATB0
#define E_PORT                 PORTBbits.RB0
#define E_WPU                  WPUBbits.WPUB0
#define E_OD                   ODCONBbits.ODCB0
#define E_ANS                  ANSELBbits.ANSELB0
#define E_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define E_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define E_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define E_GetValue()           PORTBbits.RB0
#define E_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define E_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define E_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define E_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define E_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define E_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define E_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define E_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set RB1 aliases
#define RS_TRIS                 TRISBbits.TRISB1
#define RS_LAT                  LATBbits.LATB1
#define RS_PORT                 PORTBbits.RB1
#define RS_WPU                  WPUBbits.WPUB1
#define RS_OD                   ODCONBbits.ODCB1
#define RS_ANS                  ANSELBbits.ANSELB1
#define RS_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RS_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RS_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RS_GetValue()           PORTBbits.RB1
#define RS_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RS_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RS_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define RS_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define RS_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define RS_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define RS_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define RS_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RB5 aliases
#define IO_RB5_TRIS                 TRISBbits.TRISB5
#define IO_RB5_LAT                  LATBbits.LATB5
#define IO_RB5_PORT                 PORTBbits.RB5
#define IO_RB5_WPU                  WPUBbits.WPUB5
#define IO_RB5_OD                   ODCONBbits.ODCB5
#define IO_RB5_ANS                  ANSELBbits.ANSELB5
#define IO_RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define IO_RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define IO_RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define IO_RB5_GetValue()           PORTBbits.RB5
#define IO_RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define IO_RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define IO_RB5_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define IO_RB5_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define IO_RB5_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define IO_RB5_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define IO_RB5_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define IO_RB5_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set RC0 aliases
#define DB0_TRIS                 TRISCbits.TRISC0
#define DB0_LAT                  LATCbits.LATC0
#define DB0_PORT                 PORTCbits.RC0
#define DB0_WPU                  WPUCbits.WPUC0
#define DB0_OD                   ODCONCbits.ODCC0
#define DB0_ANS                  ANSELCbits.ANSELC0
#define DB0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define DB0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define DB0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define DB0_GetValue()           PORTCbits.RC0
#define DB0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define DB0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define DB0_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define DB0_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define DB0_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define DB0_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define DB0_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define DB0_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RC1 aliases
#define DB1_TRIS                 TRISCbits.TRISC1
#define DB1_LAT                  LATCbits.LATC1
#define DB1_PORT                 PORTCbits.RC1
#define DB1_WPU                  WPUCbits.WPUC1
#define DB1_OD                   ODCONCbits.ODCC1
#define DB1_ANS                  ANSELCbits.ANSELC1
#define DB1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define DB1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define DB1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define DB1_GetValue()           PORTCbits.RC1
#define DB1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define DB1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define DB1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define DB1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define DB1_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define DB1_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define DB1_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define DB1_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set RC2 aliases
#define DB2_TRIS                 TRISCbits.TRISC2
#define DB2_LAT                  LATCbits.LATC2
#define DB2_PORT                 PORTCbits.RC2
#define DB2_WPU                  WPUCbits.WPUC2
#define DB2_OD                   ODCONCbits.ODCC2
#define DB2_ANS                  ANSELCbits.ANSELC2
#define DB2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define DB2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define DB2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define DB2_GetValue()           PORTCbits.RC2
#define DB2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define DB2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define DB2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define DB2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define DB2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define DB2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define DB2_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define DB2_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC3 aliases
#define DB3_TRIS                 TRISCbits.TRISC3
#define DB3_LAT                  LATCbits.LATC3
#define DB3_PORT                 PORTCbits.RC3
#define DB3_WPU                  WPUCbits.WPUC3
#define DB3_OD                   ODCONCbits.ODCC3
#define DB3_ANS                  ANSELCbits.ANSELC3
#define DB3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define DB3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define DB3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define DB3_GetValue()           PORTCbits.RC3
#define DB3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define DB3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define DB3_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define DB3_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define DB3_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define DB3_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define DB3_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define DB3_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 aliases
#define DB4_TRIS                 TRISCbits.TRISC4
#define DB4_LAT                  LATCbits.LATC4
#define DB4_PORT                 PORTCbits.RC4
#define DB4_WPU                  WPUCbits.WPUC4
#define DB4_OD                   ODCONCbits.ODCC4
#define DB4_ANS                  ANSELCbits.ANSELC4
#define DB4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define DB4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define DB4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define DB4_GetValue()           PORTCbits.RC4
#define DB4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define DB4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define DB4_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define DB4_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define DB4_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define DB4_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define DB4_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define DB4_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC5 aliases
#define DB5_TRIS                 TRISCbits.TRISC5
#define DB5_LAT                  LATCbits.LATC5
#define DB5_PORT                 PORTCbits.RC5
#define DB5_WPU                  WPUCbits.WPUC5
#define DB5_OD                   ODCONCbits.ODCC5
#define DB5_ANS                  ANSELCbits.ANSELC5
#define DB5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define DB5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define DB5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define DB5_GetValue()           PORTCbits.RC5
#define DB5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define DB5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define DB5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define DB5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define DB5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define DB5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define DB5_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define DB5_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 aliases
#define DB6_TRIS                 TRISCbits.TRISC6
#define DB6_LAT                  LATCbits.LATC6
#define DB6_PORT                 PORTCbits.RC6
#define DB6_WPU                  WPUCbits.WPUC6
#define DB6_OD                   ODCONCbits.ODCC6
#define DB6_ANS                  ANSELCbits.ANSELC6
#define DB6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define DB6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define DB6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define DB6_GetValue()           PORTCbits.RC6
#define DB6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define DB6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define DB6_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define DB6_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define DB6_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define DB6_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define DB6_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define DB6_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 aliases
#define DB7_TRIS                 TRISCbits.TRISC7
#define DB7_LAT                  LATCbits.LATC7
#define DB7_PORT                 PORTCbits.RC7
#define DB7_WPU                  WPUCbits.WPUC7
#define DB7_OD                   ODCONCbits.ODCC7
#define DB7_ANS                  ANSELCbits.ANSELC7
#define DB7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define DB7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define DB7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define DB7_GetValue()           PORTCbits.RC7
#define DB7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define DB7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define DB7_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define DB7_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define DB7_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define DB7_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define DB7_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define DB7_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

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

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handler for the BP1 pin functionality
 * @param none
 * @return none
 */
void BP1_ISR(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for BP1 pin interrupt-on-change functionality.
 *        Allows selecting an interrupt handler for BP1 at application runtime
 * @pre Pins intializer called
 * @param InterruptHandler function pointer.
 * @return none
 */
void BP1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup  pinsdriver
 * @brief Dynamic Interrupt Handler for BP1 pin.
 *        This is a dynamic interrupt handler to be used together with the BP1_SetInterruptHandler() method.
 *        This handler is called every time the BP1 ISR is executed and allows any function to be registered at runtime.
 * @pre Pins intializer called
 * @param none
 * @return none
 */
extern void (*BP1_InterruptHandler)(void);

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for BP1 pin. 
 *        This is a predefined interrupt handler to be used together with the BP1_SetInterruptHandler() method.
 *        This handler is called every time the BP1 ISR is executed. 
 * @pre Pins intializer called
 * @param none
 * @return none
 */
void BP1_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handler for the BP2 pin functionality
 * @param none
 * @return none
 */
void BP2_ISR(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for BP2 pin interrupt-on-change functionality.
 *        Allows selecting an interrupt handler for BP2 at application runtime
 * @pre Pins intializer called
 * @param InterruptHandler function pointer.
 * @return none
 */
void BP2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup  pinsdriver
 * @brief Dynamic Interrupt Handler for BP2 pin.
 *        This is a dynamic interrupt handler to be used together with the BP2_SetInterruptHandler() method.
 *        This handler is called every time the BP2 ISR is executed and allows any function to be registered at runtime.
 * @pre Pins intializer called
 * @param none
 * @return none
 */
extern void (*BP2_InterruptHandler)(void);

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for BP2 pin. 
 *        This is a predefined interrupt handler to be used together with the BP2_SetInterruptHandler() method.
 *        This handler is called every time the BP2 ISR is executed. 
 * @pre Pins intializer called
 * @param none
 * @return none
 */
void BP2_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handler for the BP3 pin functionality
 * @param none
 * @return none
 */
void BP3_ISR(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for BP3 pin interrupt-on-change functionality.
 *        Allows selecting an interrupt handler for BP3 at application runtime
 * @pre Pins intializer called
 * @param InterruptHandler function pointer.
 * @return none
 */
void BP3_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup  pinsdriver
 * @brief Dynamic Interrupt Handler for BP3 pin.
 *        This is a dynamic interrupt handler to be used together with the BP3_SetInterruptHandler() method.
 *        This handler is called every time the BP3 ISR is executed and allows any function to be registered at runtime.
 * @pre Pins intializer called
 * @param none
 * @return none
 */
extern void (*BP3_InterruptHandler)(void);

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for BP3 pin. 
 *        This is a predefined interrupt handler to be used together with the BP3_SetInterruptHandler() method.
 *        This handler is called every time the BP3 ISR is executed. 
 * @pre Pins intializer called
 * @param none
 * @return none
 */
void BP3_DefaultInterruptHandler(void);


#endif // PINS_H
/**
 End of File
*/