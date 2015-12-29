/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <joerg@FreeBSD.ORG> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.        Joerg Wunsch
 * ----------------------------------------------------------------------------
 *
 * Stdio demo, upper layer of LCD driver.
 *
 * $Id: lcd.c,v 1.1.2.1 2005/12/28 22:35:08 joerg_wunsch Exp $
 *
 * Rev. History:
 * mm 08.06	 
 *		lcd_init() 		added arg 1: cursor on/off   
 *		lcd_putchar()	'\r' sets cursor to second line of display
 */




#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include <avr/io.h>

#include <util/delay.h>

#include "hd44780.h"
#include "lcd.h"

/*
 * Setup the LCD controller.  First, call the hardware initialization
 * function, then adjust the display attributes we want.
 */
void lcd_init(int8_t cursor_on)
{

  hd44780_init();

  /*
   * Clear the display.
   */
  hd44780_wait_ready();
  hd44780_outcmd(HD44780_CLR);
  

  /*
   * Entry mode: auto-increment address counter, no display shift in
   * effect.
   */
  hd44780_wait_ready();
  hd44780_outcmd(HD44780_ENTMODE(1, 0));


  /*
   * Enable display, activate non-blinking cursor.
   */
  //hd44780_outcmd(HD44780_DISPCTL(1, 1, 0));
  hd44780_wait_ready();
  hd44780_outcmd(HD44780_DISPCTL(1, cursor_on, 0));
}

/*
 * Send character c to the LCD display.  After a '\n' has been seen,
 * the next character will first clear the display.
 */
int lcd_putchar(char c, FILE *unused)
{
  static bool nl_seen;
  if (c == '\r')	//set cursor to second line
  {
      hd44780_wait_ready();
	  hd44780_outcmd(HD44780_DDADDR(64));
  }
  else if (nl_seen && c != '\n')
  {
      /*
       * First character after newline, clear display and home cursor.
       */
      hd44780_wait_ready();
      hd44780_outcmd(HD44780_CLR);
      hd44780_wait_ready();
      hd44780_outcmd(HD44780_HOME);
      hd44780_wait_ready();
      hd44780_outcmd(HD44780_DDADDR(0));

      nl_seen = false;
  }
  if (c == '\n')
  {
      nl_seen = true;
  }
  else if (c != '\r')
  {
      hd44780_wait_ready();
      hd44780_outdata(c);
  }

  return 0;
}
