/*
 *main.cpp: 
 *
 * OhBoy library test
 *
 *
 */
#include "ohBoy.h"
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
			
		//Testing timesr with LED
		uart::print("\n\nTesting the timer\n");
		//timer::test();
		uart::print("\n\nDone testing the timer\n");
								
		uart::print("\nTesting PWM\n...");
		pwm::test();
		uart::print("\nDone testing PWM\n");

		//Testing sound
		uart::print("\nTesting sound\n...");
		sound::test();
		uart::print("\n\nTests were completed!");	
		while(true);
}
