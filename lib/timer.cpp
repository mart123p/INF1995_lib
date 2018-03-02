#include "timer.h"
#include "light.h"

timer::init(uint16_t ms){
	
	//set prescaler to 64 in CTC mode
	TCCR1B |= (1 << WGM12)|(1 << CS12);
	
	// initialiser le compteur
    TCNT1 = 0;
	
	OCR1A = ms*31;
	
  	// activate the timer
    TIMSK1 |= (1 << OCIE1A);

 	// activate the interrupts
    sei();

}



timer::on(){
	
	sei();	
	
}
timer::off(){
	
	cli();	
	
}

timer::test(){
	
	ISR (TIMER1_COMPA_vect){
	light::green();
	_delay_(5000);
	light::red();
	TCNT1 = 0;
}
	timer::init(5000);
	
}
