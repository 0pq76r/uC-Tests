#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
//#include <delay.h>
#include <avr/interrupt.h>
#include "lcd_keypad_m2560.h"


#define DEBUG(s) {\
		printf( "%s:%d\r" s, __FILE__, __LINE__);\
		_delay_ms(1000);\
	}
//#define DEBUG(s,...) 

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

enum State{};


struct Time {
	volatile int seconds;
	volatile int minutes;
	volatile int hour;
};
volatile int display = 1;


enum TimeIndex {DAYTIME, ALARMTIME};

struct Time time[2] = {};

ISR(TIMER0_COMPA_vect){
	static uint16_t tics;
	tics++;
	if (tics == 1000)
	{
		time[DAYTIME].seconds++;
		tics=0;
		display =1;
	}
	if (time[DAYTIME].seconds ==60)
	{
		time[DAYTIME].seconds = 0;

		time[DAYTIME].minutes++;
		if (time[DAYTIME].minutes == 60)
		{
			time[DAYTIME].minutes = 0;
			time[DAYTIME].hour++;
			if (time[DAYTIME].hour == 24)
			{
				time[DAYTIME].hour= 0;
			}
		}
	}
}

void init_timer(){
	TCCR0A |=(1<<WGM01);//CTC-Mode
	TCCR0B |=(1<<CS00)|(1<<CS01);//Prescaler 64
	OCR0A = 124;//Vergleichswert -> 1ms/
}

int main(void)
{	
		static FILE fd_lcd = FDEV_SETUP_STREAM(lcd_putchar, NULL, _FDEV_SETUP_WRITE);
		stdout = &fd_lcd;
		init_lcd();
		init_timer();
		sei();//Globales Interupt
    while(1)
    {
		printf("asdf3r");
		continue;
		if (display ==1)
		{
        printf("Die Zeit ist\r %d %d %d \n", time[DAYTIME].hour, time[DAYTIME].minutes, time[DAYTIME].seconds);
		display =0;
		}
    }
}


int main()
{	
	static FILE fd_lcd = FDEV_SETUP_STREAM(lcd_putchar, NULL, _FDEV_SETUP_WRITE);
	stdout = &fd_lcd;
	init_lcd();
	
	static enum State state = Aus;
	static int timer, intervalzeit=0;

	DEBUG("Main");

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
				printf("IntvWait\r%f\n",3.3*timer);
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

