#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include <stdio.h>
#include <stdlib.h>

#include "lcd_keypad_m2560.h"

#define DEBUG(s) {\
		printf( "%s:%d\r" s, __FILE__, __LINE__);\
		_delay_ms(1000);\
	}
//#define DEBUG(s,...) 

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
	TIMSK0 |= (1<<TOIE0)|(1<<OCIE0A); //Overfow Interrupt
	OCR0A = 249;//Vergleichswert -> 1ms/
}

int main()
{	
	static FILE fd_lcd = FDEV_SETUP_STREAM(lcd_putchar, NULL, _FDEV_SETUP_WRITE);
	stdout = &fd_lcd;
	init_lcd();
	init_timer();

	sei();
	
	DEBUG("INTI END\n");
	
	char space[]="   ";
	printf("%s%s\n", space, text);
	
	while(1){
		if (display ==1)
		{
        printf("Die Zeit ist\r %d %d %d \n", time[DAYTIME].hour, time[DAYTIME].minutes, time[DAYTIME].seconds);
		display =0;
		}
	}
}

