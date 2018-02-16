#include "PWM.h"

void pwm_init(){
	TCCR1A |= (1 << COM1A1) | (1 << COM1B1);
	// SET NON-INVERTING MODE
	TCCR1A |= (1 << WGM10);
	TCCR1B |= (1 << CS11);
}

setPwmA(uint8_t signal, bool wheelDirection){
	OCR1A = signal;
	if(wheelDirection)
		PORTD |= 0x80;//set PIND8 to 1
	else
		PORTD &= 0x7F;//set PIND8 to 0
}

setPwmB(uint8_t signal, bool wheelDirection){
	OCR1A = signal;
	if(wheelDirection)
		PORTD |= 0x40;//set PIND7 to 1
	else
		PRTD &= 0xBf;//set PIND7 to 0
}

void testPwm(){
	pwm_init();
	setPwmA(0,1);
	setPwmB(0,1);
	_delay_ms(2000);
	setPwmA(128,1);
	setPwmB(128,1);
	_delay_ms(2000);
	setPwmA(255,0);
	setPwmB(255,0);
	_delay_ms(2000);
}
