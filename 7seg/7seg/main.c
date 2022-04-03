
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

const unsigned char NUMBERS[11] = {
	0b00111111, // 0
	0b00000110, // 1
	0b01011011, // 2
	0b01001111, // 3
	0b01100110, // 4
	0b01101101, // 5
	0b01111101, // 6
	0b00000111, // 7
	0b01111111, // 8
	0b01101111, // 9
	0b01111001, // E
};

void display(int digit) {
	if (digit > 10) {
		PORTC = NUMBERS[10];
		} else {
		PORTC = NUMBERS[digit];
	}
}

int main(void)
{
	DDRD = 0b11111100;		// PORTD(7:3) output, PORTD(2:0) input
	DDRC = 0xFF;
	
	while (1) {		
		if (PIND == 0x01) {
			numberIndex++;
			} else if (PIND == 0x02) {
			numberIndex--;
			} else if (PIND == 0x03) {
			numberIndex = 0;
		}
		if (numberIndex < 0) {
			 numberIndex = 0;
		}
		display(numberIndex);
		wait(500);
	}
}