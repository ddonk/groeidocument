/*
 * main.c
 *
 * Created: 4/3/2022 6:50:16 PM
 *  Author: Daan van Donk
 */ 

#include <xc.h>
#define F_CPU 8e6

#include <avr/io.h>
#include <util/delay.h>


/******************************************************************/
void wait( int ms )
/* 
short:			Busy wait number of millisecs
inputs:			int ms (Number of millisecs to busy wait)
outputs:	
notes:			Busy wait, not very accurate. Make sure (external)
				clock value is set. This is used by _delay_ms inside
				util/delay.h
*******************************************************************/
{
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

/******************************************************************/
int main( void ) {
/* 
short:			main() loop, entry point of executable
inputs:			
outputs:	
notes:			Looping forever, flipping bits on PORTD
*******************************************************************/

	DDRD = 0b11111111;			// All pins PORTD are set to output 
	
	while (1) {
		PORTD = 0b01000000;
		wait( 500 );				
		PORTD = 0b10000000;
		wait( 500 );				
	}

	return 1;
}
