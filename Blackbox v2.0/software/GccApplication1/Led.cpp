#include <avr/io.h>
#include "Led.h"

Led::Led(){
	PORTD |= 1<<PD2;
	DDRD |= 1<<PD2;
}
	
void Led::on(){
	PORTD &= 1<<PD2;
}
	
void Led::off(){
	PORTD |= 1<<PD2;
}
	
void Led::toggle(){
	PORTD ^= 1<<PD2;
}
	
bool Led::get_status(){
	return ! (PORTD & ~(1<<PD2));
}
