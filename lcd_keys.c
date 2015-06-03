#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

#include "lcd_keys.h"
#include "lcd_keypad_m2560.h"

enum LCD_KEY adc_to_lcd_key(uint16_t adc)
{
	if(adc<100)
		return LCD_KEY_RIGHT;
	if(adc<300)
		return LCD_KEY_UP;
	if(adc<450)
		return LCD_KEY_DOWN;
	if(adc<700)
		return LCD_KEY_LEFT;
	if(adc<900)
		return LCD_KEY_SELECT;
	
	return LCD_KEY_NONE;
}

enum LCD_KEY get_lcd_key(char block)
{
	static uint8_t reading=0;
	if(!reading)
	{
		ADCSRA|=1<<ADSC; //Read
		reading=1;
	}

	while((ADCSRA>>ADSC)&1)
		if(!block) return LCD_KEY_WAITING; //Wait

	reading=0;
	return adc_to_lcd_key(ADC);
}

void initLCD()
{
	static FILE fd_lcd = FDEV_SETUP_STREAM(lcd_putchar, NULL, _FDEV_SETUP_WRITE);
	stdout = &fd_lcd;
	init_lcd();
}

void initLCDADC()
{
	//ADC for LCD buttons
	ADMUX|=1<<REFS0;
	ADCSRB|=1<<ACME;
	ADCSRA|=1<<ADEN|1<<ADSC| \
		1<<ADPS2|1<<ADPS1|1<<ADPS0;
}

