/*	Author: cdes002
 *  Partner(s) Name: myself
 *	Lab Section:022
 *	Assignment: Lab #2  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char tmpA = 0x00;

	unsigned char tmpC = 0x00;

    /* Insert your solution below */
    while (1) {
	tmpA = PINA;
	
	// If only 1 spot is available
	if(tmpA == 0x0E || tmpA == 0x07 || tmpA == 0x0B || tmpA == 0x0D){
	
		tmpC = (tmpC & 0xF0) | 0x01;
	}

	// If 2 spots are available
	 else if(tmpA == 0x03 || tmpA == 0x0C || tmpA == 0x05 || tmpA == 0x06 || tmpA == 0x0A || tmpA == 0x09){

                tmpC  = (tmpC & 0xF0) | 0x02;
        }

	//If 3 spots are available
	 else if(tmpA == 0x01 || tmpA == 0x08 || tmpA == 0x04 || tmpA == 0x02){

                tmpC = (tmpC & 0xF0) | 0x03;
        }

	//If all spots are available
	else if(tmpA == 0x00){
	        tmpC = (tmpC & 0xF0) | 0x04;
	}
	
	// If there are no spots
	else if(tmpA == 0x0F){
                tmpC = (tmpC & 0x70)| 0x80;
        }


	PORTC = tmpC;	

    }
    return 0;
}
