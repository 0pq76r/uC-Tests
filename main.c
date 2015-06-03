#define DO_DEBUG 1

#include "header.h"
#include "myIO.h"

void menuAction1(){
	DEBUG("1\n");
}
void menuAction2(){
	DEBUG("2\n");
}
void menuAction3(){
	DEBUG("3\n");
}
void menuAction4(){
	DEBUG("4\n");
}

struct MenuItem_T mainMenu[]= {
	{"Menu Action1", menuAction1},
	{"Menu Action2", menuAction2},
	{"Menu Action3", menuAction3},
	{"Menu Action4", menuAction4},
};

int main()
{	
	initLCD(); //init stdout
	initLCDADC(); //init ADC 

	sei();
	
	DEBUG("Main");
	
	LoadMenu(mainMenu);
	
	SET(DDRA, PA3);
	SET(PORTA, PA3);

	while(1){
		enum LCD_KEY key=get_lcd_key(1);
		if(key==LCD_KEY_SELECT)
		{
			SET(PORTA, PA3);
			ProcessMenu(BUTTON_EXECUTE);
		}
		if(key==LCD_KEY_UP)
		{
			ProcessMenu(BUTTON_MENU);
			CLR(PORTA, PA3);
		}
		_delay_ms(500);
	}
}

