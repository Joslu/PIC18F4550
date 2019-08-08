/*
 * File:   HolaMundo.c
 * Author: Luis Cruz @joslu
 * 
 * Hardware: Tarjeta de desarrollo MIUVA Intesc
  
 * El microcontrolador PIC18F4550 cuenta con 40 pines los cuales están divididos 
 * en 5 puertos, 35 de ellos son puertos de entrada - salida (I/O), 
 * los cuales pueden ser configurados como entradas o salidas de 
 * propósito general,configurando los registros asociados a ellos.
 * 
 * Cada puerto del microcontrolador esta asociado con registros de 8 bits 
 * para operaciones IO.
	1. TRISx
	2. LATx
	3. PORTx

   A continuación se explicará cómo configurar,
   escribir o leer un Pin de cada PUERTO. 
	- TRISX: Escribiendo en cada bit (?1? lógico = Entrada y ?0? lógico = Salida).
	- LATX: Escribiendo en cada bit la salida tendrá un nivel 
      de Voltaje (1 lógico = 5v | 0 lógico = 0v).
	- PORTX: Este registro es de solo Lectura (5v =1 lógico | 0v =0 lógico).

 */


#include <xc.h> //Libreria del compilador
#include "Config.h"
#include "pic18f4550.h"



void InitPort(){ 
    ADCON1= 0x0F;
    LATE = 0; 
    TRISEbits.RE2 = 0; //PortE = salida 0, 1 entrada
    
}

void main(void) {
    InitPort();
    while(1){
        LATEbits.LATE2 = 1; 
        __delay_ms(1000);
        LATEbits.LATE2 = 0;
        __delay_ms(1000);
      
    }
    return;
}



