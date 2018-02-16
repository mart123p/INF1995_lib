#include "uart.h"
#include <avr/pgmspace.h>
const uint8_t asciiNumbers[] PROGMEM = {0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39};


void uartSend(uint8_t data){
        while ( !( UCSR0A & (1<<UDRE0)) );
        UDR0 = data;
}

long pow(uint8_t base, uint8_t exponent){
	long number = base;
	for(uint8_t i = 1; i < exponent; i++)
		number *= base;
	return number;
}

uint32_t pow_unsigned(uint8_t base, uint8_t exponent){
	uint32_t number = base;
	for(uint8_t i = 1; i < exponent; i++)
		number *= base;
	return number;
}


void initUART(){
	// 2400 bauds. Nous vous donnons la valeur des deux
	// premier registres pour vous éviter des complications

	UBRR0H = 0;
	UBRR0L = 0xCF;

	// permettre la reception et la transmission par le UART0
	UCSR0A=0;
	UCSR0B =(1<<RXEN0)|(1<<TXEN0); 
	// Format des trames: 8 bits, 1 stop bits, none parity
	UCSR0C =(0 << USBS0)|(3 << UCSZ00)|(0 << UPM00)|(0 << UMSEL00);
}

void printUART(const char* c, const uint8_t size){
	for(uint8_t i = 0; i < size; i++){
		uartSend(c[i]);
	}
}

void printUART(const char c){
	uartSend(c);
}
void printUART(const int n){
	uint8_t size = 1;
	int num = n;
	if(n < 0){
		num *= -1;
		uartSend('-');
	}
	uint8_t rem;
	while(pow(10,size) < num){
		size++;
	}
	uint8_t digits[size];
	for(uint8_t i = 0; i < size; i++){
		rem = num % 10;
		num = num / 10;
		digits[i] = pgm_read_byte(&asciiNumbers[rem]);
	}
	for(int i = (size -1); i >= 0; i--){
		uartSend(digits[i]);
	}
}

void printUART(const uint8_t n){
	printUART((int) n);
}

void printUART(const long n){
	uint8_t size = 1;
	long num = n;
	if(n < 0){
		num *= -1;
		uartSend('-');
	}
	uint8_t rem;
	while(pow(10,size) < num){
		size++;
	}
	uint8_t digits[size];
	for(uint8_t i = 0; i < size; i++){
		rem = num % 10;
		num = num / 10;
		digits[i] = pgm_read_byte(&asciiNumbers[rem]);
	}
	for(int i = (size -1); i >= 0; i--){
		uartSend(digits[i]);
	}
}

void printUART(const uint16_t n){
	printUART((long) n);
}
void printUART(const uint32_t n){
	uint8_t size = 1;
	uint32_t num = n;
	if(n < 0){
		num *= -1;
		uartSend('-');
	}
	uint8_t rem;
	while(pow_unsigned(10,size) < num){
		size++;
	}
	uint8_t digits[size];
	for(uint8_t i = 0; i < size; i++){
		rem = num % 10;
		num = num / 10;
		digits[i] = pgm_read_byte(&asciiNumbers[rem]);
	}
	for(int i = (size -1); i >= 0; i--){
		uartSend(digits[i]);
	}
}
void printlnUART(){
	uartSend('\n');
}
void testUART(){

	initUART();
	
	printUART("Testing UART\n",13);
	
	//We check the number ouput
	printUART(0);
	printlnUART();
	
	printUART(-2);
	printlnUART();
	
	printUART(3);
	printlnUART();
	
	printUART(23);
	printlnUART();
	
	printUART(-23);
	printlnUART();
	
	printUART(-4232);
	printlnUART();
	
	printUART(4232);
	printlnUART();
	
	printUART(625532);
	printlnUART();
	
	printUART(-625532);
	printlnUART();
	
	uint8_t x1 = 54;
	printUART(x1);
	printlnUART();

	uint16_t x2 = 5432;
	printUART(x2);
	printlnUART();

	uint32_t x3 = 4677322;
	printUART(x3);
	printlnUART();

	//Testing string output
	printUART("this is a test",14);
	printlnUART();
	printUART("Done testing UART!",18);
	printlnUART();
}

