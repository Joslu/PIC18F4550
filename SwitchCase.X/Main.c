/*
 * File:   Main.c
 * Author: luisc
 *
 * Created on 6 de agosto de 2019, 09:51 PM
 * 
 * Switch statement with PIC18F4550 microcontroller
 * Hardware: MIUVA Intesc
 * 
 * The switch statement is a more elegant method of handling code that 
 * would otherwise require multiple if statements. 
 * The only drawback is that the conditions must all evaluate to 
 * integer types (int or char), whereas if statements may use 
 * any data type in their conditional expressions.
 * 
 * switch (expression)
    {
        case const-expr1: statements1
 *      .
 *      .
 *      .s
        case const-exprn: statementsn
        default: statementsn+1
    }
 * 
 */


#include <xc.h>
#include "Config.h"
#include "pic18f4550.h"

int juego = 0;

void LedAzul();
void LedRojo();
void LedVerde();


void Start(){

  
    
    TRISEbits.RE0 = 0;
    TRISEbits.RE1 = 0;
    TRISEbits.RE2 = 0;
    TRISCbits.RC0 = 1;
  
}

void main(void) {
    Start();
    
    
    while(1){
        
        if (PORTCbits.RC0 == 1){
        __delay_ms(20);
        juego = juego + 1;
        if (juego == 4){
            juego =1;
        }
    }
       
        
        switch(juego){
            case 1:
               
                LedAzul();
              
               
                break;
            case 2:
                
                LedRojo();
               
               
                break;
            case 3:
              
                LedVerde();
        
                break;
            }
    
  
    }
    
    return;
}


void LedAzul(){
    LATEbits.LATE0 = 0;
    LATEbits.LATE1 = 1;
    LATEbits.LATE2 = 1;
}

void LedRojo(){
    LATEbits.LATE0 = 1;
    LATEbits.LATE1 = 0;
    LATEbits.LATE2 = 1;
  
}

void LedVerde(){
    LATEbits.LATE0 = 1;
    LATEbits.LATE1 = 1;
    LATEbits.LATE2 = 0;

}