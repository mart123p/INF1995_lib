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
		
		uart::print("\nTesting PWM\n...",16);
		pwm::test();
		uart::print("\nDone testing PWM\n",18);
		
		//Testing timer with LED
		
		//Testing can
		
		//Waiting for interrupt test
		
		//LED Color
		
		//Memory test
		
				
		while(true);
}
