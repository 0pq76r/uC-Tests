/* menutree.c
 * Simple LCD menu example based on structs 
 * (c) Matthias Meier, 2015
 */

#include <stdio.h>
#include "menutree.h"

struct MenuItem_T * activeMenu;		//same as: static struct MenuItem_T activeMenu[];
int activeMenuItem;
static int nrMenuItems;


/**
  * _LoadMenu() - load another menu tree (main- or submenu)
 */
void _LoadMenu(struct MenuItem_T menu[], int nrItems)
{
		activeMenu = menu;
		nrMenuItems = nrItems;
		activeMenuItem = 0;
		ProcessMenu(0); 	//Display first menuitem (on first display line)
}

/**
  * ProcessMenu() - change to next or execute current menu item, then display menu text
 */
void ProcessMenu(char button)
{
	switch (button) {

	case BUTTON_MENU:
		activeMenuItem = (activeMenuItem + 1) % nrMenuItems; //proceed to next menu item
		break;

	case BUTTON_EXECUTE:
		if (activeMenu[activeMenuItem].func!=NULL)  
			activeMenu[activeMenuItem].func(); //execute the selected menufunction
	}
	printf("\n%s",activeMenu[activeMenuItem].text);  //display current selected menu text
}



