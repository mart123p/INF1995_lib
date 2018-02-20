#include "light.h"
#include "uart.h"
void light::init()
{
	DDRB |= 0x0c;
}

void light::green()
{
	PORTB |= (1 << PD2) ;
	PORTB  &= ~(1 << PD3);
}

void light::red()
{
	PORTB |= (1 << PD3);
	PORTB &= ~(1 << PD2);
	
}

void light::ambre(uint8_t sec);

void light::test()
{
	uart::print("test led");
	light::init();
	light::green();
	_delay_ms(5000);
	light::red();
	_delay_ms(5000);
	uart::print("test led fini");
}
