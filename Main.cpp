/*
* Main function process the thread of the game
*/
#include "ProcessGame.h"

int main()
{
	interf = MENU;
	resizeConsole(950, 540);
	FixConsoleWindow();
	DisableSelection();
	ShowScrollbar(0);
	StartGame(); 
	ShowCur(0);
	SetColor(2);
	Menu();
	while (1)
	{
		switch (interf)
		{
		case MENU:
			Menu();
			break;
		case INGAME:
			InGame();
			break;
		case SETTING:
			Setting();
			break;
		case SETCOLOR:
			SetSnakeColor();
			break;
		case SETSPEED:
			SetSpeed();
			break;
		case SETSOUND:
			SetSound();
			break;
		case INFORMATION:
			Information();
			break;
		case LOADGAME:
			LoadGame();
			InGame(1);
			break;
		case GAMEOVER:
			GameOver();
			break;
		case QUITGAME:
			QuitGame();
			break;
		}
	}
	return 0;
}