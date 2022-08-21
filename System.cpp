/*
* Implementation of "System.h"
*/
#include "System.h"

POINT snake[40]; 
POINT food[8]; 

int CHAR_LOCK; 
int MOVING; 
int SPEED = 5; 
int HEIGH_CONSOLE, WIDTH_CONSOLE; 
int FOOD_INDEX; 
int SIZE_SNAKE; 
int STATE; 
int LEVEL = 1;
int LEVELUP = 0; 
int temp; 
int SCORE = 0; 
int start_char = 0; 
int SOUND = 1; 
int SNAKE_COLOR = 5; 
state interf; 

void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void DisableSelection()
{
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleMode(hStdin, ~ENABLE_QUICK_EDIT_MODE);
}

void ShowScrollbar(BOOL Show)
{
	HWND hWnd = GetConsoleWindow();
	ShowScrollBar(hWnd, SB_BOTH, Show);
}

void GotoXY(int x, int y)
{
	COORD coord{ x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

void SetColor(WORD color)
{
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}