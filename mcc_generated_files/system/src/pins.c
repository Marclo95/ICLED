/**
 * Generated Driver File
 * 
 * @file pins.c
 * 
 * @ingroup  pinsdriver
 * 
 * @brief This is generated driver implementation for pins. 
 *        This file provides implementations for pin APIs for all pins selected in the GUI.
 *
 * @version Driver Version 3.1.1
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

#include "../pins.h"

void (*BP1_InterruptHandler)(void);
void (*BP2_InterruptHandler)(void);
void (*BP3_InterruptHandler)(void);

void PIN_MANAGER_Initialize(void)
{
   /**
    LATx registers
    */
    LATA = 0x0;
    LATB = 0x0;
    LATC = 0x0;
    /**
    ODx registers
    */
    ODCONA = 0x0;
    ODCONB = 0x0;
    ODCONC = 0x0;

    /**
    TRISx registers
    */
    TRISA = 0xFE;
    TRISB = 0xDC;
    TRISC = 0x0;

    /**
    ANSELx registers
    */
    ANSELA = 0xF0;
    ANSELB = 0xDC;
    ANSELC = 0x0;

    /**
    WPUx registers
    */
    WPUA = 0x0;
    WPUB = 0x0;
    WPUC = 0x0;
    WPUE = 0x0;


    /**
    SLRCONx registers
    */
    SLRCONA = 0xFF;
    SLRCONB = 0xFF;
    SLRCONC = 0xFF;

    /**
    INLVLx registers
    */
    INLVLA = 0xFF;
    INLVLB = 0xFF;
    INLVLC = 0xFF;
    INLVLE = 0x8;

   /**
    RxyI2C | RxyFEAT registers   
    */
    RB1I2C = 0x0;
    RB2I2C = 0x0;
    RC3I2C = 0x0;
    RC4I2C = 0x0;
    /**
    PPS registers
    */

   /**
    IOCx registers 
    */
    IOCAP = 0xE;
    IOCAN = 0x0;
    IOCAF = 0x0;
    IOCBP = 0x0;
    IOCBN = 0x0;
    IOCBF = 0x0;
    IOCCP = 0x0;
    IOCCN = 0x0;
    IOCCF = 0x0;
    IOCEP = 0x0;
    IOCEN = 0x0;
    IOCEF = 0x0;

    BP1_SetInterruptHandler(BP1_DefaultInterruptHandler);
    BP2_SetInterruptHandler(BP2_DefaultInterruptHandler);
    BP3_SetInterruptHandler(BP3_DefaultInterruptHandler);

    // Enable PIE0bits.IOCIE interrupt 
    PIE0bits.IOCIE = 1; 
}
  
void PIN_MANAGER_IOC(void)
{
    // interrupt on change for pin BP1
    if(IOCAFbits.IOCAF1 == 1)
    {
        BP1_ISR();  
    }
    // interrupt on change for pin BP2
    if(IOCAFbits.IOCAF2 == 1)
    {
        BP2_ISR();  
    }
    // interrupt on change for pin BP3
    if(IOCAFbits.IOCAF3 == 1)
    {
        BP3_ISR();  
    }
}
   
/**
   BP1 Interrupt Service Routine
*/
void BP1_ISR(void) {

    // Add custom BP1 code

    // Call the interrupt handler for the callback registered at runtime
    if(BP1_InterruptHandler)
    {
        BP1_InterruptHandler();
    }
    IOCAFbits.IOCAF1 = 0;
}

/**
  Allows selecting an interrupt handler for BP1 at application runtime
*/
void BP1_SetInterruptHandler(void (* InterruptHandler)(void)){
    BP1_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for BP1
*/
void BP1_DefaultInterruptHandler(void){
    // add your BP1 interrupt custom code
    // or set custom function using BP1_SetInterruptHandler()
}
   
/**
   BP2 Interrupt Service Routine
*/
void BP2_ISR(void) {

    // Add custom BP2 code

    // Call the interrupt handler for the callback registered at runtime
    if(BP2_InterruptHandler)
    {
        BP2_InterruptHandler();
    }
    IOCAFbits.IOCAF2 = 0;
}

/**
  Allows selecting an interrupt handler for BP2 at application runtime
*/
void BP2_SetInterruptHandler(void (* InterruptHandler)(void)){
    BP2_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for BP2
*/
void BP2_DefaultInterruptHandler(void){
    // add your BP2 interrupt custom code
    // or set custom function using BP2_SetInterruptHandler()
}
   
/**
   BP3 Interrupt Service Routine
*/
void BP3_ISR(void) {

    // Add custom BP3 code

    // Call the interrupt handler for the callback registered at runtime
    if(BP3_InterruptHandler)
    {
        BP3_InterruptHandler();
    }
    IOCAFbits.IOCAF3 = 0;
}

/**
  Allows selecting an interrupt handler for BP3 at application runtime
*/
void BP3_SetInterruptHandler(void (* InterruptHandler)(void)){
    BP3_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for BP3
*/
void BP3_DefaultInterruptHandler(void){
    // add your BP3 interrupt custom code
    // or set custom function using BP3_SetInterruptHandler()
}
/**
 End of File
*/