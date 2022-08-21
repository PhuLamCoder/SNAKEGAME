/*
* Implementation of "Draw.h"
*/
#include "Draw.h"

void DrawBoard(int x, int y, int width, int height, int curPosX, int curPosY)
{
	char a = 223;
	char b = 220;
	char c = 219;
	GotoXY(x, y); cout << b;
	for (int i = 1; i < width; i++)
		cout << b;
	cout << b;
	GotoXY(x, height + y); cout << a;
	for (int i = 1; i < width; i++)
		cout << a;
	cout << a;
	for (int i = y + 1; i < height + y; i++)
	{
		GotoXY(x, i); cout << c;
		GotoXY(x + width, i); cout << c;
	}

	GotoXY(x + width + 2, y);
	for (int i = 0; i < 30; i++)
		cout << b;
	GotoXY(x + width + 2, y + height);
	for (int i = 0; i < 30; i++)
		cout << a;
	for (int i = 1; i < height; i++)
	{
		GotoXY(x + width + 2, y + i);
		cout << c << "                            " << c;
	}
	GotoXY(curPosX, curPosY);
}
void SmallBoard()
{
	SetColor(14);
	GotoXY(95, 4); printf("                     ____");
	GotoXY(95, 5); printf("_______  _  .    .  |__ /");
	GotoXY(95, 6); printf(" |  |__ /_\\ |\\  /|   |_ \\");
	GotoXY(95, 7); printf(" |  |__/   \\| \\/ |  |___/");
	GotoXY(95, 8); printf("                  _|\"\"\"\"\"|");
	GotoXY(95, 9); printf("                  \"`-0-0-`");
	SetColor(13);
	GotoXY(98, 11); printf("----- LEVEL %d -----", LEVEL);
	SetColor(11);
	if (start_char == 0 && LEVELUP != 2)
	{
		GotoXY(101, 13); printf("   Size:  %d", SIZE_SNAKE);
	}
	GotoXY(101, 14); printf("   Score: %d", SCORE);
	SetColor(8);
	GotoXY(101, 16); printf("P : Pause Game");
	GotoXY(101, 17); printf("T : Save Game");
	GotoXY(101, 18); printf("L : Load Game");
	GotoXY(101, 19); printf("W : Move Up");
	GotoXY(101, 20); printf("S : Move Down");
	GotoXY(101, 21); printf("A : Move Left");
	GotoXY(101, 22); printf("D : Move Right");
}

void DrawSnakeAndFood(const char str, int start_char)
{
	if (STATE == 0) return;
	SetColor(SNAKE_COLOR);
	if (SIZE_SNAKE != 40 && food[FOOD_INDEX].x != 0 && STATE == 1)
	{
		GotoXY(food[FOOD_INDEX].x, food[FOOD_INDEX].y);
		cout << str;
	}
	for (int i = 0; i < SIZE_SNAKE; i++)
	{
		GotoXY(snake[i].x, snake[i].y);
		if (str != ' ')
			cout << Snake_Body[i + start_char];
		else
			cout << str;
	}
}

void DrawWallLevel2()
{
	char a = 220, b = 223, c = 177, e = 219;
	for (int i = 13; i < 30; i++)
	{
		GotoXY(i, 6);
		cout << e;
	}
	for (int i = 7; i < 12; i++)
	{
		GotoXY(13, i);
		cout << e;
		GotoXY(14, i);
		cout << e;
	}
	for (int i = 19; i <= 24; i++)
	{
		GotoXY(13, i);
		cout << e;
		GotoXY(14, i);
		cout << e;
	}
	for (int i = 14; i < 30; i++)
	{
		GotoXY(i, 24);
		cout << e;
	}
	for (int i = 60; i <= 77; i++)
	{
		GotoXY(i, 6);
		cout << e;
		GotoXY(i, 24);
		cout << e;
	}
	for (int i = 7; i < 12; i++)
	{
		GotoXY(77, i);
		cout << e;
		GotoXY(76, i);
		cout << e;
	}


	for (int i = 19; i <= 24; i++)
	{
		GotoXY(77, i);
		cout << e;
	}
	for (int i = 19; i <= 24; i++)
	{
		GotoXY(76, i);
		cout << e;
	}
	for (int i = 44; i <= 47; i++)
	{
		GotoXY(i, 15);
		cout << e;
	}
	for (int i = 44; i <= 47; i++)
	{
		GotoXY(i, 16);
		cout << e;
	}
	GotoXY(48, 14);
	cout << e;
	GotoXY(49, 13);
	cout << e;
	GotoXY(50, 12);
	cout << e;
	GotoXY(51, 11);
	cout << e;
	GotoXY(48, 17);
	cout << e;
	GotoXY(49, 18);
	cout << e;
	GotoXY(50, 19);
	cout << e;
	GotoXY(51, 20);
	cout << e;
	GotoXY(43, 17);
	cout << e;
	GotoXY(42, 18);
	cout << e;
	GotoXY(41, 19);
	cout << e;
	GotoXY(40, 20);
	cout << e;
	GotoXY(43, 14);
	cout << e;
	GotoXY(42, 13);
	cout << e;
	GotoXY(41, 12);
	cout << e;
	GotoXY(40, 11);
	cout << e;
}
void DrawWallLevel3()
{
	char c = 219;
	for (int i = 11; i <= 22; i++)
	{
		GotoXY(i, 6);
		cout << c;
		GotoXY(i, 22);
		cout << c;
	}
	for (int i = 30; i <= 40; i++)
	{
		GotoXY(i, 12);
		cout << c;
		GotoXY(i, 16);
		cout << c;
	}
	for (int i = 53; i <= 63; i++)
	{
		GotoXY(i, 12);
		cout << c;
		GotoXY(i, 16);
		cout << c;
	}
	for (int i = 71; i <= 82; i++)
	{
		GotoXY(i, 6);
		cout << c;
		GotoXY(i, 22);
		cout << c;
	}
	for (int i = 6; i <= 12; i++)
	{
		GotoXY(40, i);
		cout << c;
		GotoXY(41, i);
		cout << c;
		GotoXY(52, i);
		cout << c;
		GotoXY(53, i);
		cout << c;
	}
	for (int i = 7; i <= 12; i++)
	{
		GotoXY(11, i);
		cout << c;
		GotoXY(12, i);
		cout << c;
		GotoXY(81, i);
		cout << c;
		GotoXY(82, i);
		cout << c;
	}
	for (int i = 16; i <= 21; i++)
	{
		GotoXY(11, i);
		cout << c;
		GotoXY(12, i);
		cout << c;
		GotoXY(81, i);
		cout << c;
		GotoXY(82, i);
		cout << c;
	}
	for (int i = 16; i <= 22; i++)
	{
		GotoXY(40, i);
		cout << c;
		GotoXY(41, i);
		cout << c;
		GotoXY(52, i);
		cout << c;
		GotoXY(53, i);
		cout << c;
	}
}
void DrawWallLevel4()
{
	char b = 219;
	SetColor(2);
	//Draw  4 corner walls
	for (int i = 8; i <= 22; i++)
	{
		GotoXY(i, 8);
		cout << b;
		GotoXY(i, 21);
		cout << b;
	}
	for (int i = 70; i <= 84; i++)
	{
		GotoXY(i, 8);
		cout << b;
		GotoXY(i, 21);
		cout << b;
	}
	for (int j = 4; j <= 8; j++)
	{
		GotoXY(22, j);
		cout << b;
		GotoXY(70, j);
		cout << b;
		GotoXY(21, j);
		cout << b;
		GotoXY(71, j);
		cout << b;
	}
	for (int j = 21; j <= 25; j++)
	{
		GotoXY(22, j);
		cout << b;
		GotoXY(70, j);
		cout << b;
		GotoXY(21, j);
		cout << b;
		GotoXY(71, j);
		cout << b;
	}
	//Draw wall in the middle
	for (int i = 38; i <= 54; i++)
	{
		GotoXY(i, 15);
		cout << b;
	}
	for (int j = 14; j <= 16; j++)
	{
		GotoXY(45, j);
		cout << b;
		GotoXY(47, j);
		cout << b;
		GotoXY(44, j);
		cout << b;
		GotoXY(48, j);
		cout << b;
	}
	//Draw wall on the top and the bottom
	for (int i = 29; i <= 36; i++)
	{
		GotoXY(i, 4);
		cout << b;
		GotoXY(i, 25);
		cout << b;
	}
	for (int i = 36; i <= 56; i++)
	{
		GotoXY(i, 6);
		cout << b;
		GotoXY(i, 23);
		cout << b;
	}
	for (int i = 56; i <= 63; i++)
	{
		GotoXY(i, 4);
		cout << b;
		GotoXY(i, 25);
		cout << b;
	}
	for (int j = 23; j <= 25; j++)
	{
		GotoXY(36, j);
		cout << b;
		GotoXY(56, j);
		cout << b;
		GotoXY(37, j);
		cout << b;
		GotoXY(55, j);
		cout << b;
	}
	for (int j = 4; j <= 6; j++)
	{
		GotoXY(36, j);
		cout << b;
		GotoXY(56, j);
		cout << b;
		GotoXY(37, j);
		cout << b;
		GotoXY(55, j);
		cout << b;
	}
}


void DrawGateLv1()
{
	char e = 219;
	for (int i = 12; i < 15; i++)
	{
		GotoXY(65, i);
		cout << e;
	}
	for (int i = 16; i < 19; i++)
	{
		GotoXY(65, i);
		cout << e;
	}

	for (int i = 66; i < 69; i++)
	{
		GotoXY(i, 14);
		cout << e;
	}
	for (int i = 66; i < 69; i++)
	{
		GotoXY(i, 16);
		cout << e;
	}
	GotoXY(68, 15);
	cout << e;
}
void DrawGateLv2()
{
	char e = 219;
	GotoXY(85, 12);
	cout << e;
	GotoXY(85, 13);
	cout << e;
	GotoXY(85, 17);
	cout << e;
	GotoXY(85, 14);
	cout << e;
	GotoXY(85, 16);
	cout << e;
	GotoXY(85, 18);
	cout << e;
	for (int i = 86; i < 89; i++)
	{
		GotoXY(i, 14);
		cout << e;
	}
	for (int i = 86; i < 89; i++)
	{
		GotoXY(i, 16);
		cout << e;
	}
	GotoXY(88, 15);
	cout << e;
}
void DrawGateLv3()
{
	char e = 219;
	for (int i = 21; i < 24; i++)
	{
		GotoXY(87, i);
		cout << e;
	}
	for (int i = 25; i < 28; i++)
	{
		GotoXY(87, i);
		cout << e;
	}
	for (int i = 88; i < 91; i++)
	{
		GotoXY(i, 23);
		cout << e;
	}
	for (int i = 88; i < 91; i++)
	{
		GotoXY(i, 25);
		cout << e;
	}
	GotoXY(90, 24);
	cout << e;
}
void DrawGateLv4()
{
	char e = 219;
	for (int i = 2; i < 5; i++)
	{
		GotoXY(87, i);
		cout << e;
	}
	for (int i = 6; i < 9; i++)
	{
		GotoXY(87, i);
		cout << e;
	}
	for (int i = 88; i < 91; i++)
	{
		GotoXY(i, 4);
		cout << e;
	}
	for (int i = 88; i < 91; i++)
	{
		GotoXY(i, 6);
		cout << e;
	}
	GotoXY(90, 5);
	cout << e;
}


void DrawContinueGame()
{
	system("cls");
	SetColor(2);
	DrawBoard(1, 1, WIDTH_CONSOLE, HEIGH_CONSOLE);
	SmallBoard();
	SetColor(2);
	switch (LEVEL)
	{
	case 2:
		DrawWallLevel2();
		break;
	case 3:
		DrawWallLevel3();
		break;
	case 4:
		DrawWallLevel4();
		break;
	}
	if (LEVELUP == 1)
	{
		SetColor(3);
		if (LEVEL == 1)
			DrawGateLv1();
		else if (LEVEL == 2)
			DrawGateLv2();
		else if (LEVEL == 3)
			DrawGateLv3();
		else if (LEVEL == 4)
			DrawGateLv4();
	}
	DrawSnakeAndFood(3);
}