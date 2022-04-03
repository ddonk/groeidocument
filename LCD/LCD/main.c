/*
 * main.c
 *
 * Created: 4/3/2022 9:11:29 PM
 *  Author: Daan van Donk
 */ 

#define F_CPU 8e6
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "LCDHelper/LCDHelper.h"

void wait( int ms ) {
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

int main(void)
{
	init();
	const char* result = "test";
	display_text(result);
	while (1) {


		wait(1);
	}
}