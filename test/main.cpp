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
		uart::init();

		uart::print("\nTesting sound\n...");
		sound::test();
		uart::print("\n\nTests were completed!");	
		while(true);
}
