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
			
		//Testing timer with LED
		
		//Testing can
		
		//Waiting for interrupt test
		
		//Testing sound
		
		uart::print("\nTesting PWM\n...");
		pwm::test();
		uart::print("\nDone testing PWM\n");
	
				
	
		
		uart::print("\n\nTests were completed!");	
		while(true);
}
