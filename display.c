#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include <stdio.h>
#include <stdlib.h>

#include "lcd_keypad_m2560/lcd_keypad_m2560.c"

void initADC()
{
	ADMUX=1<<REFS0;
	ADCSRB=1<<ACME;
	ADCSRA=1<<ADEN|1<<ADSC| \
		1<<ADPS2|1<<ADPS1|1<<ADPS0;
}

uint16_t readADC()
{
	ADCSRA|=1<<ADSC;
	while((ADCSRA>>ADSC)&1);
	return (ADC);
}

int main()
{	
	static FILE fd_lcd = FDEV_SETUP_STREAM(lcd_putchar, NULL, _FDEV_SETUP_WRITE);
	stdout = &fd_lcd;

	init_lcd();
	initADC();

	while(1){
		printf("ASDF %d\n", readADC());
		_delay_ms(250);
	}
}
