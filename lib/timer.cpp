#include "timer.h"
#include "light.h"



void timer::init(){
	
	
	 // set up timer with prescaler = 64 and CTC mode
    TCCR1B |= (1 << WGM12)|(1 << CS12);
  
    // initialize counter
    TCNT1 = 0;
  
    // initialize compare value
    OCR1A = 31249;
  
    // enable compare interrupt
    TIMSK1 |= (1 << OCIE1A);
  
    // enable global interrupts
    sei();
	
}

void timer::init(uint16_t ms){
	
	 // set up timer with prescaler = 64 and CTC mode
    TCCR1B |= (1 << WGM12)|(1 << CS12);
  
    // initialize counter
    TCNT1 = 0;
  
    // initialize compare value
    OCR1A = (ms*31.249);
  
    // enable compare interrupt
    TIMSK1 |= (1 << OCIE1A);
  
    // enable global interrupts
    sei();


}

void timer::on(){
	
	sei();	
	
}
void timer::off(){
	
	cli();	
	
}

void timer::test(){
	
	timer::init();
}

void timer::test(uint16_t ms){
	
	timer::init(ms);
}
