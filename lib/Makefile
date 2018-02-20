CC=avr-gcc
MCU=atmega324pa
OPTLEVEL=s
CFLAGS=-I. -MMD -g -mmcu=$(MCU) -O$(OPTLEVEL) \
        -fpack-struct -fshort-enums             \
        -funsigned-bitfields -funsigned-char    \
        -Wall
all: uart.o pwm.o memory.o can.o
	avr-ar crs -o libohboy.a $^
pwm.o: pwm.h pwm.cpp
	$(CC) $(CFLAGS) -l. -c pwm.cpp -o $@
uart.o: uart.h uart.cpp
	$(CC) $(CFLAGS) -l. -c uart.cpp -o $@
memory.o: memory.h memory.cpp
	$(CC) $(CFLAGS) -l. -c memory.cpp -o $@
can.o: can.h can.cpp
	$(CC) $(CFLAGS) -l. -c can.cpp -o $@

clean:
	rm *.o
	rm *.d
