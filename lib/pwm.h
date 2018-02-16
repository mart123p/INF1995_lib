#ifndef PWM_H
#define PWM_H

#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>
/**
 * Set register for pwm
 */
void pwmINIT();

/**
 * Set pwm signal to OCR1A
 * @param signal (0 to 255)
 * @param wheelDirection (1 forward or 0 backward)
 */
void setPwmA(uint8_t signal,bool wheelDirection);

/**
 * Set pwm signal to OCR1B
 * @param signal (0 to 255)
 * @param wheelDirection (1 forward or 0 backward)
 */
void setPwmB(uint8_t signal,bool wheelDirection);

/**
 * Test all the functions in pwm.h
 */
void testPwm();

#endif
