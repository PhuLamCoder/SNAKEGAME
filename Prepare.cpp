/*
* Implementation of "Prepare.h"
*/
#include "Prepare.h"

bool IsValidLevel1(int x, int y)
{
	for (int i = 0; i < SIZE_SNAKE; i++)
	{
		if (snake[i].x == x && snake[i].y == y)
		{
			return false;
		}
	}
	return true;
}
bool IsValidLevel2(int x, int y)
{
	for (int i = 13; i < 30; i++)
	{
		if (x == i && y == 6)
			return false;
		if (x == i && y == 24)
			return false;
	}
	for (int i = 7; i <= 11; i++)
	{
		if (x == 13 && y == i)
			return false;
		if (x == 14 && y == i)
			return false;
		if (x == 77 && y == i)
			return false;
		if (x == 76 && y == i)
			return false;
	}
	for (int i = 19; i <= 24; i++)
	{
		if (x == 13 && y == i)
			return false;
		if (x == 14 && y == i)
			return false;
		if (x == 77 && y == i)
			return false;
		if (x == 76 && y == i)
			return false;
	}
	for (int i = 60; i <= 77; i++)
	{
		if (x == i && y == 6)
			return false;
		if (x == i && y == 24)
			return false;
	}
	for (int i = 44; i <= 47; i++)
	{
		if (x == i && y == 15)
			return false;
		if (x == i && y == 16)
			return false;
	}
	for (int i = 48; i <= 51; i++)
	{
		for (int j = 14; j >= 11; j--)
			if (x == i && y == j)
				return false;
		for (int j = 17; j <= 20; j++)
			if (x == i && y == j)
				return false;
	}
	for (int i = 43; i >= 40; i--)
	{
		for (int j = 14; j >= 11; j--)
			if (x == i && y == j)
				return false;
		for (int j = 17; j <= 20; j++)
			if (x == i && y == j)
				return false;
	}
	for (int i = 0; i < SIZE_SNAKE; i++)
	{
		if (snake[i].x == x && snake[i].y == y)
		{
			return false;
		}
	}
	return true;
}
bool IsValidLevel3(int x, int y)
{
	for (int i = 11; i <= 22; i++)
	{
		if (x == i && y == 6) return false;
		if (x == i && y == 22) return false;
	}
	for (int i = 30; i <= 41; i++)
	{
		if (x == i && y == 12) return false;
		if (x == i && y == 16) return false;
	}
	for (int i = 52; i <= 63; i++)
	{
		if (x == i && y == 12) return false;
		if (x == i && y == 16) return false;
	}
	for (int i = 71; i <= 82; i++)
	{
		if (x == i && y == 6) return false;
		if (x == i && y == 22) return false;
	}
	for (int i = 6; i <= 11; i++)
	{
		if (x == 40 && y == i) return false;
		if (x == 41 && y == i) return false;
		if (x == 52 && y == i) return false;
		if (x == 53 && y == i) return false;
	}
	for (int i = 7; i <= 12; i++)
	{
		if (x == 11 && y == i) return false;
		if (x == 12 && y == i) return false;
		if (x == 81 && y == i) return false;
		if (x == 82 && y == i) return false;
	}
	for (int i = 17; i <= 22; i++)
	{
		if (x == 40 && y == i) return false;
		if (x == 41 && y == i) return false;
		if (x == 52 && y == i) return false;
		if (x == 53 && y == i) return false;
	}
	for (int i = 16; i <= 21; i++)
	{
		if (x == 11 && y == i) return false;
		if (x == 12 && y == i) return false;
		if (x == 81 && y == i) return false;
		if (x == 82 && y == i) return false;
	}
	return true;
}
bool IsValidLevel4(int x, int y)
{
	for (int i = 0; i < SIZE_SNAKE; i++)
	{
		if (snake[i].x == x && snake[i].y == y)
		{
			return false;
		}
	}
	for (int i = 8; i <= 22; i++)
	{
		if (x == i && y == 8)
			return false;
		if (x == i && y == 21)
			return false;
	}
	for (int i = 70; i <= 84; i++)
	{
		if (x == i && y == 8)
			return false;
		if (x == i && y == 21)
			return false;
	}
	for (int i = 29; i <= 37; i++)
	{
		if (x == i && y == 4)
			return false;
		if (x == i && y == 25)
			return false;
	}
	for (int i = 55; i <= 63; i++)
	{
		if (x == i && y == 4)
			return false;
		if (x == i && y == 25)
			return false;
	}
	for (int i = 36; i <= 56; i++)
	{
		if (x == i && y == 6)
			return false;
		if (x == i && y == 23)
			return false;
	}
	for (int j = 4; j <= 8; j++)
	{
		if (x == 22 && y == j)
			return false;
		if (x == 70 && y == j)
			return false;
		if (x == 21 && y == j)
			return false;
		if (x == 71 && y == j)
			return false;
	}
	for (int j = 21; j <= 25; j++)
	{
		if (x == 22 && y == j)
			return false;
		if (x == 70 && y == j)
			return false;
		if (x == 21 && y == j)
			return false;
		if (x == 71 && y == j)
			return false;
	}
	for (int j = 4; j <= 6; j++)
	{
		if (x == 36 && y == j)
			return false;
		if (x == 56 && y == j)
			return false;
		if (x == 37 && y == j)
			return false;
		if (x == 55 && y == j)
			return false;

	}
	for (int j = 23; j <= 25; j++)
	{
		if (x == 36 && y == j)
			return false;
		if (x == 56 && y == j)
			return false;
		if (x == 37 && y == j)
			return false;
		if (x == 55 && y == j)
			return false;
	}
	for (int i = 38; i <= 54; i++)
	{
		if (x == i && y == 15)
			return false;
	}
	for (int i = 44; i <= 48; i++)
	{
		if (x == i && y == 14)
			return false;
		if (x == i && y == 16)
			return false;
	}
	return true;
}


void GenerateFood()
{
	int x, y;
	srand((time_t)time(NULL));
	switch (LEVEL)
	{
	case 1:
		for (int i = 0; i < MAX_SIZE_FOOD; i++)
		{
			do
			{
				x = rand() % (WIDTH_CONSOLE - 1) + 2;
				y = rand() % (HEIGH_CONSOLE - 1) + 2;
			} while (!IsValidLevel1(x, y));
			food[i] = { x,y };
		}
		break;
	case 2:
		for (int i = 0; i < MAX_SIZE_FOOD; i++)
		{
			do
			{
				x = rand() % (WIDTH_CONSOLE - 1) + 2;
				y = rand() % (HEIGH_CONSOLE - 1) + 2;
			} while (!IsValidLevel2(x, y));
			food[i] = { x,y };
		}
		break;
	case 3:
		for (int i = 0; i < MAX_SIZE_FOOD; i++)
		{
			do
			{
				x = rand() % (WIDTH_CONSOLE - 1) + 2;
				y = rand() % (HEIGH_CONSOLE - 1) + 2;
			} while (!IsValidLevel3(x, y));
			food[i] = { x,y };
		}
		break;
	case 4:
		for (int i = 0; i < MAX_SIZE_FOOD; i++)
		{
			do
			{
				x = rand() % (WIDTH_CONSOLE - 1) + 2;
				y = rand() % (HEIGH_CONSOLE - 1) + 2;
			} while (!IsValidLevel4(x, y));
			food[i] = { x,y };
		}
		break;
	}
}


void ResetDataLV1()
{
	// Initialize the global values
	CHAR_LOCK = 'A', MOVING = 'D', FOOD_INDEX = 0, WIDTH_CONSOLE = 90,
		HEIGH_CONSOLE = 27, SIZE_SNAKE = 8;
	// Initialize default values for snake
	snake[0] = { 17, 5 }; snake[1] = { 16, 5 };
	snake[2] = { 15, 5 }; snake[3] = { 14, 5 };
	snake[4] = { 13, 5 }; snake[5] = { 12, 5 };
	snake[6] = { 11, 5 }; snake[7] = { 10, 5 };
	GenerateFood(); // Create food array
}
void ResetDataLV2()
{
	// Initialize the global values
	CHAR_LOCK = 'A', MOVING = 'D'; FOOD_INDEX = 0, WIDTH_CONSOLE = 90,
		HEIGH_CONSOLE = 27, SIZE_SNAKE = 16;
	// Initialize default values for snake
	snake[0] = { 25, 4 }; snake[1] = { 24, 4 };
	snake[2] = { 23, 4 }; snake[3] = { 22, 4 };
	snake[4] = { 21, 4 }; snake[5] = { 20, 4 };
	snake[6] = { 19, 4 }; snake[7] = { 18, 4 };

	snake[8] = { 17, 4 }; snake[9] = { 16, 4 };
	snake[10] = { 15, 4 }; snake[11] = { 14, 4 };
	snake[12] = { 13, 4 }; snake[13] = { 12, 4 };
	snake[14] = { 11, 4 }; snake[15] = { 10, 4 };
	GenerateFood(); // Create food array
}
void ResetDataLV3()
{
	// Initialize the global values
	CHAR_LOCK = 'A', MOVING = 'D'; FOOD_INDEX = 0, WIDTH_CONSOLE = 90,
		HEIGH_CONSOLE = 27, SIZE_SNAKE = 24;
	// Initialize default values for snake
	snake[0] = { 33, 4 }; snake[1] = { 32, 4 };
	snake[2] = { 31, 4 }; snake[3] = { 30, 4 };
	snake[4] = { 29, 4 }; snake[5] = { 28, 4 };
	snake[6] = { 27, 4 }; snake[7] = { 26, 4 };

	snake[8] = { 25, 4 }; snake[9] = { 24, 4 };
	snake[10] = { 23, 4 }; snake[11] = { 22, 4 };
	snake[12] = { 21, 4 }; snake[13] = { 20, 4 };
	snake[14] = { 19, 4 }; snake[15] = { 18, 4 };

	snake[16] = { 17, 4 }; snake[17] = { 16, 4 };
	snake[18] = { 15, 4 }; snake[19] = { 14, 4 };
	snake[20] = { 13, 4 }; snake[21] = { 12, 4 };
	snake[22] = { 11, 4 }; snake[23] = { 10, 4 };
	GenerateFood(); // Create food array
}
void ResetDataLV4()
{
	// Initialize the global values
	CHAR_LOCK = 'A', MOVING = 'D'; FOOD_INDEX = 0, WIDTH_CONSOLE = 90,
		HEIGH_CONSOLE = 27, SIZE_SNAKE = 32;
	// Initialize default values for snake
	snake[0] = { 35, 11 }; snake[1] = { 34, 11 };
	snake[2] = { 33, 11 }; snake[3] = { 32, 11 };
	snake[4] = { 31, 11 }; snake[5] = { 30, 11 };
	snake[6] = { 29, 11 }; snake[7] = { 28, 11 };

	snake[8] = { 27, 11 }; snake[9] = { 26, 11 };
	snake[10] = { 25, 11 }; snake[11] = { 24, 11 };
	snake[12] = { 23, 11 }; snake[13] = { 22, 11 };
	snake[14] = { 21, 11 }; snake[15] = { 20, 11 };

	snake[16] = { 19, 11 }; snake[17] = { 18, 11 };
	snake[18] = { 17, 11 }; snake[19] = { 16, 11 };
	snake[20] = { 15, 11 }; snake[21] = { 14, 11 };
	snake[22] = { 13, 11 }; snake[23] = { 12, 11 };

	snake[24] = { 11, 11 }; snake[25] = { 10, 11 };
	snake[26] = { 9, 11 }; snake[27] = { 8, 11 };
	snake[28] = { 7, 11 }; snake[29] = { 6, 11 };
	snake[30] = { 5, 11 }; snake[31] = { 4, 11 };
	GenerateFood(); // Create food array
}
