/*
 * main.c
 *
 * Created: 4/3/2022 7:04:47 PM
 *  Author: Daan van Donk
 */ 

#include <xc.h>
#define F_CPU 8e6
#include <avr/io.h>
#include <util/delay.h>

void wait( int ms ) {
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

int main(void) {

		DDRD = 0b11111111;			// All pins PORTD are set to output
		
		char result = 0b00000001;
		while (1) {

			for (int i = 0; i < 8; i++)
			{
				PORTD = result;
				result = result<<1;
				wait(50);
			}

			result = 0b00000001;

		}
}
