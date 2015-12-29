// menutree.c
// Simple Example of a LCD Menu based on structs 
// (c) Matthias Meier, 2011
// Modul: mc1
// Aim: Struct and functions for simple menu tree handling

#include <stdio.h>
//#include <avr/pgmspace.h> 
//Rem: much SRAM could be saved by using PSTR() / PROGMEM / printf_P("%S") 
//     but definition of the struct constants are ugly due to compiler-restrictions

#include "menutree.h"
#include "buttons.h"

static struct MenuItem_T * activeMenu;
//static struct MenuItem_T activeMenu[];
static int activeMenuItem;
static int nrMenuItems;

//------------------------------------------------------------------------------

/** ProcessMenu() - function to Load an execute a (sub)menu...
 */

void LoadMenu(struct MenuItem_T menu[], int nrItems)
{
		activeMenu = menu;
		nrMenuItems = nrItems;
		activeMenuItem = 0;
		ProcessMenu(0); //Display first menuitem (on first display line)
}

void ProcessMenu(int button_state)
{
	switch (button_state) {

	case BUTTON_MENU:
		activeMenuItem = (activeMenuItem + 1) % nrMenuItems; //proceed to next menu item
		break;

	case BUTTON_EXECUTE:
		if (activeMenu[activeMenuItem].func==NULL) //no action because no menufunction defined
			return;
		else 
			activeMenu[activeMenuItem].func(); //execute the selected menufunction

	}
	printf("\n%s",activeMenu[activeMenuItem].text);  //display current selected menu text
}

//------------------------------------------------------------------------------

