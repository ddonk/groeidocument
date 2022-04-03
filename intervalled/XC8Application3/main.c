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
	DDRC = 0b00000000;
	char result = 0b00000001;
	int index = 0;
	
	int waitTime = 1000;
	while (1) {
		if(PINC == 0x01) {
			if(waitTime == 1000) {
				waitTime = 4000;
			} else {
				waitTime = 1000;
			}
			
			wait(200);
		}
		PORTD = result;
		result = result<<1;
		index++;
		
		if(index >7) {
			result = 0b00000001;
			index = 0;
		}
		wait(waitTime);

	}
}