#ifndef LIGHT_H
#define LIGHT_H

#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>

namespace light{
	
	void init();
	void green();
	void red();
	void amber(uint16_t ms);
	void off();
	void test();
}
#endif
