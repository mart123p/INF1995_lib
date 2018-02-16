#include "uart.h"
#include <avr/pgmspace.h>
const uint8_t asciiNumbers[] PROGMEM = {0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39};


void uartSend(uint8_t data){
        while ( !( UCSR0A & (1<<UDRE0)) );
        UDR0 = data;
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
	while((size * 10) < n){
		size++;
	}
	for(uint8_t i = 0; i < size; i++){
		rem = num %10;
		num = num / 10;
		uartSend(rem);
		uartSend(pgm_read_byte(&asciiNumbers[rem]));
	}
}
void printUART(const uint8_t n){
	uint8_t size = 1;
	unsigned int num = n;
	uint8_t rem;
	while((size * 10) < n){
		size++;
	}
	for(uint8_t i = 0; i < size; i++){
		rem = num %10;
		num = num / 10;
		uartSend(asciiNumbers[rem]);
	}
}

void printUART(const uint16_t n){
	uint8_t size = 1;
	unsigned int num = n;
	uint8_t rem;
	while((size * 10) < n){
		size++;
	}
	for(uint8_t i = 0; i < size; i++){
		rem = num %10;
		num = num / 10;
		uartSend(asciiNumbers[rem]);
	}
}
void printUART(const uint32_t n){
	uint8_t size = 1;
        unsigned long num = n;
        uint8_t rem;
        while((size * 10) < n){
                size++;
        }
        for(uint8_t i = 0; i < size; i++){
                rem = num %10;
                num = num / 10;
                uartSend(asciiNumbers[rem]);
        }
}
void printlnUART(){
	uartSend('\n');
}
void testUART(){

	initUART();
	
	//We check the number ouput
	printUART(-23);
	printlnUART();
	
	printUART(3242);
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
	printUART("this is a test",13);
	printlnUART();
	printUART("Done",4);
}

