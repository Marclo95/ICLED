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

// Définition des constantes liées aux LEDs
#define LED_PIN LATBbits.LATB5     // Broche de commande LED WS2812
#define LED_TRIS TRISBbits.TRISB5  // Direction de la broche LED
#define LED_Debug LATAbits.LATA0
#define LED_Debug_PIN TRISAbits.TRISA0
#define ADC_H


#define NUM_LEDS 144
#define COLORS 3
#define LIGNE 12   // Nombre de lignes de la matrice LED
#define COLUMN 12 // Nombre de colonnes de la matrice LED
#define NB_COLORS (sizeof(COLORS_TAB)/sizeof(COLORS_TAB[0]))

// --- ADC related definitions ---
#define VREF 5.f   // Tension de référence ADC
#define ADC_MAX 4095.0f 
// ===============================================
//                  Structure GRB
// ===============================================

typedef struct GRB {
      union{ 
        struct {
           uint8_t green ;  // Composante verte de la LED
           uint8_t red;     // Composante rouge
           uint8_t blue;    // Composante bleue
           
        };
        uint8_t colors[COLORS]; // Accès direct par tableau : colors[0]=G, [1]=R, [2]=B
        uint24_t color;         // Accès en bloc de 24 bits (utile pour transferts rapides)
    };
}GRB ;
// --- Définitions des états du menu ---
typedef enum {
    MENU_PRINCIPAL,
    MENU_ICLED,
    MENU_INTENSITER,
    MENU_COURANT,
    MENU_ANIMATION,
    ICLED_COULEUR1,
    ICLED_COULEUR2,
    ICLED_COULEUR3,
    ICLED_COULEUR4,
    ICLED_COULEUR5,
    ICLED_COULEUR6,
    ICLED_COULEUR7,
    ICLED_COULEUR8,
    Eteindre,
    MESURE_COURANT
} EtatMenu;

EtatMenu etat_courant = MENU_PRINCIPAL;


// ===============================================
//             Fonction de l'afficheur
// ===============================================

void LCD_UpdateMenu(void) {
    
    char buffer[16];
    
    LCD_Init();
    switch (etat_courant) {
        case MENU_PRINCIPAL:
            LCD_SetCursor(0,6); LCD_String("Menu");           // Titre
            LCD_SetCursor(1,0); LCD_String("1.ICLED 2.MESURE"); // Choix disponibles
            LCD_SetCursor(2,0); LCD_String("3.INTEN 4.ANIMA");
            LCD_SetCursor(2,15); LCD_Char(0b11011111);
            break;

        case MENU_ICLED:
            LCD_SetCursor(0,0); LCD_String("LED:");         // Sous-menu LED
            LCD_SetCursor(1,0); LCD_String("1.R 2.G 3.B 4.O");  // Choix couleurs
            break;

        case MENU_COURANT:                                      // Sous-menu Mesure courant
            LCD_SetCursor(0,0); LCD_String("Mesure courant");
            break;
            
        case ICLED_COULEUR1:
            LCD_SetCursor(0,0); LCD_String("Couleur: ROUGE");
            LCD_SetCursor(1,15); LCD_Char(0b01111110);
            break;

        case ICLED_COULEUR2:
            LCD_SetCursor(0,0); LCD_String("Couleur: VERT");
            LCD_SetCursor(1,15); LCD_Char(0b01111110);
            break;

        case ICLED_COULEUR3:
            LCD_SetCursor(0,0); LCD_String("Couleur: BLEU");
            LCD_SetCursor(1,15); LCD_Char(0b01111110);
            break;
            
        case ICLED_COULEUR4:
            LCD_SetCursor(0,0); LCD_String("Couleur: ORANGE");
            LCD_SetCursor(1,15); LCD_Char(0b01111110);
            break;
            
        case ICLED_COULEUR5:
            LCD_SetCursor(0,0); LCD_String("Couleur: JAUNE");
            LCD_SetCursor(1,15); LCD_Char(0b01111110);
            break;
            
        case ICLED_COULEUR6:
            LCD_SetCursor(0,0); LCD_String("Couleur: VIOLET");
            LCD_SetCursor(1,15); LCD_Char(0b01111110);
            break;
        
        case ICLED_COULEUR7:
            LCD_SetCursor(0,0); LCD_String("Couleur: ROSE");
            LCD_SetCursor(1,15); LCD_Char(0b01111110);
            break;
            
        case ICLED_COULEUR8:
            LCD_SetCursor(0,0); LCD_String("Couleur: BLANC");
            LCD_SetCursor(1,15); LCD_Char(0b01111110);
            break;
            
        case MENU_ANIMATION:
            // Ton code ici
            break;

         case Eteindre:
            LCD_SetCursor(0,0); LCD_String("ETEINDRE");
            LCD_SetCursor(1,15); LCD_Char(0b01111111);
            break;

        case MESURE_COURANT:
            LCD_SetCursor(0,0); 
            LCD_String("V_Iled:");
            LCD_SetCursor(1, 0);
            float tension = lire_tension();
            sprintf(buffer, "%.2f V", tension); 
            LCD_String(buffer);
            LCD_SetCursor(2,0); 
            LCD_String("Courent leds:");
            LCD_SetCursor(3,0); 
            int courant = lire_tension() ;
            sprintf(buffer, "%.3e A", courant);
            LCD_String(buffer);
  
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
    {.red = 0, .green = 0, .blue = 100},    // Bleu
    {.red = 100, .green = 50, .blue = 0},   //Orange
    {.red = 100, .green = 100, .blue = 0},  // Jaune
    {.red = 50, .green = 0, .blue = 100},   // Violet
    {.red = 100, .green = 0, .blue = 50},    // Rose
    {.red = 100, .green = 100, .blue = 100}    // Blanc
};


// ===============================================
//                Fonctions LED de base
// ===============================================

// Éteint toutes les LEDs
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
     send_leds(); // Met à jour physiquement les LEDs
}

// Allume toutes les LEDs avec une couleur donnée
void on_leds(uint8_t r, uint8_t g, uint8_t b){
    uint8_t i = 0;
     uint8_t j = 0;
    for(i = 0 ; i< LIGNE ; i++ ){
        for(j= 0 ; j< COLUMN ; j++ ){  
            matrix_tab[i][j].red = r;   // Appliquer la couleur rouge
            matrix_tab[i][j].green = g; // Appliquer la couleur vert
            matrix_tab[i][j].blue = b;  // Appliquer la couleur bleu
        }
    }
     send_leds();   // Met à jour physiquement les LEDs
}

// Envoie les données de la matrice aux LEDs WS2812
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
//                Fonctions arc en ciel
// =============================================

void rainbow_scroll_vertical(void) {
    static uint8_t offset = 0;

    for (uint8_t i = 0; i < LIGNE; i++) {
        uint8_t color_index = (i + offset) % NB_COLORS;
        for (uint8_t j = 0; j < COLUMN; j++) {
            matrix_tab[i][j] = COLORS_TAB[color_index];
        }
    }

    send_leds();
    offset = (offset + 1) % NB_COLORS;
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


// Envoie une couleur individuelle à la LED (ordre GRB)
void send_color(uint8_t r, uint8_t g, uint8_t b) {
    send_byte(g); 
    send_byte(r);
    send_byte(b);
}

void ws2812_reset() {
    LED_PIN = 0;
    __delay_us(80);  // Reset > 50µs
}

// ===============================================
//         Fonctions lecture du courant
// ===============================================
float lire_tension(void)
{
    ADC_ChannelSelect(ADC_CHANNEL_ANA4);
    ADC_ConversionStart();
    adc_result_t adc_val = ADC_ConversionResultGet(); // Lire la valeur brute
    
   float tension = (adc_val * VREF) / ADC_MAX;
    return tension;
}

float lire_courant(void)
{
    int courant = lire_tension() ; // amplification de la mesure de courant 1V/A
    return courant;
}
// ===============================================
//             Gestion des interruptions BP
// ===============================================

void int_BP1(void) {
    __delay_ms(40); // Anti-rebond

    switch (etat_courant) {
        case MENU_PRINCIPAL:
            etat_courant = MENU_ICLED; // Entrée dans le menu ICLED
            break;

        case Eteindre:
            etat_courant = MENU_PRINCIPAL;
            break;

        default:
            etat_courant = MENU_PRINCIPAL;
            break;
    }

    LCD_UpdateMenu(); // Mise à jour de l'affichage
}
                                                                                                                                                                                                                                                                                                                   
void int_BP2(void) {
    __delay_ms(40); // Anti-rebond

     if (etat_courant == MENU_ICLED) {
        etat_courant = ICLED_COULEUR1; // Rouge
    } else if (etat_courant == ICLED_COULEUR1) {
        etat_courant = ICLED_COULEUR2; // Vert
    } else if (etat_courant == ICLED_COULEUR2) {
        etat_courant = ICLED_COULEUR3; // Bleu
    } else if (etat_courant == ICLED_COULEUR3) {
        etat_courant = ICLED_COULEUR4; // Orange
    } else if (etat_courant == ICLED_COULEUR4) {
        etat_courant = ICLED_COULEUR5; // Jaune
    } else if (etat_courant == ICLED_COULEUR5) {
        etat_courant = ICLED_COULEUR6; // Violet
    } else if (etat_courant == ICLED_COULEUR6) {
        etat_courant = ICLED_COULEUR7; // Rose
    } else if (etat_courant == ICLED_COULEUR7) {
        etat_courant = ICLED_COULEUR8; // Blanc
    } else if (etat_courant == ICLED_COULEUR8) {
        etat_courant = Eteindre; // Eteindre 
    } else if (etat_courant == Eteindre) {
        etat_courant = MENU_PRINCIPAL; // Retour menu principal (ou boucle)
    } else if (etat_courant == MENU_PRINCIPAL) {
        etat_courant = MENU_COURANT; // Accès au menu de mesure de courant
    }

    LCD_UpdateMenu();
}

void int_BP3(void) {
    __delay_ms(40);
    appliquer_action();
    LCD_UpdateMenu();
}

// ===============================================
//             Action en fonction du menu
// ===============================================
void appliquer_action(void) {
    if (etat_courant >= ICLED_COULEUR1 && etat_courant <= ICLED_COULEUR8) {
        GRB color = COLORS_TAB[etat_courant - ICLED_COULEUR1];
        on_leds(color.red, color.green, color.blue);
    } else if (etat_courant == Eteindre) {
        off_leds();
    } else if (etat_courant == MENU_COURANT) {
        etat_courant = MESURE_COURANT;
    }
}

// ===============================================
//         Gestion du timer via interruption
// ===============================================

void TMR1_handler( void){
     
    static uint16_t timer_1s = 0;
    
    if( timer_1s ++ > 10){  // Si 20 interruptions ? 1 seconde écoulée
        timer_1s = 0;
        LED_DEBUG_Toggle();
    }
}

// ===============================================
//                    Fonction main
// ===============================================
int main(void) {
    
    SYSTEM_Initialize(); // Initialisation de tous les périphériques MCC
    ADC_Initialize(); // Initialisation de l'ADC
    TMR1_OverflowCallbackRegister(TMR1_handler); // Enregistre l'interruption du timer
    
   BP1_SetInterruptHandler(int_BP1);    // ISR bouton 2
   BP2_SetInterruptHandler(int_BP2);    // ISR bouton 2
   BP3_SetInterruptHandler(int_BP3);    // ISR bouton 2
    
    INTERRUPT_GlobalInterruptEnable();  // Active les interruptions globales
    LED_TRIS = 0;  // Configure RB5 en sortie
    LED_PIN = 0;
    LED_Debug_PIN = 0;  // RA5 en sortie
    LED_Debug = 0;   // Initialiser à 0
    
    
    
        // Affichage initial
    LCD_UpdateMenu();   // Affiche le menu principal au démarrage
    
        //uint8_t position = 0;
    uint8_t frame = 0;
     
    while(1) {
        
    }

    return 0;
}
