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
		
		uart::print("\nTesting light\n...");
		sound::test();
		uart::print("\n\nTests were completed!");	
		while(true);
}
