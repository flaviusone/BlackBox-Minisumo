#include <avr/io.h>
#include "DigitalLineSensors.h"

DigitalLineSensors::DigitalLineSensors(){
	/* set pins as Hi-Z inputs, usually it's already done */
	PORTC &= ~(1<<PC2);
	PORTC &= ~(1<<PC3);
		
	DDRC &= ~(1<<PC2);
	DDRC &= ~(1<<PC3);
}
	
bool DigitalLineSensors::read_any(){
	return (PINC & ((1<<PC2) | (1<<PC3))) != 0;
}
	
bool DigitalLineSensors::read_left(){
	return (PINC & (1<<PC2)) != 0;
}
	
bool DigitalLineSensors::read_right(){
	return (PINC & (1<<PC3)) != 0;
}