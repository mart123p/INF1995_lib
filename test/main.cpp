/*
 *main.cpp:
 *
 * OhBoy library test
 *
 *
 */
#include "ohBoy.h"

volatile uint16_t cmp = 0;

ISR(TIMER1_COMPA_vect) { cmp++; }

int main() {
  uart::init();
  // Testing sound
  uart::print("\nTesting sound\n...");
  sound::test();
  uart::print("\n\nTests were completed!");
  while(true);
}
