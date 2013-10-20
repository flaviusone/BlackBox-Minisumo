#include <avr/io.h>
#include "BannerSensors.h"

BannerSensors::BannerSensors(){
	/* set pins as Hi-Z inputs, usually it's already done */
	PORTC &= ~(1<<PC4);
	PORTC &= ~(1<<PC5);
		
	DDRC &= ~(1<<PC4);
	DDRC &= ~(1<<PC5);
}
	
bool BannerSensors::read_any(){
	return (PINC & ((1<<PC4) | (1<<PC5))) != 0;
}
	
bool BannerSensors::read_left(){
	return (PINC & (1<<PC4)) != 0;
}
	
bool BannerSensors::read_right(){
	return (PINC & (1<<PC5)) != 0;
}
