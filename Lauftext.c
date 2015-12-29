/*
 * Lauftext.c
 *
 * Created: 31.5.2015 12:37:21
 *  Author: anitarosenberger
 */ 


#include <avr/io.h>
#include "lcd_keypad_m2560.h"
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>

void laufText(char* laufText){
	char *spaces="                 ";
	for(int i = 0;*laufText!=0;i++){
		if(*spaces==0)
			laufText++;
		else
			spaces++;

		printf("%s%s\n", spaces, laufText);
		_delay_ms(300);
	 }
	
	_delay_ms(300);
	 printf(" \n");
}
int main(void)
{
	char msg[] ={"De Ferdinant isch gstorbe "};
		
		static FILE fd_lcd = FDEV_SETUP_STREAM(lcd_putchar, NULL, _FDEV_SETUP_WRITE);
		stdout = &fd_lcd;
		
	init_lcd();     
	      
    while(1)
    {		
		laufText(msg);//alternativ &msg[0]
		_delay_ms(200);
    }
}