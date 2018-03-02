#include "sound.h"
enum Note {C,C_,D,D_,E,F,F_,G,G_,A,A_,B};

void _delay_us_var(const uint16_t duration){
	uint16_t i = 0;
	while(i != duration){
		_delay_us(1);
		i++;
	}
}


/**
 * @brief      Plays a frequency
 *
 * @param[in]  freq      The frequency in hertz From (1000hz to 9999hz)
 * @param[in]  duration  The duration in ms
 */
void frequency(const uint16_t freq, const uint16_t duration){
	uint16_t i = 0;
	uint16_t time = ((freq+5) / 1000) * duration;
	while(i != time){
		PORTC |= (1 << PD2);
		_delay_us(5);
		PORTC  &= ~(1 << PD3);
		_delay_us_var(freq);
		i++;
	}
}

void sound::init(){
	DDRC |= 0x0C;
}

void sound::test(){
	frequency(1046,500);
}