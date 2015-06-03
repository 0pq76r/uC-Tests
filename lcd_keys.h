#ifndef __LCD_KEYS_H__
#define __LCD_KEYS_H__

enum LCD_KEY
{
	LCD_KEY_SELECT, LCD_KEY_LEFT, LCD_KEY_DOWN, LCD_KEY_UP, LCD_KEY_RIGHT, LCD_KEY_NONE, LCD_KEY_WAITING
};

extern void initLCD();
extern void initLCDADC();
extern enum LCD_KEY get_lcd_key(char block); // REQ. LCD ADC setup
extern enum LCD_KEY adc_to_lcd_key(uint16_t adc);

#endif
