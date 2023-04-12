/*
 * File:   main.c
 * Author: mark harrington
 * PIC12F675 example: blink an LED on pin GP5
 * Created on 12 April 2023, 02:01
 */


 
#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSC oscillator: I/O function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-Up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // GP3/MCLR intrenally tied to VDD
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config CP = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)

#include <xc.h>

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
#define _XTAL_FREQ 4000000

#define LED GPIObits.GP4//
void InitPic (void);

void main(void)
{
    
    /* PICMicro initialization */
    InitPic();
    
    // Here is the 5 second delay before this starts  so at reset we should see
    // led stop flashing with another 5 second delay before starting  but we dont 
    // In fact this  should not work 
    
    
    __delay_ms(5000) ;
    /* Never ending cycle...*/
    while(1)
    {
       /*led  is  defined as above LED GPIObits.GP4  */
        
        LED ^= 1;             /* LED alternate ON and OFF / invert  this  value when looping */
        __delay_ms(500);    /* delay macro (500ms)  simple delay */
    }

}

void InitPic (void)
{
/* I/O port configuration */
    GPIO  =  0x00; // clear port down

#ifdef _PIC12F675_H_
    CMCON =  0x07;      /* Disable comparators Correct */
#endif
    
    
    ANSEL =  0x00;      /* Disable A/D module  Correct */
    TRISIO = 0x00;      /* All output is set as OUTPUT  also Correct */
    WPU = 0;            /* Disable all internal pull-ups  Correct again */
    OPTION_REG = 0x80;  /* Disable internal pull-ups global */
    
    /*Option_REG  is  ad follows GPPU: GPIO Pull-up  
     * Enable bit1 = GPIO pull-ups are disabled 0 
     * = GPIO pull-ups are enabled by individual port latch values */
}

