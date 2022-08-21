/* 
* Contains main function to process the snake and thread of the game 
*/
#pragma once
#include "System.h"
#include "Draw.h"
#include "Dead.h"
#include "Prepare.h"

// Function to prepare for starting the game
void StartGame();
//Function pause game
void PauseGame(HANDLE t);

// Function to check if a filename existed
bool ExistFileName(const char* namesaved, const char* filename);
// Function to save game
void SaveGame();
// Function to load game
void LoadGame();


// Function to update global data
void Eat();
// Function to process when the snake die
void ProcessDead();


// Function for moving left
void MoveLeft();
// Function for moving right
void MoveRight();
// Function for moving up
void MoveUp();
// Function for moving down
void MoveDown();


// Subfunction for thread
void ThreadFunc();

// Function to draw and execute game's function 
void Menu();
// Function for playing game
void InGame(int oldgame = 0);
// Function to draw game over screen
void GameOver();
// Function to quit the game
void QuitGame();
// Function to draw information screen
void Information();

// Function for setting snake color
void SetSnakeColor();
// Function for setting start speed
void SetSpeed();
// Function to turn on/off sound
void SetSound();
// Function for setting game
void Setting();
