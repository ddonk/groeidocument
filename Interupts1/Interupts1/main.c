#define F_CPU 8e6
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int ledIndex = 0;

ISR( INT0_vect ) {
	ledIndex--;
	ledIndex = (ledIndex < 0 ? 7 : ledIndex);
	PORTC = (1<<ledIndex);
}


ISR( INT1_vect ) {
	ledIndex++;
	//if i is greater then 7
	ledIndex = (ledIndex > 7 ? 0 : ledIndex);
	PORTC = (1<<ledIndex);
}


int main(void)
{
	DDRC = 0xFF; //Setting row to output
	DDRD = 0x00;
	
	EICRA |= 0x0B;			// INT1 falling edge, INT0 rising edge
	EIMSK |= 0x03;			// Enable INT1 & INT0

	sei();
	
	/* Replace with your application code */
	while (1)
	{
	}
}