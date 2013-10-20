#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include "defines.h"
#include "utils.h"

#define F_CPU 16000000
#include <util/delay.h>



#define MOTOR_0_DIRECTION_PIN	0
#define MOTOR_0_DIRECTION_NPIN	1
#define MOTOR_0_DIRECTION_PORT	PORTA

#define MOTOR_1_DIRECTION_PIN	2
#define MOTOR_1_DIRECTION_NPIN	3
#define MOTOR_1_DIRECTION_PORT	PORTA

#define MOTOR_2_DIRECTION_PIN	4
#define MOTOR_2_DIRECTION_NPIN	5
#define MOTOR_2_DIRECTION_PORT	PORTA

#define MOTOR_3_DIRECTION_PIN	6
#define MOTOR_3_DIRECTION_NPIN	7
#define MOTOR_3_DIRECTION_PORT	PORTA


void motor_speed_0(int16_t speed){
	// MOTOR_0_DIRECTION_PIN set => forward
	// MOTOR_0_DIRECTION_PIN cleared => backward
	if(speed < 0){
		MOTOR_0_DIRECTION_PORT |= (1 << MOTOR_0_DIRECTION_PIN);
		MOTOR_0_DIRECTION_PORT &= ~(1 << MOTOR_0_DIRECTION_NPIN);
		speed = -speed;
	} else {
		MOTOR_0_DIRECTION_PORT &= ~(1 << MOTOR_0_DIRECTION_PIN);
		MOTOR_0_DIRECTION_PORT |= (1 << MOTOR_0_DIRECTION_NPIN);
	}

	// truncated to 8 bits
	speed = MIN(speed, 255);
	set_pwm_0(speed);
}


void motor_speed_1(int16_t speed){
	if(speed < 0){
		MOTOR_1_DIRECTION_PORT |= (1 << MOTOR_1_DIRECTION_PIN);
		MOTOR_1_DIRECTION_PORT &= ~(1 << MOTOR_1_DIRECTION_NPIN);
		speed = -speed;
	} else {
		MOTOR_1_DIRECTION_PORT &= ~(1 << MOTOR_1_DIRECTION_PIN);
		MOTOR_1_DIRECTION_PORT |= (1 << MOTOR_1_DIRECTION_NPIN);
	}

	// truncated to 8 bits
	speed = MIN(speed, 255);
	set_pwm_1A(speed);
}


void motor_speed_2(int16_t speed){
	if(speed < 0){
		MOTOR_2_DIRECTION_PORT |= (1 << MOTOR_2_DIRECTION_PIN);
		MOTOR_2_DIRECTION_PORT &= ~(1 << MOTOR_2_DIRECTION_NPIN);
		speed = -speed;
	} else {
		MOTOR_2_DIRECTION_PORT &= ~(1 << MOTOR_2_DIRECTION_PIN);
		MOTOR_2_DIRECTION_PORT |= (1 << MOTOR_2_DIRECTION_NPIN);
	}

	// truncated to 8 bits
	speed = MIN(speed, 255);
	set_pwm_1B(speed);
}


void motor_speed_3(int16_t speed){
	if(speed < 0){
		MOTOR_3_DIRECTION_PORT |= (1 << MOTOR_3_DIRECTION_PIN);
		MOTOR_3_DIRECTION_PORT &= ~(1 << MOTOR_3_DIRECTION_NPIN);
		speed = -speed;
	} else {
		MOTOR_3_DIRECTION_PORT &= ~(1 << MOTOR_3_DIRECTION_PIN);
		MOTOR_3_DIRECTION_PORT |= (1 << MOTOR_3_DIRECTION_NPIN);
	}

	// truncated to 8 bits
	speed = MIN(speed, 255);
	set_pwm_2(speed);
}



int main(){
	
	DDRA = 0xFF;

	while(1){
		motor_speed_0(255);
		motor_speed_1(255);
		motor_speed_2(255);
		motor_speed_3(255);
		
		_delay_ms(1000);

		motor_speed_0(-255);
		motor_speed_1(-255);
		motor_speed_2(-255);
		motor_speed_3(-255);
		
		_delay_ms(1000);
		
	}


	setup_interrupt_0(INT_TRIGGER_RISING);
	setup_interrupt_1(INT_TRIGGER_RISING);
	return 0;
}

ISR(INT0_vect){
	motor_speed_0(255);
	motor_speed_1(255);
}

ISR(INT1_vect){
	motor_speed_0(-255);
	motor_speed_1(-255);
}