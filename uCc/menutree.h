// menutree.h
// (c) Matthias Meier
// Fach: mpppro, Beispiel MenuTree

//Menu button assignments for mcHob2 board ...
#define BUTTON_MENU 	BUTTON_S3	//select next menu item
#define BUTTON_EXECUTE 	BUTTON_S4	//execute menu function currently displayed
#define BUTTON_XXX	BUTTON_S5	//currently not used..

//------------------------------------------------------------------------------

//define menu function type: a parameterless function with return value int
typedef int (*Menufunc_T)(void);

//Menu data type: a struct with text to show and a menu function...
struct MenuItem_T {
	char * text;
	Menufunc_T func;
} ;
//Rem: exit from submenu if field funct is NULL or definded menu function returns !=0 


//Macro to estimate the number of items in a menu
#define NrArrayItems(array) (sizeof(array)/sizeof(array[0]))

//Function to Load and display the Top-Menu ()
void LoadMenu(struct MenuItem_T menu[], int nrMenuItems);

//Function to Process the Menu when a button is pushed
void ProcessMenu(int button_state);
