/*
 *main.cpp: 
 *
 * OhBoy library test
 *
 *
 */
#include "ohBoy.h"

volatile uint16_t cmp = 0;

ISR(TIMER1_COMPA_vect){
	cmp++;
}

int main()
{
		
		uart::test();
		uart::print("\nTesting light\n...");
		light::test();
		uart::print("\nDone testing light\n");
		
		//Memory test
		uart::print("\nTesting Memory\n...\n");
		mem::test();
		uart::print("\n\nDone testing Memory\n");
									
		uart::print("\nTesting PWM\n...");
		pwm::test();
		uart::print("\nDone testing PWM\n");

		//Testing sound
		uart::print("\nTesting sound\n...");
		sound::test();
		uart::print("\n\nTests were completed!");
	
		//Testing timer 
		uart::print("\n\nTesting the timer\n...");
		timer::test(100);
		uart::print("\n\nDone testing the timer\n");
		
		while(1){
			uart::print(cmp); 
			uart::print(" "); 
			_delay_ms(100);
		}
}
