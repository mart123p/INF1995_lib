#ifndef UART_H
#define UART_H

/**
 * Sets all the registers necessary for the UART.
 * @return void
 */
void initUART();

/**
 * Prints to UART an array of character or a string.
 * @param c The array of character or the string
 * @param size The size of the array or string
 * @return void
 */
void printUART(const char* c, const uint8_t size);

/**
 * Prints a uint8_t to UART
 * @param n The byte to print
 * @return void
 */
void printUART(const uint8_t n);

/**
 * Prints a uint16_t to UART
 * @param n The uint16_t to print
 * @return void
 */
void printUART(const uint16_t n);

/**
 * Prints a uint32_t to UART
 * @param n The uint32_t to print
 * @return void
 */
void printUART(const uint32_t n);

/**
 * Prints a char to UART
 * @param n The char to print
 * @return void
 */
void printUART(const char c);

/**
 * Prints a new line to UART
 * @return void
 */
void printlnUART();

#endif
