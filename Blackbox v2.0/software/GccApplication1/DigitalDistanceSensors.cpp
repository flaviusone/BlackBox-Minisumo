#include <avr/io.h>
#include "DigitalDistanceSensors.h"

DigitalDistanceSensors::DigitalDistanceSensors(){
	/* set pins as Hi-Z inputs, usually it's already done */
	PORTD &= ~(1<<PD0);
	PORTD &= ~(1<<PD1);
		
	DDRD &= ~(1<<PD0);
	DDRD &= ~(1<<PD1);
}
	
bool DigitalDistanceSensors::read_any(){
	return (PIND & ((1<<PD0) | (1<<PD1))) != 0;
}
	
bool DigitalDistanceSensors::read_left(){
	return (PIND & (1<<PD0)) != 0;
}
	
bool DigitalDistanceSensors::read_right(){
	return (PIND & (1<<PD1)) != 0;
}