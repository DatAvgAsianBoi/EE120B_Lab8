/*	Author: huryan18
 *  Partner(s) Name:
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
const unsigned short light_max = 0b0111000000;

void ADC_init(){
      ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00;  PORTA = 0xff;
    DDRB = 0xff;  PORTB = 0x00;
    DDRD = 0xff;  PORTD = 0x00;
    /* Insert your solution below */
    ADC_init();
    unsigned short adc_read = ADC;
    while (1) {
		adc_read = ADC;
            if(adc_read >= light_max/2)
                  PORTB = 0x01;
            else
                  PORTB = 0x00;
    }
    return 1;
}
