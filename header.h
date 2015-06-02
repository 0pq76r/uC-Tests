#ifndef __HEADER_H__
#define __HEADER_H__

#ifdef DO_DEBUG
	#define DEBUG(s) {\
			printf( "\n%s:%d\r" s, __FILE__, __LINE__);\
			_delay_ms(1000);\
		}
#else
	#define DEBUG(s) 
#endif


#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "lcd_keypad_m2560.h"
#include "menutree.h"
#include "lcd_keys.h"


#endif
 
