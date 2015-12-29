/* File:    lcdtest.c
 * Version: V1.0, (c) 2007 Matthias Meier
 * Zweck:   Testprogramm fuer mcHob LCD-Display Treiber
 *
 * Quelle:  Der LCD-Treiber (lcd.* und hd44780.*) wurde mit kleinen Aenderungen aus 
 *			dem WinAVR-Demo-Projekt C:\Programme\WinAVR-20070525\examples\stdiodemo übernommen
 *
 * Bemerkungen zur Funktion _delay_ms() aus avr-libc
 * - _delay_ms() ist in avr-libc als Software-Delayschlaufe implementiert, weshalb...
 * - Frequency in Projektoptionen mit effektivem Takt (Quart, Fusebits, etc) uebereistimmen muss!!
 * - Zulaessiges maximales Delay ist abh.von Taktfrequenz: siehe avr-libc Reference Manual!!
 */


#include <avr/io.h>			//AVR IO-Registers
#include <util/delay.h>		//_dealy_ms() 
#include <stdio.h>			//FILE , printf()

#include "lcd.h"

#define BTNMASK ((1<<PD5)|(1<<PD4)|(1<<PD3))	//mcHob: Taster an PD5..3

int main()
{
  char buttons;

  static FILE lcd_str = FDEV_SETUP_STREAM(lcd_putchar, NULL, _FDEV_SETUP_WRITE);
  stdout = &lcd_str;	//Standardausgabe auf obigen Stream setzen

  lcd_init(0);	//LCD-Display initialisieren

  DDRC = 0xff; //LED-Port auf Ausgang
  PORTD = BTNMASK;	//Pullups auf Taster aktivieren
  
  while (1)
  { 
    buttons = (~PIND & BTNMASK) >> PD3;		//Taster einlesen, invertieren, maskieren, auf LSB ausrichten
    printf("Hi Folks!\rButtons = %d\n",buttons);	//Ausgabe auf LCD in 2 Zeilen
  	PORTC=buttons; 	//und auch an LEDs
	_delay_ms(100); //Wartepause damit LCD-Anzeige besser sichtbar...
  }
}


