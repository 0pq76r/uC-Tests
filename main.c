#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include <stdio.h>
#include <stdlib.h>

#include "music.h"
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

static void initT0()
{
	TCCR0B = (1<<CS00); // Prescaler 0 
	TIMSK0 |= (1<<TOIE0); //Overfow Interrupt
}

enum lcd_key
{
	select, left, down, up, right, none
};

static enum lcd_key get_lcd_key()
{
	ADCSRA|=1<<ADSC; //Read
	while((ADCSRA>>ADSC)&1); //Wait
	uint16_t acd=ADC; 

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

ISR (TIMER0_OVF_vect)
{
	uint8_t sreg=SREG;
	/* Interrupt Aktion alle
	* 	(16e6)/256 Hz = 62.5 kHz
	*/

	play_62_5_kHz();
	
	SREG=sreg;
}

int main()
{	
	static FILE fd_lcd = FDEV_SETUP_STREAM(lcd_putchar, NULL, _FDEV_SETUP_WRITE);
	stdout = &fd_lcd;

	init_lcd();
	initADC();
	initT0();
	initDIO();
	initMusic();
	
	sei();
	
	while(1){
		static uint8_t trig=0;
		switch(get_lcd_key())
		{
			case select:
				if(trig)break;
				trig=1;

				music_stop();
			break;
			case left:
				if(trig)break;
				trig=1;

				music_start();
			break;
			case down:
				if(trig)break;
				trig=1;

			break;
			case up:
				if(trig)break;
				trig=1;

			break;
			case right:
				if(trig)break;
				trig=1;

				music_next();
			break;
			default:
				trig=0;
			break;
		}
	}
}
