
#define F_CPU 8e6
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>

int numberIndex = 0;

void wait( int ms ) {
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

int main(void)
{
	DDRD = 0b11111100;		// PORTD(7:3) output, PORTD(2:0) input
	DDRC = 0xFF;
	
	unsigned char segvalue = 0b00000001;
	while (1) {
		numberIndex++;
		if(numberIndex > 7) {
			PORTC = 0b11111111;
			wait(500);
			PORTC = 0b00000000;
			wait(500);
			PORTC = 0b11111111;
			numberIndex = 0;
			segvalue = 0b00000001;
		} else {
			segvalue = segvalue << 1;
			PORTC = segvalue;
		}
		wait(500);
	}
}