/*
 * Alarmclock.c
 *
 * Created: 30.5.2015 09:34:57
 *  Author: stephanrosenberger
 */ 


#include <avr/io.h>
//#include <delay.h>
#include <avr/interrupt.h>
#include "lcd_keypad_m2560.h"
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
//if(time[DAYTIME].seconds == time[ALARMTIME].seconds){
		
//	}
//	if(time[DAYTIME].minutes == time[ALARMTIME].minutes){
		
	//}
	//if(time[DAYTIME].hour == time[ALARMTIME].hour){
		
	//}

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