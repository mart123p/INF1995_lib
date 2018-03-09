#ifndef TIMER_H
#define TIMER_H

#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>
#include <avr/interrupt.h>

namespace timer{
	
	/**
	 * Turn on the timer and interrupt
	 * @return void
	 */
	void init();
	
	/**
	 * Initialize the timer 
	 * @param ms delay between each incrementation
	 * @return void
	 */
	void init(uint16_t ms);
	
	/**
	 * Turn on the timer and interrupt
	 * @return void
	 */
	void on();
	
	/**
	 * Turn off the timer and interrupt
	 * @return void
	 */
	void off();
	
	/**
	 * Test the timer functions
	 * @return void
	 */
	void test();
		
		
	/**
	 * Test all the timer functions
	 * @param delay of timer incrementing
	 * @return void
	 */	
	void test(uint16_t ms);
}

#endif
