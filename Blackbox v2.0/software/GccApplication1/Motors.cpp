#include <avr/io.h>
#include "Motors.h"

void Motors::pwm_right(int16_t d){
	if(d >= 0){
		/*forward*/
		PORTB &= ~(1<<PB0);
		OCR1A = d;
		}else{
		/*backward*/
		PORTB |= 1<<PB0;
		OCR1A = -d;
	}
}
	
void Motors::pwm_left(int16_t d){
	if(d >= 0){
		/*forward*/
		PORTC &= ~(1<<PC1);
		OCR1B = d;
		}else{
		/*backward*/
		PORTC |= 1<<PC1;
		OCR1B = -d;
	}
}
	
Motors::Motors(){
	/* set phase-correct 10-bit pwm */
	TCCR1B &= ~((1<<WGM12) | (1<<WGM13));
	TCCR1A |= (1<<WGM10) | (1<<WGM11);
		
	OCR1A = 0;
	OCR1B = 0;
		
	/* no prescaling */
	TCCR1B &= ~((1<<CS11) | (1<<CS12));
	TCCR1B |= 1<<CS10;
		
	/* external outputs enabled and inverted */
	TCCR1A &= ~((1<<COM1A0) | (1<<COM1B0));
	TCCR1A |= (1<<COM1A1) | (1<<COM1B1);
		
	/* mark PWM pins as outputs */
	DDRB |= (1<<PB1) | (1<<PB2);
		
	/* mark direction pins as outputs */
	DDRB |= 1<<PB0;
	DDRC |= 1<<PC1;
}
	
void Motors::go_fwd(){
	pwm_left(-512);
	pwm_right(512);
}

void Motors::drive(int16_t stanga, int16_t dreapta){
	pwm_left(stanga);;
	pwm_right(dreapta);
}