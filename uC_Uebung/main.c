#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

#include <stdio.h>
#include <stdlib.h>

#include "lcd_keypad_m2560.h"

static void initADC()
{
	//ADC for LCD buttons
	ADMUX=1<<REFS0;
	ADCSRB=1<<ACME;
	ADCSRA=1<<ADEN|1<<ADSC| \
		1<<ADPS2|1<<ADPS1|1<<ADPS0;
}

static void initDIO()
{
	DDRA=0xff;
	PORTA=0xff;
}

enum lcd_key
{
	select, left, down, up, right, none
};

static enum lcd_key get_lcd_key()
{
	static uint8_t reading=0;
	if(!reading)
	{
		ADCSRA|=1<<ADSC; //Read
		reading=1;
	}

	if((ADCSRA>>ADSC)&1) return none; //Wait
	uint16_t acd=ADC; 
	reading=0;

	if(acd<100)
		return right;
	if(acd<300)
		return up;
	if(acd<450)
		return down;
	if(acd<700)
		return left;
	if(acd<900)
		return select;
		
	return none;
}

enum State{Aus, Ein, IntvMess, IntvWait};
#define MAXIMUM 100

int main()
{	
	static FILE fd_lcd = FDEV_SETUP_STREAM(lcd_putchar, NULL, _FDEV_SETUP_WRITE);
	stdout = &fd_lcd;
	
	static enum State state = Aus;
	static int timer, intervalzeit=0;

	init_lcd();
	initADC();
	initDIO();
	
	sei();
	
	while(1){
		switch(state)
		{
			case Aus:
				printf_P(PSTR("Aus\n"));
				PORTA=0x00;

				if(get_lcd_key()==up)
				{
					state=Ein;
					PORTA=0xFF;
				}
			break;
			case Ein:
				printf_P(PSTR("Ein\n"));
				PORTA=0xFF;

				if(get_lcd_key()==down)
				{
					PORTA=0x00;
					state=IntvMess;
					timer=0;
				}
				break;
			case IntvMess:
				printf_P(PSTR("IntvMess\r%d\n"),timer);
				timer++;
				PORTA=0x00;

				if(timer==MAXIMUM)
				{
					state=Aus;
				}
				if(get_lcd_key()==up)
				{
					state=IntvWait;
					PORTA=0xFF;
					intervalzeit=timer;
					timer=0;
				}
			break;
			case IntvWait:
				printf_P(PSTR("IntvWait\r%d\n"),timer);
				PORTA=0x00;
				
				timer++;

				if(get_lcd_key()==down)
				{
					state=IntvMess;
					PORTA=0xFF;
					timer=0;
				}
				if(timer==intervalzeit)
				{
					PORTA=0xFF;
					timer=0;
				}
			break;
		}
		_delay_ms(100);
	}
}
