/* 
* Contains all the function about draw in the game 
*/
#pragma once
#include "System.h"

// Function to draw the board of game
void DrawBoard(int x, int y, int width, int height, int curPosX = 0, int curPosY = 0);
// Function to draw board of score and length while playing
void SmallBoard();

// Function to draw snake and food
void DrawSnakeAndFood(const char str, int start_char = 0);

// Function to draw obstacles in level 2
void DrawWallLevel2();
// Function to draw obstacles in level 3
void DrawWallLevel3();
// Function to draw obstacles in level 4
void DrawWallLevel4();

// Function to draw gate in level 1
void DrawGateLv1();
// Function to draw gate in level 2
void DrawGateLv2();
// Function to draw gate in level 3
void DrawGateLv3();
// Function to draw gate in level 4
void DrawGateLv4();

// Function to draw board after saving and loading
void DrawContinueGame();
