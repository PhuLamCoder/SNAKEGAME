/* 
* Contains functions about check and reset data for new game 
*/
#pragma once
#include "System.h"

// Function to check if the food is valid in level 1
bool IsValidLevel1(int x, int y);
// Function to check if the food is valid in level 2
bool IsValidLevel2(int x, int y);
// Function to check if the food is valid in level 3
bool IsValidLevel3(int x, int y);
// Function to check if the food is valid in level 4
bool IsValidLevel4(int x, int y);

// Function to generate food for 4 level
void GenerateFood();

// Function to reset data in level 1
void ResetDataLV1();
// Function to reset data in level 2
void ResetDataLV2();
// Function to reset data in level 3
void ResetDataLV3();
// Function to reset data in level 4
void ResetDataLV4();
