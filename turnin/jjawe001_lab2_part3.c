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
    unsigned char tmpC = 0x00;
 
    /* Insert your solution below */
    while (1) {
  	 tmpA = PINA;
	 tmpC = 0x00;

	 // 1 or 2 fasten seatbelt
	 if (tmpA == 0x31 || tmpA == 0x32) {
	 	tmpC = 0xE0;
	 }

	 // 3 or 4 fasten seatbelt
	 else if (tmpA == 0x33 || tmpA == 0x34) {
		tmpC = 0xF0;
	 }

	 // 5 OR 6 fasten seatbelt
	 else if (tmpA == 0x35 || tmpA == 0x36) {
		tmpC = 0xB8;
	 }

	 // 7, 8, 9 fasten seatbelt
	 else if (tmpA == 0x37 || tmpA == 0x38 || tmpA == 0x39) {
		tmpC = 0xBC;
	 }

	 // 10, 11, 12, fasten seatbelt
	 else if (tmpA == 0x3A || tmpA == 0x3B || tmpA == 0x3C) {
		tmpC = 0xBE;
	 }

	 // 13, 14, 15 fasten seatbelt
	 else if (tmpA == 0x3D || tmpA == 0x3E || tmpA == 0x3F) {
	       tmpC = 0xBF;
	 }

	 // Fuel level is 1 or 2, then PC6 and PC5 light
	 else if (tmpA == 0x01 || tmpA == 0x02) {
		tmpC =  0x60;
	 }
	 // Fuel level is 3 or 4, then PC4, PC5, and PC6 light
	 else if (tmpA == 0x03 || tmpA == 0x04) {
		tmpC = 0x70;
	 }
	 // Fuel level is 5 or 6, then PC5, PC4, and PC3 light
	 else if (tmpA == 0x05 || tmpA == 0x06) {
		tmpC = 0x38;
	 }
	 // Fuel level is 7, 8, or 9, then PC5, PC4, PC3, PC2
	 else if (tmpA == 0x07 || tmpA == 0x08 || tmpA == 0x09) {
	        tmpC = 0x3C;
	 }
	 // Fuel level 10, 11, 12  then PC5, PC4, PC3, PC2, PC1 light
	 else if (tmpA == 0x0A || tmpA == 0x0B || tmpA == 0x0C) {
		tmpC = 0x3E;
	 }
	 // Fuel level 13, 14, 15, then PC5, PC4, PC3, PC2, PC1, and PC0 light
	 else if (tmpA == 0x0D || tmpA == 0x0E || tmpA == 0x0F) {
		tmpC = 0x3F;
	 }

	 PORTC = tmpC;
    }
 
    return 1;
}
