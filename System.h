/* 
* Contains definition of global variables and functions processing console screen 
*/
#pragma once
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <thread>
using namespace std;

// GLOBAL VARIABLES

// Constants
#define MAX_SIZE_SNAKE 40
#define MAX_SIZE_FOOD 8

const char Snake_Body[] = "2112049221120493211204962112042321120409"; // Body of the snake

extern POINT snake[40]; //snake
extern POINT food[8]; // food

// User interface
enum state { MENU, INGAME, SETTING, SETCOLOR, SETSPEED, SETSOUND, LOADGAME, INFORMATION, GAMEOVER, QUITGAME };
extern state interf; 

extern int CHAR_LOCK; /* used to determine the direction my snake cannot move (At a moment, there is one
			   direction my snake cannot move to) */
extern int MOVING; /* used to determine the direction my snake moves (At a moment, there are three directions
			my snake can move) */
extern int SPEED; // Standing for level, the higher the round, the quicker the speed
extern int HEIGH_CONSOLE, WIDTH_CONSOLE; // Width and height of console-screen
extern int FOOD_INDEX; // current food-index
extern int SIZE_SNAKE; // size of snake, initially is 8 units and maximum size is 40
extern int STATE; // State of snake: dead or alive
extern int LEVEL; // level min is 1 and max is 4
extern int LEVELUP; /* LEVELUP = 0 : the snake is running; LEVELUP = 1 : the snake is going through the gate
				 LEVELUP = 2 : the snake move to next round */
extern int temp; // store the key player pressed
extern int SCORE; // store player score; when the snake eat 1 food, score will be added by 5
extern int start_char; // use to print the snake when moving through the gate
extern int SOUND; // SOUND = 1 : turn on SOUND; SOUND = 0 : turn off SOUND
extern int SNAKE_COLOR; // color of the snake; there are 6 colors

// Function for not allowing to zoom the console window
void FixConsoleWindow();
// Function for not allowing to sellect
void DisableSelection();
// Function to hide scrollbar
void ShowScrollbar(BOOL Show);
// Function to move the cursor to the coordinate
void GotoXY(int x, int y);
// Function to hide and show cursor
void ShowCur(bool CursorVisibility);
// Function to set color of character
void SetColor(WORD color);
// Function to resize the console windows
void resizeConsole(int width, int height);