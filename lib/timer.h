#ifndef TIMER_H
#define TIMER_H

namespace timer{
	
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
	 * Test all the timer functions
	 * @return void
	 */
	void test();
		
	
}

#endif
