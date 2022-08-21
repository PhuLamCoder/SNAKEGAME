/* 
* Contains functions that process death when the snake hits obstacles 
*/
#pragma once
#include "System.h"

// Function to check if the snake hits it body when turn left
bool ReachBodyLeft();
// Function to check if the snake hits it body when turn right
bool ReachBodyRight();
// Function to check if the snake hits it body when turn up
bool ReachBodyUp();
// Function to check if the snake hits it body when turn down
bool ReachBodyDown();


// Function to check if the snake hits wall when turn left in level 1
bool LeftDeadLevel1();
// Function to check if the snake hits wall when turn right in level 1
bool RightDeadLevel1();
// Function to check if the snake hits wall when turn up in level 1
bool UpDeadLevel1();
// Function to check if the snake hits wall when turn down in level 1
bool DownDeadLevel1();


// Function to check if the snake hits wall when turn left in level 2
bool LeftDeadLevel2();
// Function to check if the snake hits wall when turn right in level 2
bool RightDeadLevel2();
// Function to check if the snake hits wall when turn up in level 2
bool UpDeadLevel2();
// Function to check if the snake hits wall when turn down in level 2
bool DownDeadLevel2();


// Function to check if the snake hits wall when turn left in level 3
bool LeftDeadLevel3();
// Function to check if the snake hits wall when turn right in level 3
bool RightDeadLevel3();
// Function to check if the snake hits wall when turn up in level 3
bool UpDeadLevel3();
// Function to check if the snake hits wall when turn down in level 3
bool DownDeadLevel3();


// Function to check if the snake hits wall when turn left in level 4
bool LeftDeadLevel4();
// Function to check if the snake hits wall when turn right in level 4
bool RightDeadLevel4();
// Function to check if the snake hits wall when turn up in level 4
bool UpDeadLevel4();
// Function to check if the snake hits wall when turn down in level 4
bool DownDeadLevel4();
