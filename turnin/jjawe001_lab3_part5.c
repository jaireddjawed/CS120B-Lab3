/*	Author: lab
 *  Partner(s) Name: Jaired Jawed
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #5
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


    DDRD = 0x00; PORTD = 0xFF;
    DDRB = 0x01; PORTB = 0x00;

    unsigned char tmpB = 0x00;
    unsigned char tmpD = 0x00;
    unsigned short total = 0x00;
    unsigned char endB = 0x00;

    /* Insert your solution below */
    while (1) {
    	tmpB = PINB;
	tmpD = PIND;

	// combine the D weight and B weight
	total = (tmpD << 1) | (tmpB & 0x01);

	// >= 70 pounds
	if (total >= 0x46) {
		endB = 0x02; // 0000 0010
	}
	// >5 and < 70
	else if (total > 0x05 && total < 0x46) {
		endB = 0x04;
	}
	// <= 5
	else if (total <= 0x05) {
	       endB = 0x00;
	}	       

	PORTB = endB;
    }
 
    return 1;
}
