/*
* GccApplication1.cpp
*
* Created: 10/4/2013 11:45:50 AM
*  Author: Adrian
*/

#include <avr/io.h>

#define F_CPU 16000000ULL
#include <util/delay.h>

#include "Led.h"
#include "BannerSensors.h"
#include "DigitalDistanceSensors.h"
#include "DigitalLineSensors.h"
#include "Motors.h"

int main(void){
	BannerSensors banner;
	DigitalLineSensors line;
	DigitalDistanceSensors digi;
	Led led;
	Motors m;


		m.go_fwd();
	
}