#ifndef MENUTREE_H
#define MENUTREE_H

// menutree.h
// (c) Matthias Meier

enum MENUBUTTONS{BUTTON_MENU, BUTTON_EXECUTE};

//------------------------------------------------------------------------------

//menu function type (a parameterless function with return value int)
typedef void (*Menufunc_T)(void);

// menu data type (a struct with text to show plus corresponding menu function)
struct MenuItem_T {
	char * text;
	Menufunc_T func;
} ;

// global varaibles (normally not used)
struct MenuItem_T * activeMenu;
int activeMenuItem;


// macro to easy load a new menu
#define LoadMenu(menu) _LoadMenu(menu, NrArrayItems(menu));

// function to Process the Menu when a button is pushed
void ProcessMenu(char button);

//---------------------------------------------------------

//internal function to load a new menu
void _LoadMenu(struct MenuItem_T menu[], int nrMenuItems);

//Macro to estimate the number of items in a menu
#define NrArrayItems(array) (sizeof(array)/sizeof(array[0]))

#endif //MENUTREE_H

