/*	Author: lab
 *  Partner(s) Name: Jaired Jawed
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #2
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
 
    /* Insert your solution below */
    while (1) {
  	 tmpA = PINA;

	 // Fuel level 13, 14, or 15
	 if ((tmpA == 0x0D) || (tmpA  == 0x0E) || (tmpA == 0x0F))
    	 {
		PORTC = 0x3F;
	 }
	 // Fuel level 10, 11, or 12
	 else if ((tmpA == 0x0A) || (tmpA == 0x0B) || (tmpA == 0x0C)) {
		PORTC = 0x3E;
	 }
	 // Fuel level 7, 8, or 9
	 else if ((tmpA == 0x07) || (tmpA == 0x08) || (tmpA == 0x09)) {
	        PORTC = 0x3C;
	 }
	 // Fuel level 6 or 7
	 else if ((tmpA == 0x05) || (tmpA == 0x06)) {
	 	PORTC = 0x38;
	 }
	 // Fuel level 3 or 4
	 else if ((tmpA == 0x03) || (tmpA  == 0x04)) {
	 	PORTC = 0x70;
	 }
	 else if ((tmpA == 0x01) || (tmpA == 0x02)) {
		PORTC = 0x60;
	 }
	 
    }
 
    return 1;
}
