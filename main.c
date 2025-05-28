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

// ===============================================
//              Bibliothèques et définitions
// ===============================================
#include <xc.h>
#include <stdint.h>
#include "mcc_generated_files/system/system.h"
#include "LCMS01604DSF.h"
#include "main.h"
#include "led_driver.h"

// Définition des constantes pour la LED et la matrice
#define LED_PIN LATBbits.LATB5
#define LED_TRIS TRISBbits.TRISB5
#define NUM_LEDS 144
#define COLORS 3
#define LIGNE 12   // LIGNE for matrix
#define COLUMN 12 // COLUMN for matrix 

#define NB_COLORS (sizeof(COLORS_TAB)/sizeof(COLORS_TAB[0]))

// ===============================================
//                  Structure GRB
// ===============================================

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
}GRB ;
// --- Définitions des états du menu ---
typedef enum {
    MENU_PRINCIPAL,
    MENU_ICLED,
    MENU_COURANT,
    ICLED_COULEUR1,
    ICLED_COULEUR2,
    ICLED_COULEUR3,
    MESURE_COURANT
} EtatMenu;

EtatMenu etat_courant = MENU_PRINCIPAL;

// ===============================================
//             Fonction de l'afficheur
// ===============================================

void LCD_UpdateMenu(void) {
    LCD_Init();
    LCD_Clear();
    switch (etat_courant) {
        case MENU_PRINCIPAL:
            LCD_SetCursor(0,0); LCD_String("Choix:");
            LCD_SetCursor(1,0); LCD_String("1.ICLED 2.Mesure");
            break;

        case MENU_ICLED:
            LCD_SetCursor(0,0); LCD_String("LED:");
            LCD_SetCursor(1,0); LCD_String("1.R 2.G 3.B");
            break;

        case MENU_COURANT:
            LCD_SetCursor(0,0); LCD_String("Mesure courant");
            break;

        case ICLED_COULEUR1:
            LCD_SetCursor(0,0); LCD_String("Couleur: ROUGE");
            break;

        case ICLED_COULEUR2:
            LCD_SetCursor(0,0); LCD_String("Couleur: VERT");
            break;

        case ICLED_COULEUR3:
            LCD_SetCursor(0,0); LCD_String("Couleur: BLEU");
            break;

        case MESURE_COURANT:
            LCD_SetCursor(0,0); LCD_String("Courant:");
            // ajouter fonction d'affichage du courant ici
            break;
    }
}
// Matrice principale des LEDs
GRB matrix_tab [LIGNE][COLUMN];  // matrix to use for each module 

// Flag utilisé dans certaines animations
bool flag_start = false ;

// Tableau de couleurs prédéfinies
const GRB COLORS_TAB[] = {
    {.red = 100, .green = 0, .blue = 0},   // Rouge
    {.red = 0, .green = 100, .blue = 0},   // Vert
    {.red = 0, .green = 0, .blue = 100}    // Bleu
};

// ===============================================
//                Fonctions LED de base
// ===============================================

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

void on_leds(uint8_t r, uint8_t g, uint8_t b){
    uint8_t i = 0;
     uint8_t j = 0;
    for(i = 0 ; i< LIGNE ; i++ ){
        for(j= 0 ; j< COLUMN ; j++ ){  
            matrix_tab[i][j].red = r;
            matrix_tab[i][j].green = g;
            matrix_tab[i][j].blue = b;
        }
    }
     send_leds();
}


void send_leds (void){
    uint8_t i = 0;
     uint8_t j = 0;
     
    for(i = 0 ; i< LIGNE ; i++ ){
        for(j= 0 ; j< COLUMN ; j++ ){
            send_color(matrix_tab[i][j].red,matrix_tab[i][j].green, matrix_tab[i][j].blue);
        }       
    }
     ws2812_reset();
}

// ===============================================
//         Fonctions bas niveau pour LEDs WS2812
// ===============================================
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

// ===============================================
//             Gestion des interruptions BP
// ===============================================

void int_BP1(void) {
    __delay_ms(40); // antirebond

    switch (etat_courant) {
        case MENU_PRINCIPAL:
            etat_courant = MENU_ICLED;
            break;
        case MENU_ICLED:
            etat_courant = MENU_PRINCIPAL;
            break;
        case MENU_COURANT:
            etat_courant = MENU_PRINCIPAL;
            break;
        default:
            etat_courant = MENU_PRINCIPAL;
            break;
    }
    LCD_UpdateMenu();
}
                                                                                                                                                                                                                                                                                                                   
void int_BP2(void) {
    __delay_ms(40);

    if (etat_courant == MENU_ICLED) {
        etat_courant = ICLED_COULEUR1;
    } else if (etat_courant == ICLED_COULEUR1) {
        etat_courant = ICLED_COULEUR2;
    } else if (etat_courant == ICLED_COULEUR2) {
        etat_courant = ICLED_COULEUR3;
    } else if (etat_courant == ICLED_COULEUR3) {
        etat_courant = ICLED_COULEUR1;
    } else if (etat_courant == MENU_PRINCIPAL) {
        etat_courant = MENU_COURANT;
    }

    LCD_UpdateMenu();
}
void int_BP3(void) {
    __delay_ms(40);
    appliquer_action();
    LCD_UpdateMenu();
}

// --- Action du bouton 3 selon le contexte ---
void appliquer_action(void) {
    switch (etat_courant) {
        case ICLED_COULEUR1:
            // Allume LED en rouge
            on_leds(100, 0, 0);
            break;
        case ICLED_COULEUR2:
            // Allume LED en vert
            on_leds(0, 100, 0);
            break;
        case ICLED_COULEUR3:
            // Allume LED en bleu
            on_leds(0, 0, 100);
            break;
        case MENU_COURANT:
        case MESURE_COURANT:
            // afficher valeur de courant
            etat_courant = MESURE_COURANT;
            break;
        default:
            break;
    }
}

// ===============================================
//         Gestion du timer via interruption
// ===============================================
void TMR1_handler( void){
     
    
    static uint16_t timer_1s = 0;
    
    if( timer_1s ++ > 20){
        timer_1s = 0;
        flag_start = !flag_start;
    }
     
}

// ===============================================
//                    Fonction main
// ===============================================
int main(void) {
    
    SYSTEM_Initialize();
    
    TMR1_OverflowCallbackRegister(TMR1_handler);
    
   BP1_SetInterruptHandler(int_BP1);
   BP2_SetInterruptHandler(int_BP2);
   BP3_SetInterruptHandler(int_BP3); 
    
    INTERRUPT_GlobalInterruptEnable();
    LED_TRIS = 0;  // Configure RB5 en sortie
    LED_PIN = 0;

   
    /*LCD_String("Antoine");
    LCD_SetCursor(1, 0);
    LCD_String("L'empereur dieu");*/

    //uint8_t position = 0;
    uint8_t frame = 0;
    
        // Affichage initial
    LCD_UpdateMenu();
    
    while(1) {
        
    /*LCD_Init();
    LCD_SetCursor(0, 0);
    if (PORTAbits.RA1 == 0) {
        LCD_Clear();
        LCD_String("ETEINT");
        __delay_ms(50);
    } else if (PORTAbits.RA1 == 1){
        LCD_Clear();
        LCD_String("VERT");}
        // Lecture du bouton
       /* if (PORTAbits.RA1 == 1) {
            send_color(0, 100, 0);
            ws2812_reset();
        } else {
            send_color(0, 0, 0);
            ws2812_reset();
    }*/
        
        // - Sapin de Noël
       /* uint8_t index = 0;

        for (uint8_t i = 0; i < LIGNE; i++) {
            for (uint8_t j = 0; j < COLUMN; j++) {
                uint8_t color_index = (index + frame) % NB_COLORS;
                matrix_tab[i][j] = COLORS_TAB[color_index];
                index++;
            }
        }
        INTERRUPT_GlobalInterruptDisable();
        send_leds();
        INTERRUPT_GlobalInterruptEnable();
        
         frame++;
        __delay_ms(50);*/
        
        // - Clignotement
       /*// Éteindre toutes les LEDs
        off_leds();
        // toute les led clignote sans utiliser de delais
        if( flag_start == true){
            on_leds();
        }else{
            off_leds();
        }
        INTERRUPT_GlobalInterruptDisable();
        send_leds();
        INTERRUPT_GlobalInterruptEnable();*/
        
        // - Chenillard
       /* for (uint8_t i = 0; i < NUM_LEDS; i++) {
            if (i == position) {
                send_color(0, 100, 0);  // Rouge
                //send_color(0, 0, 255);  // Rouge
            } else {
                send_color(0, 0, 0);    // Éteint
            }
        }
        ws2812_reset();
        __delay_ms(50);  // Vitesse du chenillard
        position++;
        if (position >= NUM_LEDS) {
            position = 0;
        }*/
        
        // - Envoi de couleurs fixes
       /*send_color(255, 0, 0);  // LED 0 : Rouge
        send_color(0, 0, 255);  // LED 1 : Bleu
        send_color(0, 255, 0);  // LED 2 : Vert
        ws2812_reset();
        __delay_ms(500);*/
        
        // Juste envoyer une couleur
        //send_color(0, 0, 255);  // LED 1 : Bleu
    }

    return 0;
}
