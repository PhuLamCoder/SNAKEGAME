/*
* Implementation of "Dead.h"
*/
#include "Dead.h"

bool ReachBodyLeft()
{
	int headX = snake[0].x - 1;
	int headY = snake[0].y;
	for (int i = 0; i < SIZE_SNAKE - 1; i++)
	{
		if (snake[i].x == headX && snake[i].y == headY)
			return true;
	}
	return false;
}
bool ReachBodyRight()
{
	int headX = snake[0].x + 1;
	int headY = snake[0].y;
	for (int i = 0; i < SIZE_SNAKE - 1; i++)
	{
		if (snake[i].x == headX && snake[i].y == headY)
			return true;
	}
	return false;
}
bool ReachBodyUp()
{
	int headX = snake[0].x;
	int headY = snake[0].y - 1;
	for (int i = 0; i < SIZE_SNAKE - 1; i++)
	{
		if (snake[i].x == headX && snake[i].y == headY)
			return true;
	}
	return false;
}
bool ReachBodyDown()
{
	int headX = snake[0].x;
	int headY = snake[0].y + 1;
	for (int i = 0; i < SIZE_SNAKE - 1; i++)
	{
		if (snake[i].x == headX && snake[i].y == headY)
			return true;
	}
	return false;
}


bool LeftDeadLevel1()
{   // Processing hit walls
	if (snake[0].x - 1 == 1)
		return true;
	if (LEVELUP == 1)
	{   // Processing hit the gate
		for (int i = 14; i < 17; i++)
		{
			if (snake[0].x - 1 == 68 && snake[0].y == i)
				return true;
		}

		for (int i = 12; i < 15; i++)
		{
			if (snake[0].x - 1 == 65 && snake[0].y == i)
				return true;

		}
		for (int i = 16; i < 19; i++)
		{
			if (snake[0].x - 1 == 65 && snake[0].y == i)
				return true;
		}
	}
	return false;
}
bool RightDeadLevel1()
{   // Processing hit walls
	if (snake[0].x + 1 == WIDTH_CONSOLE + 1)
		return true;
	if (LEVELUP == 1)
	{   // Processing hit the gate
		for (int i = 12; i < 15; i++)
		{
			if (snake[0].x + 1 == 65 && snake[0].y == i)
				return true;
		}
		for (int i = 16; i < 19; i++)
		{
			if (snake[0].x + 1 == 65 && snake[0].y == i)
				return true;
		}
	}
	return false;
}
bool UpDeadLevel1()
{   // Processing hit walls
	if (snake[0].y - 1 == 1)
		return true;
	if (LEVELUP == 1)
	{   // Processing hit the gate
		if (snake[0].y - 1 == 18 && snake[0].x == 65)
			return true;
		for (int i = 66; i < 69; i++)
		{
			if (snake[0].y - 1 == 16 && snake[0].x == i)
				return true;
			if (snake[0].y - 1 == 14 && snake[0].x == i)
				return true;
		}
	}
	return false;
}
bool DownDeadLevel1()
{   // Processing hit walls
	if (snake[0].y + 1 == HEIGH_CONSOLE + 1)
		return true;
	if (LEVELUP == 1)
	{   // Processing hit the gate
		if (snake[0].y + 1 == 12 && snake[0].x == 65)
			return true;
		if (snake[0].y + 1 == 16 && snake[0].x == 67)
			return true;
		for (int i = 66; i < 69; i++)
		{
			if (snake[0].y + 1 == 14 && snake[0].x == i)
				return true;
			if (snake[0].y + 1 == 16 && snake[0].x == i)
				return true;
		}
	}
	return false;
}


bool LeftDeadLevel2()
{   // Processing hit walls
	if (snake[0].x - 1 == 1)
		return true;
	for (int i = 7; i < 12; i++)
	{
		if (snake[0].x - 1 == 13 && snake[0].y == i)
			return true;
		if (snake[0].x - 1 == 14 && snake[0].y == i)
			return true;
	}
	for (int i = 6; i < 12; i++)
	{
		if (snake[0].x - 1 == 77 && snake[0].y == i)
			return true;
	}
	for (int i = 19; i < 24; i++)
	{
		if (snake[0].x - 1 == 13 && snake[0].y == i)
			return true;
		if (snake[0].x - 1 == 14 && snake[0].y == i)
			return true;
	}
	for (int i = 19; i < 25; i++)
	{
		if (snake[0].x - 1 == 77 && snake[0].y == i)
			return true;
	}
	if (snake[0].x - 1 == 29 && snake[0].y == 6)
		return true;
	if (snake[0].x - 1 == 29 && snake[0].y == 24)
		return true;
	for (int i = 15; i < 17; i++)
	{
		if (snake[0].x - 1 == 47 && snake[0].y == i)
			return true;
	}
	if (snake[0].x - 1 == 48 && snake[0].y == 17)
		return true;
	if (snake[0].x - 1 == 49 && snake[0].y == 18)
		return true;
	if (snake[0].x - 1 == 50 && snake[0].y == 19)
		return true;
	if (snake[0].x - 1 == 51 && snake[0].y == 20)
		return true;
	if (snake[0].x - 1 == 48 && snake[0].y == 14)
		return true;
	if (snake[0].x - 1 == 49 && snake[0].y == 13)
		return true;
	if (snake[0].x - 1 == 50 && snake[0].y == 12)
		return true;
	if (snake[0].x - 1 == 51 && snake[0].y == 11)
		return true;
	if (snake[0].x - 1 == 43 && snake[0].y == 17)
		return true;
	if (snake[0].x - 1 == 42 && snake[0].y == 18)
		return true;
	if (snake[0].x - 1 == 41 && snake[0].y == 19)
		return true;
	if (snake[0].x - 1 == 40 && snake[0].y == 20)
		return true;
	if (snake[0].x - 1 == 43 && snake[0].y == 14)
		return true;
	if (snake[0].x - 1 == 42 && snake[0].y == 13)
		return true;
	if (snake[0].x - 1 == 41 && snake[0].y == 12)
		return true;
	if (snake[0].x - 1 == 40 && snake[0].y == 11)
		return true;
	if (LEVELUP == 1)
	{   // Processing hit the gate
		for (int i = 14; i < 17; i++)
		{
			if (snake[0].x - 1 == 88 && snake[0].y == i)
				return true;
		}

		for (int i = 12; i < 15; i++)
		{
			if (snake[0].x - 1 == 85 && snake[0].y == i)
				return true;

		}
		for (int i = 16; i < 19; i++)
		{
			if (snake[0].x - 1 == 85 && snake[0].y == i)
				return true;
		}
	}
	return false;
}
bool RightDeadLevel2()
{   // Processing hit walls
	if (snake[0].x + 1 == WIDTH_CONSOLE + 1)
		return true;
	for (int i = 6; i < 12; i++)
	{
		if (snake[0].x + 1 == 13 && snake[0].y == i)
			return true;
	}
	for (int i = 19; i < 25; i++)
	{
		if (snake[0].x + 1 == 13 && snake[0].y == i)
			return true;
	}
	for (int i = 7; i < 12; i++)
	{
		if (snake[0].x + 1 == 77 && snake[0].y == i)
			return true;
		if (snake[0].x + 1 == 76 && snake[0].y == i)
			return true;
	}
	for (int i = 19; i < 24; i++)
	{
		if (snake[0].x + 1 == 77 && snake[0].y == i)
			return true;
		if (snake[0].x + 1 == 76 && snake[0].y == i)
			return true;
	}
	if (snake[0].x + 1 == 60 && snake[0].y == 6)
		return true;
	if (snake[0].x + 1 == 60 && snake[0].y == 24)
		return true;
	for (int i = 15; i < 17; i++)
	{
		if (snake[0].x + 1 == 44 && snake[0].y == i)
			return true;
	}
	if (snake[0].x + 1 == 43 && snake[0].y == 14)
		return true;
	if (snake[0].x + 1 == 42 && snake[0].y == 13)
		return true;
	if (snake[0].x + 1 == 41 && snake[0].y == 12)
		return true;
	if (snake[0].x + 1 == 40 && snake[0].y == 11)
		return true;
	if (snake[0].x + 1 == 43 && snake[0].y == 17)
		return true;
	if (snake[0].x + 1 == 42 && snake[0].y == 18)
		return true;
	if (snake[0].x + 1 == 41 && snake[0].y == 19)
		return true;
	if (snake[0].x + 1 == 40 && snake[0].y == 20)
		return true;
	if (snake[0].x + 1 == 48 && snake[0].y == 14)
		return true;
	if (snake[0].x + 1 == 49 && snake[0].y == 13)
		return true;
	if (snake[0].x + 1 == 50 && snake[0].y == 12)
		return true;
	if (snake[0].x + 1 == 51 && snake[0].y == 11)
		return true;
	if (snake[0].x + 1 == 48 && snake[0].y == 17)
		return true;
	if (snake[0].x + 1 == 49 && snake[0].y == 18)
		return true;
	if (snake[0].x + 1 == 50 && snake[0].y == 19)
		return true;
	if (snake[0].x + 1 == 51 && snake[0].y == 20)
		return true;
	if (LEVELUP == 1)
	{   // Processing hit the gate
		for (int i = 12; i < 15; i++)
		{
			if (snake[0].x + 1 == 85 && snake[0].y == i)
				return true;
		}
		for (int i = 16; i < 19; i++)
		{
			if (snake[0].x + 1 == 85 && snake[0].y == i)
				return true;
		}
	}
	return false;
}
bool UpDeadLevel2()
{   // Processing hit walls
	if (snake[0].y - 1 == 1)
		return true;
	for (int i = 14; i < 30; i++)
	{
		if (snake[0].y - 1 == 6 && snake[0].x == i)
			return true;
	}
	for (int i = 60; i < 78; i++)
	{
		if (snake[0].y - 1 == 6 && snake[0].x == i)
			return true;
	}
	for (int i = 60; i < 78; i++)
	{
		if (snake[0].y - 1 == 24 && snake[0].x == i)
			return true;
	}
	for (int i = 13; i < 30; i++)
	{
		if (snake[0].y - 1 == 24 && snake[0].x == i)
			return true;
	}
	if (snake[0].y - 1 == 11 && snake[0].x == 13)
		return true;
	if (snake[0].y - 1 == 11 && snake[0].x == 14)
		return true;
	if (snake[0].y - 1 == 11 && snake[0].x == 77)
		return true;
	if (snake[0].y - 1 == 11 && snake[0].x == 76)
		return true;
	for (int i = 44; i < 48; i++)
	{
		if (snake[0].y - 1 == 16 && snake[0].x == i)
			return true;
	}
	if (snake[0].y - 1 == 17 && snake[0].x == 43)
		return true;
	if (snake[0].y - 1 == 18 && snake[0].x == 42)
		return true;
	if (snake[0].y - 1 == 19 && snake[0].x == 41)
		return true;
	if (snake[0].y - 1 == 20 && snake[0].x == 40)
		return true;
	if (snake[0].y - 1 == 14 && snake[0].x == 43)
		return true;
	if (snake[0].y - 1 == 13 && snake[0].x == 42)
		return true;
	if (snake[0].y - 1 == 12 && snake[0].x == 41)
		return true;
	if (snake[0].y - 1 == 11 && snake[0].x == 40)
		return true;
	if (snake[0].y - 1 == 17 && snake[0].x == 48)
		return true;
	if (snake[0].y - 1 == 18 && snake[0].x == 49)
		return true;
	if (snake[0].y - 1 == 19 && snake[0].x == 50)
		return true;
	if (snake[0].y - 1 == 20 && snake[0].x == 51)
		return true;
	if (snake[0].y - 1 == 14 && snake[0].x == 48)
		return true;
	if (snake[0].y - 1 == 13 && snake[0].x == 49)
		return true;
	if (snake[0].y - 1 == 12 && snake[0].x == 50)
		return true;
	if (snake[0].y - 1 == 11 && snake[0].x == 51)
		return true;
	if (LEVELUP == 1)
	{   // Processing hit the gate
		if (snake[0].y - 1 == 18 && snake[0].x == 85)
			return true;
		for (int i = 86; i < 89; i++)
		{
			if (snake[0].y - 1 == 16 && snake[0].x == i)
				return true;
			if (snake[0].y - 1 == 14 && snake[0].x == i)
				return true;
		}
	}
	return false;
}
bool DownDeadLevel2()
{   // Processing hit walls
	if (snake[0].y + 1 == HEIGH_CONSOLE + 1)
		return true;
	for (int i = 13; i <= 29; i++)
	{
		if (snake[0].y + 1 == 6 && snake[0].x == i)
			return true;
	}
	for (int i = 60; i < 78; i++)
	{
		if (snake[0].y + 1 == 6 && snake[0].x == i)
			return true;
	}
	for (int i = 60; i < 78; i++)
	{
		if (snake[0].y + 1 == 24 && snake[0].x == i)
			return true;
	}
	for (int i = 13; i <= 29; i++)
	{
		if (snake[0].y + 1 == 24 && snake[0].x == i)
			return true;
	}
	for (int i = 44; i < 48; i++)
	{
		if (snake[0].y + 1 == 15 && snake[0].x == i)
			return true;
	}
	if (snake[0].y + 1 == 19 && snake[0].x == 13)
		return true;
	if (snake[0].y + 1 == 19 && snake[0].x == 14)
		return true;
	if (snake[0].y + 1 == 19 && snake[0].x == 77)
		return true;
	if (snake[0].y + 1 == 19 && snake[0].x == 76)
		return true;
	if (snake[0].y + 1 == 17 && snake[0].x == 43)
		return true;
	if (snake[0].y + 1 == 18 && snake[0].x == 42)
		return true;
	if (snake[0].y + 1 == 19 && snake[0].x == 41)
		return true;
	if (snake[0].y + 1 == 20 && snake[0].x == 40)
		return true;
	if (snake[0].y + 1 == 14 && snake[0].x == 43)
		return true;
	if (snake[0].y + 1 == 13 && snake[0].x == 42)
		return true;
	if (snake[0].y + 1 == 12 && snake[0].x == 41)
		return true;
	if (snake[0].y + 1 == 11 && snake[0].x == 40)
		return true;
	if (snake[0].y + 1 == 17 && snake[0].x == 48)
		return true;
	if (snake[0].y + 1 == 18 && snake[0].x == 49)
		return true;
	if (snake[0].y + 1 == 19 && snake[0].x == 50)
		return true;
	if (snake[0].y + 1 == 20 && snake[0].x == 51)
		return true;
	if (snake[0].y + 1 == 14 && snake[0].x == 48)
		return true;
	if (snake[0].y + 1 == 13 && snake[0].x == 49)
		return true;
	if (snake[0].y + 1 == 12 && snake[0].x == 50)
		return true;
	if (snake[0].y + 1 == 11 && snake[0].x == 51)
		return true;
	if (LEVELUP == 1)
	{   // Processing hit the gate
		if (snake[0].y + 1 == 12 && snake[0].x == 85)
			return true;
		if (snake[0].y + 1 == 16 && snake[0].x == 87)
			return true;
		for (int i = 86; i < 89; i++)
		{
			if (snake[0].y + 1 == 14 && snake[0].x == i)
				return true;
			if (snake[0].y + 1 == 16 && snake[0].x == i)
				return true;
		}
	}
	return false;
}


bool LeftDeadLevel3()
{   // Processing hit walls
	if (snake[0].x - 1 == 1)
		return true;
	for (int i = 6; i <= 11; i++)
	{
		if (snake[0].x - 1 == 41 && snake[0].y == i || snake[0].x - 1 == 53 && snake[0].y == i || snake[0].x - 1 == 82 && snake[0].y == i)
			return true;
	}
	for (int i = 7; i <= 12; i++)
	{
		if (snake[0].x - 1 == 12 && snake[0].y == i)
			return true;
	}
	if (snake[0].x - 1 == 22 && snake[0].y == 6 || snake[0].x - 1 == 41 && snake[0].y == 12 || snake[0].x - 1 == 63 && snake[0].y == 12 || snake[0].x - 1 == 82 && snake[0].y == 12)
	{
		return true;
	}
	for (int i = 17; i <= 22; i++)
	{
		if (snake[0].x - 1 == 41 && snake[0].y == i || snake[0].x - 1 == 53 && snake[0].y == i || snake[0].x - 1 == 82 && snake[0].y == i)
			return true;
	}
	for (int i = 16; i <= 21; i++)
	{
		if (snake[0].x - 1 == 12 && snake[0].y == i)
			return true;
	}
	if (snake[0].x - 1 == 41 && snake[0].y == 16 || snake[0].x - 1 == 63 && snake[0].y == 16 || snake[0].x - 1 == 82 && snake[0].y == 16 || snake[0].x - 1 == 22 && snake[0].y == 22)
	{
		return true;
	}
	if (LEVELUP == 1)
	{   // Processing hit the gate
		for (int i = 21; i < 24; i++)
		{
			if (snake[0].x - 1 == 87 && snake[0].y == i)
				return true;

		}
	}
	return false;
}
bool RightDeadLevel3()
{   // Processing hit walls
	if (snake[0].x + 1 == WIDTH_CONSOLE + 1)
		return true;
	for (int i = 6; i <= 11; i++)
	{
		if (snake[0].x + 1 == 11 && snake[0].y == i || snake[0].x + 1 == 40 && snake[0].y == i || snake[0].x + 1 == 52 && snake[0].y == i)
			return true;
	}
	for (int i = 7; i <= 12; i++)
	{
		if (snake[0].x + 1 == 81 && snake[0].y == i)
			return true;
	}
	if (snake[0].x + 1 == 11 && snake[0].y == 12 || snake[0].x + 1 == 30 && snake[0].y == 12 || snake[0].x + 1 == 52 && snake[0].y == 12 || snake[0].x + 1 == 71 && snake[0].y == 6)
	{
		return true;
	}
	for (int i = 17; i <= 22; i++)
	{
		if (snake[0].x + 1 == 11 && snake[0].y == i || snake[0].x + 1 == 40 && snake[0].y == i || snake[0].x + 1 == 52 && snake[0].y == i)
			return true;
	}
	for (int i = 16; i <= 21; i++)
	{
		if (snake[0].x + 1 == 81 && snake[0].y == i)
			return true;
	}
	if (snake[0].x + 1 == 11 && snake[0].y == 16 || snake[0].x + 1 == 30 && snake[0].y == 16 || snake[0].x + 1 == 52 && snake[0].y == 16 || snake[0].x + 1 == 71 && snake[0].y == 22)
	{
		return true;
	}
	if (LEVELUP == 1)
	{   // Processing hit the gate
		for (int i = 21; i < 24; i++)
		{
			if (snake[0].x + 1 == 87 && snake[0].y == i)
				return true;
		}
		for (int i = 25; i < 28; i++)
		{
			if (snake[0].x + 1 == 87 && snake[0].y == i)
				return true;
		}
	}
	return false;
}
bool UpDeadLevel3()
{   // Processing hit walls
	if (snake[0].y - 1 == 1)
		return true;
	for (int i = 13; i <= 22; i++)
	{
		if (snake[0].x == i && snake[0].y - 1 == 6)
			return true;
	}
	for (int i = 30; i <= 41; i++)
	{
		if (snake[0].x == i && snake[0].y - 1 == 12)
			return true;
	}
	for (int i = 52; i <= 63; i++)
	{
		if (snake[0].x == i && snake[0].y - 1 == 12)
			return true;
	}
	for (int i = 71; i <= 80; i++)
	{
		if (snake[0].x == i && snake[0].y - 1 == 6)
			return true;
	}
	if (snake[0].x == 11 && snake[0].y - 1 == 12 || snake[0].x == 12 && snake[0].y - 1 == 12 || snake[0].x == 81 && snake[0].y - 1 == 12 || snake[0].x == 82 && snake[0].y - 1 == 12)
	{
		return true;
	}
	for (int i = 11; i <= 22; i++)
	{
		if (snake[0].x == i && snake[0].y - 1 == 22)
			return true;
	}
	for (int i = 30; i <= 39; i++)
	{
		if (snake[0].x == i && snake[0].y - 1 == 16)
			return true;
	}
	for (int i = 54; i <= 63; i++)
	{
		if (snake[0].x == i && snake[0].y - 1 == 16)
			return true;
	}
	for (int i = 71; i <= 82; i++)
	{
		if (snake[0].x == i && snake[0].y - 1 == 22)
			return true;
	}
	if (snake[0].x == 40 && snake[0].y - 1 == 22 || snake[0].x == 41 && snake[0].y - 1 == 22 || snake[0].x == 52 && snake[0].y - 1 == 22 || snake[0].x == 53 && snake[0].y - 1 == 22)
	{
		return true;
	}
	if (LEVELUP == 1)
	{   // Processing hit the gate
		for (int i = 88; i < 91; i++)
		{
			if (snake[0].y - 1 == 23 && snake[0].x == i)
				return true;
		}
	}
	return false;
}
bool DownDeadLevel3()
{   // Processing hit walls
	if (snake[0].y + 1 == HEIGH_CONSOLE + 1)
		return true;
	for (int i = 11; i <= 22; i++)
	{
		if (snake[0].x == i && snake[0].y + 1 == 6)
			return true;
	}
	for (int i = 30; i <= 39; i++)
	{
		if (snake[0].x == i && snake[0].y + 1 == 12)
			return true;
	}
	for (int i = 54; i <= 63; i++)
	{
		if (snake[0].x == i && snake[0].y + 1 == 12)
			return true;
	}
	for (int i = 71; i <= 82; i++)
	{
		if (snake[0].x == i && snake[0].y + 1 == 6)
			return true;
	}
	if (snake[0].x == 40 && snake[0].y + 1 == 6 || snake[0].x == 41 && snake[0].y + 1 == 6 || snake[0].x == 52 && snake[0].y + 1 == 6 || snake[0].x == 53 && snake[0].y + 1 == 6)
	{
		return true;
	}
	for (int i = 13; i <= 22; i++)
	{
		if (snake[0].x == i && snake[0].y + 1 == 22)
			return true;
	}
	for (int i = 30; i <= 41; i++)
	{
		if (snake[0].x == i && snake[0].y + 1 == 16)
			return true;
	}
	for (int i = 52; i <= 63; i++)
	{
		if (snake[0].x == i && snake[0].y + 1 == 16)
			return true;
	}
	for (int i = 71; i <= 80; i++)
	{
		if (snake[0].x == i && snake[0].y + 1 == 22)
			return true;
	}
	if (snake[0].x == 11 && snake[0].y + 1 == 16 || snake[0].x == 12 && snake[0].y + 1 == 16 || snake[0].x == 81 && snake[0].y + 1 == 16 || snake[0].x == 82 && snake[0].y + 1 == 16)
	{
		return true;
	}
	if (LEVELUP == 1)
	{   // Processing hit the gate
		if (snake[0].y + 1 == 21 && snake[0].x == 87)
			return true;
		if (snake[0].y + 1 == 25 && snake[0].x == 87)
			return true;
		for (int i = 88; i < 91; i++)
		{
			if (snake[0].y + 1 == 23 && snake[0].x == i)
				return true;
			if (snake[0].y + 1 == 25 && snake[0].x == i)
				return true;
		}
	}
	return false;
}


bool LeftDeadLevel4()
{   // Processing hit walls
	if (snake[0].x - 1 == 1)
		return true;
	if (snake[0].x - 1 == 63 && snake[0].y == 4)
		return true;
	if (snake[0].x - 1 == 63 && snake[0].y == 25)
		return true;
	if (snake[0].x - 1 == 84 && snake[0].y == 8)
		return true;
	if (snake[0].x - 1 == 84 && snake[0].y == 21)
		return true;
	for (int j = 4; j <= 8; j++)
	{
		if (snake[0].x - 1 == 22 && snake[0].y == j)
			return true;
		if (snake[0].x - 1 == 71 && snake[0].y == j)
			return true;
	}
	for (int j = 4; j <= 5; j++)
	{
		if (snake[0].x - 1 == 37 && snake[0].y == j)
			return true;
		if (snake[0].x - 1 == 56 && snake[0].y == j)
			return true;
	}
	for (int j = 21; j <= 25; j++)
	{
		if (snake[0].x - 1 == 22 && snake[0].y == j)
			return true;
		if (snake[0].x - 1 == 71 && snake[0].y == j)
			return true;
	}
	for (int j = 23; j <= 25; j++)
	{
		if (snake[0].x - 1 == 37 && snake[0].y == j)
			return true;
		if (snake[0].x - 1 == 56 && snake[0].y == j)
			return true;
	}
	if (snake[0].x - 1 == 48 && snake[0].y == 14)
		return true;
	if (snake[0].x - 1 == 48 && snake[0].y == 16)
		return true;
	if (snake[0].x - 1 == 54 && snake[0].y == 15)
		return true;
	if (LEVELUP == 1)
	{   // Processing hit the gate
		for (int i = 6; i < 9; i++)
		{
			if (snake[0].x - 1 == 87 && snake[0].y == i)
				return true;

		}
	}
	return false;
}
bool RightDeadLevel4()
{   // Processing hit walls
	if (snake[0].x + 1 == WIDTH_CONSOLE + 1)
		return true;
	if (snake[0].x + 1 == 8 && snake[0].y == 8)
		return true;
	if (snake[0].x + 1 == 8 && snake[0].y == 21)
		return true;
	if (snake[0].x + 1 == 29 && snake[0].y == 4)
		return true;
	if (snake[0].x + 1 == 29 && snake[0].y == 25)
		return true;
	for (int j = 4; j <= 8; j++)
	{
		if (snake[0].x + 1 == 21 && snake[0].y == j)
			return true;
		if (snake[0].x + 1 == 70 && snake[0].y == j)
			return true;
	}
	for (int j = 4; j <= 5; j++)
	{
		if (snake[0].x + 1 == 36 && snake[0].y == j)
			return true;
		if (snake[0].x + 1 == 55 && snake[0].y == j)
			return true;
	}
	for (int j = 21; j <= 25; j++)
	{
		if (snake[0].x + 1 == 21 && snake[0].y == j)
			return true;
		if (snake[0].x + 1 == 70 && snake[0].y == j)
			return true;
	}
	for (int j = 23; j <= 25; j++)
	{
		if (snake[0].x + 1 == 36 && snake[0].y == j)
			return true;
		if (snake[0].x + 1 == 55 && snake[0].y == j)
			return true;
	}
	if (snake[0].x + 1 == 44 && snake[0].y == 14)
		return true;
	if (snake[0].x + 1 == 44 && snake[0].y == 16)
		return true;
	if (snake[0].x + 1 == 38 && snake[0].y == 15)
		return true;
	if (LEVELUP == 1)
	{   // Processing hit the gate
		for (int i = 2; i < 5; i++)
		{
			if (snake[0].x + 1 == 87 && snake[0].y == i)
				return true;
		}
		for (int i = 6; i < 9; i++)
		{
			if (snake[0].x + 1 == 87 && snake[0].y == i)
				return true;
		}
	}
	return false;
}
bool UpDeadLevel4()
{   // Processing hit walls
	if (snake[0].y - 1 == 1)
		return true;
	for (int i = 8; i <= 22; i++)
	{
		if (snake[0].y - 1 == 8 && snake[0].x == i)
			return true;
		if (snake[0].y - 1 == 21 && snake[0].x == i)
			return true;
	}
	for (int i = 29; i <= 37; i++)
	{
		if (snake[0].y - 1 == 4 && snake[0].x == i)
			return true;
		if (snake[0].y - 1 == 25 && snake[0].x == i)
			return true;
	}
	for (int i = 36; i <= 56; i++)
	{
		if (snake[0].y - 1 == 6 && snake[0].x == i)
			return true;
		if (snake[0].y - 1 == 23 && snake[0].x == i)
			return true;
	}
	for (int i = 55; i <= 63; i++)
	{
		if (snake[0].y - 1 == 4 && snake[0].x == i)
			return true;
		if (snake[0].y - 1 == 25 && snake[0].x == i)
			return true;
	}
	for (int i = 70; i <= 84; i++)
	{
		if (snake[0].y - 1 == 8 && snake[0].x == i)
			return true;
		if (snake[0].y - 1 == 21 && snake[0].x == i)
			return true;
	}
	for (int i = 44; i <= 45; i++)
	{
		if (snake[0].y - 1 == 16 && snake[0].x == i)
			return true;
	}
	for (int i = 47; i <= 48; i++)
	{
		if (snake[0].y - 1 == 16 && snake[0].x == i)
			return true;
	}
	for (int i = 38; i <= 54; i++)
	{
		if (snake[0].y - 1 == 15 && snake[0].x == i)
			return true;
	}
	if (LEVELUP == 1)
	{   // Processing hit the gate
		for (int i = 88; i < 91; i++)
		{
			if (snake[0].y - 1 == 6 && snake[0].x == i)
				return true;
			if (snake[0].y - 1 == 4 && snake[0].x == i)
				return true;
		}
		if (snake[0].y - 1 == 8 && snake[0].x == 87)
			return true;
	}
	return false;
}
bool DownDeadLevel4()
{   // Processing hit walls
	if (snake[0].y + 1 == HEIGH_CONSOLE + 1)
		return true;
	for (int i = 8; i <= 22; i++)
	{
		if (snake[0].y + 1 == 8 && snake[0].x == i)
			return true;
		if (snake[0].y + 1 == 21 && snake[0].x == i)
			return true;
	}
	for (int i = 29; i <= 37; i++)
	{
		if (snake[0].y + 1 == 4 && snake[0].x == i)
			return true;
		if (snake[0].y + 1 == 25 && snake[0].x == i)
			return true;
	}
	for (int i = 36; i <= 56; i++)
	{
		if (snake[0].y + 1 == 6 && snake[0].x == i)
			return true;
		if (snake[0].y + 1 == 23 && snake[0].x == i)
			return true;
	}
	for (int i = 55; i <= 63; i++)
	{
		if (snake[0].y + 1 == 4 && snake[0].x == i)
			return true;
		if (snake[0].y + 1 == 25 && snake[0].x == i)
			return true;
	}
	for (int i = 70; i <= 84; i++)
	{
		if (snake[0].y + 1 == 8 && snake[0].x == i)
			return true;
		if (snake[0].y + 1 == 21 && snake[0].x == i)
			return true;
	}
	for (int i = 44; i <= 45; i++)
	{
		if (snake[0].y + 1 == 14 && snake[0].x == i)
			return true;
	}
	for (int i = 47; i <= 48; i++)
	{
		if (snake[0].y + 1 == 14 && snake[0].x == i)
			return true;
	}
	for (int i = 38; i <= 54; i++)
	{
		if (snake[0].y + 1 == 15 && snake[0].x == i)
			return true;
	}
	if (LEVELUP == 1)
	{   // Processing hit the gate
		for (int i = 88; i < 91; i++)
		{
			if (snake[0].y + 1 == 6 && snake[0].x == i)
				return true;
		}
	}
	return false;
}