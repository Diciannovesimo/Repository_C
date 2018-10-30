#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <string.h>
#include "windowManager.h"
#include "menuManager.h"

/*
	Variabili --------------------------------------------------------------------------------------------------------------
*/

WINDOW window;

/*
	Funzioni ---------------------------------------------------------------------------------------------------------------
*/

main()
{
	initializeWindow(&window, &"HOME MENU", 25, 50);
	sprintf(window.content[5], "-> Option 1");
	sprintf(window.content[10], "   Option 2");
	sprintf(window.content[15], "   Option 3");
	sprintf(window.content[20], "   Option 4");
	sprintf(window.content[24], "Press 'ESC' to exit.");
	printWindow(&window);

	startMenu(4);
}

void switchOptions()
{
	switch(menIndex)
	{
		case 1:
			sprintf(window.content[5], "-> Option 1");
			sprintf(window.content[10], "   Option 2");
			break;
		case 2:
			sprintf(window.content[5], "   Option 1");
			sprintf(window.content[10], "-> Option 2");
			sprintf(window.content[15], "   Option 3");
			break;
		case 3:
			sprintf(window.content[10], "   Option 2");
			sprintf(window.content[15], "-> Option 3");
			sprintf(window.content[20], "   Option 4");
			break;
		case 4:
			sprintf(window.content[15], "   Option 3");
			sprintf(window.content[20], "-> Option 4");
			break;
	}

	system("cls");
 	printWindow(&window);
}

void onEnter()
{

}
