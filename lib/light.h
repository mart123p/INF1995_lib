/**
 * Ecole Polytechnique de Montreal
 * Departement de genie informatique
 * Cours inf1995
 *
 * Martin Pouliot, Cédric Tessier, Pascal Morel, Sean Costello
 * 2018
 */

#ifndef LIGHT_H
#define LIGHT_H

#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>

namespace light{
	
	/**
	 * Set PortD pin in output mode 
	 */
	void init();
	 
	/**
	 * Set the LED to green
	 */
	void green();
	
	/**
	 * Set the LED to red
	 */
	void red();
	
	/**
	 * Set the LED to amber
	 */
	void amber(uint16_t ms);
	
	/**
	 * Turn off the LED
	 * @param time in ms the LED is amber
	 */
	void off();
	
	/**
	 * Test the LED
	 */
	void test();
}
#endif
