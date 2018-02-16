#include "uart.h"
#include <avr/pgmspace.h>
char asciiNumbers[] PROGMEM = {'0','1','2','3','4','5','6','7','8','9'};


void uartSend(uint8_t data){
        while ( !( UCSR0A & (1<<UDRE0)) );
        UDR0 = data;
}

void uartINIT(){
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
		uartSend(asciiNumbers[rem]);
	}
}
void printUART(const uint8_t n){
	uint8_t size = 1;
	uint8_t num = n;
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
	uint16_t num = n;
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
        uint32_t num = n;
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
