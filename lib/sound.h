#ifndef SOUND_H
#define SOUND_H

#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>

namespace sound{
	void init();
	void success();
	void fail();
	void beep(uint8_t length);
	void test();

}

#endif