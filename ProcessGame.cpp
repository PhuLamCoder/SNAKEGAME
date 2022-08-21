/*
* Implementation of "ProcessGame.h"
*/
#include "ProcessGame.h"
	
#pragma comment(lib, "winmm.lib")

void StartGame()
{
	system("cls");
	SetColor(2);
	// Intialize original data
	if (LEVEL == 1)
	{
		ResetDataLV1();
	}
	else if (LEVEL == 2)
	{
		ResetDataLV2();
		DrawWallLevel2();
	}
	else if (LEVEL == 3)
	{
		ResetDataLV3();
		DrawWallLevel3();
	}
	else if (LEVEL == 4)
	{
		ResetDataLV4();
		DrawWallLevel4();
	}
	DrawBoard(1, 1, WIDTH_CONSOLE, HEIGH_CONSOLE); // Draw game
	GenerateFood();
	STATE = 1; // Start running Thread
	LEVELUP = 0; // Not levelup when starting new
}


void PauseGame(HANDLE t)
{
	SuspendThread(t);
}

bool ExistFileName(const char* namesaved, const char* filename)
{
	FILE* file;
	fopen_s(&file, namesaved, "rt");
	char str[50];
	if (file != NULL)
	{
		while (!feof(file))
		{
			fgets(str, 50, file);
			str[strlen(str) - 1] = '\0';
			if (strcmp(str, filename) == 0)
				return true;
		}
		fclose(file);
	}
	return false;
}


void SaveGame()
{   // Draw the save game screen
	system("cls");
	SetColor(3);
	DrawBoard(1, 1, WIDTH_CONSOLE, HEIGH_CONSOLE);
	SmallBoard();
	SetColor(11);
	GotoXY(20, 4);
	for (int i = 0; i < 53; i++)
		cout << (char)196;
	GotoXY(20, 6);
	for (int i = 0; i < 53; i++)
		cout << (char)196;
	for (int i = 0; i < 20; i++)
	{
		GotoXY(45, 4 + i);
		cout << (char)179;
	}
	SetColor(14);
	GotoXY(20, 5);
	cout << "     YOUR SAVED GAME " << (char)2;
	GotoXY(46, 5);
	cout << "    ENTER NAME TO SAVE " << (char)1;
	GotoXY(46, 7);
	cout << "     Enter file name: ";
	// Print the filenames were saved
	FILE* file;
	fopen_s(&file, "namesaved.txt", "rt");
	char str[50];
	if (file != NULL)
	{
		fgets(str, 50, file);
		int i = 0;
		while (!feof(file))
		{
			GotoXY(29, 8 + i++);
			cout << str;
			fgets(str, 255, file);
		}
		fclose(file);
	}
	// Save the playing game
	GotoXY(51, 9);
	ShowCur(1);
	gets_s(str);
	if (SOUND)
		PlaySound(L"enter.wav", NULL, SND_ASYNC);
	// Not write the filename if it already exists
	if (!ExistFileName("namesaved.txt", str))
	{
		fopen_s(&file, "namesaved.txt", "at");
		if (file != NULL)
		{
			fprintf(file, "%s\n", str);
			fclose(file);
		}
	}
	strcat_s(str, ".txt");
	fopen_s(&file, str, "wt");
	if (file != NULL)
	{
		fprintf(file, "%d %d %d %d %d %d %d %d\n",MOVING, CHAR_LOCK, SPEED, STATE, LEVEL, LEVELUP, SCORE, SNAKE_COLOR);
		fprintf(file, "%d ", SIZE_SNAKE);
		for (int i = 0; i < SIZE_SNAKE; i++)
		{
			fprintf(file, "%d %d ", snake[i].x, snake[i].y);
		}
		fprintf(file, "\n%d ", FOOD_INDEX);
		for (int i = 0; i < 8; i++)
		{
			fprintf(file, "%d %d ", food[i].x, food[i].y);
		}
		fclose(file);
	}
	ShowCur(0);
	GotoXY(49, 15);
	cout << "SAVING...";
	Sleep(1500);
	DrawContinueGame(); // Draw the game paused
}
void LoadGame()
{   // Draw the load game screen
	system("cls");
	SetColor(3);
	DrawBoard(1, 1, WIDTH_CONSOLE, HEIGH_CONSOLE);
	SmallBoard();
	SetColor(11);
	GotoXY(20, 4);
	for (int i = 0; i < 53; i++)
		cout << (char)196;
	GotoXY(20, 6);
	for (int i = 0; i < 53; i++)
		cout << (char)196;
	for (int i = 0; i < 20; i++)
	{
		GotoXY(45, 4 + i);
		cout << (char)179;
	}
	SetColor(14);
	GotoXY(20, 5);
	cout << "     YOUR SAVED GAME " << (char)2;
	GotoXY(46, 5);
	cout << "    ENTER NAME TO LOAD " << (char)1;
	GotoXY(46, 7);
	cout << "     Enter file name: ";
	// Print the filenames were saved
	FILE* file;
	fopen_s(&file, "namesaved.txt", "rt");
	char str[50];
	if (file != NULL)
	{
		fgets(str, 50, file);
		int i = 0;
		while (!feof(file))
		{
			GotoXY(29, 8 + i++);
			cout << str;
			fgets(str, 255, file);
		}
		fclose(file);
	}
	// Load old game
	GotoXY(51, 9);
	ShowCur(1);
	gets_s(str);
	if (SOUND)
		PlaySound(L"enter.wav", NULL, SND_ASYNC);
	strcat_s(str, ".txt");
	fopen_s(&file, str, "rt");
	if (file != NULL)
	{
		fscanf_s(file, "%d %d %d %d %d %d %d %d\n", &MOVING, &CHAR_LOCK, &SPEED, &STATE, &LEVEL, &LEVELUP, 
			&SCORE, &SNAKE_COLOR);
		fscanf_s(file, "%d ", &SIZE_SNAKE);
		for (int i = 0; i < SIZE_SNAKE; i++)
		{
			fscanf_s(file, "%d %d ", &snake[i].x, &snake[i].y);
		}
		fscanf_s(file, "\n%d ", &FOOD_INDEX);
		for (int i = 0; i < 8; i++)
		{
			fscanf_s(file, "%d %d ", &food[i].x, &food[i].y);
		}
		fclose(file);
	}
	ShowCur(0);
	GotoXY(49, 15);
	cout << "LOADING...";
	Sleep(1500);
	DrawContinueGame(); // Draw the game paused
}


void Eat()
{
	if (SOUND)
		PlaySound(L"eat.wav", NULL, SND_ASYNC);
	SCORE += 5;
	snake[SIZE_SNAKE] = food[FOOD_INDEX];
	if (FOOD_INDEX == MAX_SIZE_FOOD - 1)
	{   // Levelup, the snake can't eat anyfood when the gate appear
		food[FOOD_INDEX] = { 0, 0 }; 
		LEVELUP = 1;
	}
	else
	{
		FOOD_INDEX++;
	}
	SIZE_SNAKE++;
	// Draw gate when LEVELUP = 1
	if (LEVELUP == 1)
	{
		if (SOUND)
			PlaySound(L"gateappear.wav", NULL, SND_ASYNC);
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
}

void ProcessDead()
{
	STATE = 0;
	SetColor(SNAKE_COLOR + 1);
	for (int i = 0; i < SIZE_SNAKE; i++)
	{
		GotoXY(snake[i].x, snake[i].y);
		cout << Snake_Body[i];
	}
	if(SOUND)
		PlaySound(L"die.wav", NULL, SND_SYNC);
	// Animation of deadth
	short t = 500;
	for (int i = 0; i < SIZE_SNAKE; i++)
	{
		if (temp == 13)
		{
			break;
		}
		GotoXY(snake[i].x, snake[i].y);
		cout << ' ';
		Sleep(t);
		t /= 1.5;
		if (t < 30)
			t = 30;
	}
}


void MoveLeft()
{
	if (ReachBodyLeft())
	{
		ProcessDead();
	}
	else if ((LEVEL == 1 && LeftDeadLevel1()) || (LEVEL == 2 && LeftDeadLevel2()) || (LEVEL == 3 && LeftDeadLevel3())
		|| (LEVEL == 4 && LeftDeadLevel4()))
	{
		ProcessDead();
	}
	else
	{
		if (snake[0].x - 1 == food[FOOD_INDEX].x && snake[0].y == food[FOOD_INDEX].y)
		{
			Eat();
		}

		for (int i = SIZE_SNAKE; i >= 0; i--)
		{
			snake[i + 1].x = snake[i].x;
			snake[i + 1].y = snake[i].y;

		}
		snake[0].x--;
	}
}
void MoveRight()
{
	if (ReachBodyRight())
	{
		ProcessDead();
	}
	else if ((LEVEL == 1 && RightDeadLevel1()) || (LEVEL == 2 && RightDeadLevel2()) || (LEVEL == 3 && RightDeadLevel3()) 
		|| (LEVEL == 4 && RightDeadLevel4()))
	{
		ProcessDead();
	}
	else if ((LEVEL == 1 && LEVELUP == 1 && snake[0].x + 1 == 68 && snake[0].y == 15) ||
		(LEVEL == 2 && LEVELUP == 1 && snake[0].x + 1 == 88 && snake[0].y == 15) ||
		(LEVEL == 3 && LEVELUP == 1 && snake[0].x + 1 == 90 && snake[0].y == 24) ||
		(LEVEL == 4 && LEVELUP == 1 && snake[0].x + 1 == 90 && snake[0].y == 5))
	{   // Processing the snake going through the gate
		SIZE_SNAKE--;
		start_char++;
		if (SIZE_SNAKE == 0)
		{
			LEVELUP = 2; // Move to next level
			start_char = 0; // Reset start char
			MOVING = ' '; // Not for the snake continues moving 
		}
	}
	else
	{
		if (snake[0].x + 1 == food[FOOD_INDEX].x && snake[0].y == food[FOOD_INDEX].y)
		{
			Eat();
		}
		for (int i = SIZE_SNAKE - 1; i >= 0; i--)
		{
			snake[i + 1].x = snake[i].x;
			snake[i + 1].y = snake[i].y;
		}
		snake[0].x++;
	}
}
void MoveUp()
{
	if (ReachBodyUp())
	{
		ProcessDead();
	}
	else if ((LEVEL == 1 && UpDeadLevel1()) || (LEVEL == 2 && UpDeadLevel2()) || (LEVEL == 3 && UpDeadLevel3())
		|| (LEVEL == 4 && UpDeadLevel4()))
	{
		ProcessDead();
	}
	else
	{
		if (snake[0].x == food[FOOD_INDEX].x && snake[0].y - 1 == food[FOOD_INDEX].y)
		{
			Eat();
		}
		for (int i = SIZE_SNAKE; i >= 0; i--)
		{
			snake[i + 1].x = snake[i].x;
			snake[i + 1].y = snake[i].y;

		}
		snake[0].y--;
	}
}
void MoveDown()
{
	if (ReachBodyDown())
	{
		ProcessDead();
	}
	else if ((LEVEL == 1 && DownDeadLevel1()) || (LEVEL == 2 && DownDeadLevel2()) || (LEVEL == 3 && DownDeadLevel3()) 
		|| (LEVEL == 4 && DownDeadLevel4()))
	{
		ProcessDead();
	}
	else
	{
		if (snake[0].x == food[FOOD_INDEX].x && snake[0].y + 1 == food[FOOD_INDEX].y)
		{
			Eat();
		}
		for (int i = SIZE_SNAKE; i >= 0; i--)
		{
			snake[i + 1].x = snake[i].x;
			snake[i + 1].y = snake[i].y;
		}
		snake[0].y++;
	}
}


void ThreadFunc()
{
	while (1)
	{
		if (STATE == 1)
		{   // If my snake is alive
			SmallBoard();
			DrawSnakeAndFood(' ');
			if (start_char > 0)
			{
				// When the snake is moving through the gate, it can't move to other directions
				MOVING = 'D';
			}
			switch (MOVING)
			{
			case 'A':
				MoveLeft();
				break;
			case 'D':
				MoveRight();
				break;
			case 'W':
				MoveUp();
				break;
			case 'S':
				MoveDown();
				break;
			}
			if (LEVELUP == 0)
			{
				DrawSnakeAndFood(4);
			}
			else if (LEVELUP == 1)
			{   // Processing going through the gate
				DrawSnakeAndFood(4, start_char);
			}
			Sleep(300 / SPEED); // Sleep function with SPEED variable
		}
		else
		{
			break; // Terminate thread that call this function
		}
	}
}


void Menu()
{   // Draw the snake of the menu
	SetColor(1);
	system("cls");
	DrawBoard(1, 1, WIDTH_CONSOLE, HEIGH_CONSOLE);
	SetColor(3);
	GotoXY(13, 8); printf("Welcome to ");
	GotoXY(25, 3); printf("                           _           ");
	GotoXY(25, 4); printf("   ___    _ _     __ _    | |__    ___ ");
	GotoXY(25, 5); printf("  (_-<   | ' \\   / _` |   | / /   / -_)");
	GotoXY(25, 6); printf("  /__/_  |_||_|  \\__,_|   |_\\_\\   \\___|");
	GotoXY(25, 7); printf("_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|");
	GotoXY(25, 8); printf("\"\`-0-0-'\"\`-0-0-'\"\`-0-0-'\"\`-0-0-'\"\`-0-0-'");
	SetColor(6);
	GotoXY(25, 10); printf("              __ _");
	GotoXY(25, 11); printf("             / _` |  __ _    _ __     ___");
	GotoXY(25, 12); printf("             \\__, | / _` |  | '  \\   / -_)");
	GotoXY(25, 13);  printf("             |___/  \\__,_|  |_|_|_|  \\___|");
	GotoXY(25, 14);  printf("           _|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|");
	GotoXY(25, 15);  printf("           \"\`-0-0-'\"\`-0-0-'\"\`-0-0-'\"\`-0-0-'  of group 3!!!");
	SetColor(5);
	GotoXY(10, 12);  printf("    _    _       ");
	GotoXY(10, 13);  printf(" ,-(|)--(|)-,    ");
	GotoXY(10, 14);  printf("(            )   ");
	GotoXY(10, 15); printf(" \\_   ..   _/    ");
	GotoXY(10, 16); printf("   \\______/");
	SetColor(7);
	GotoXY(10, 17);  printf("     V  V                                           ");
	SetColor(5);
	GotoXY(25, 17);  printf("                               ____                 ");
	GotoXY(10, 18);  printf("     `.^^^`.                                 /^,--` ");
	GotoXY(10, 19);  printf("      \\^^^^^\\                               (^^\\ ");
	GotoXY(10, 20);  printf("       |^^^^|                   _,-._         \\^^\\");
	GotoXY(10, 21);  printf("      (^^^^^\\       __       _,-'^^^^^`.     _,'^^)");
	GotoXY(10, 22);  printf("       \\^^^^^`.__,-'^^`-.__.'^^^^  ^^^^ `_--'^^^_/ ");
	GotoXY(10, 23);  printf("        \\^^^^^^ ^^^   ^^^^^^^   __    ^^^^^^^^_/   ");
	GotoXY(10, 24);  printf("        \\^^^^^^ ^^ _  ^^^^^^^_,-'  `.^^^^^^^_/     ");
	GotoXY(10, 25);  printf("         `._____,-' `-.____.'        `-.___.'       ");
	// Draw the menu
	SetColor(2);
	GotoXY(101, 7);
	printf("----MENU----");
	GotoXY(101, 11);
	printf("1. New Game");
	GotoXY(101, 13);
	printf("2. Load Game");
	GotoXY(101, 15);
	printf("3. Setting");
	GotoXY(101, 17);
	printf("4. Introduction");
	GotoXY(101, 19);
	printf("5. Quit Game");
	// Processing moving the arrow of the menu
	int choice = 1;
	int oldChoice = 1;
	int next = 1;
	int key;
	SetColor(1);
	GotoXY(100, 11);
	printf("%c", 16);
	while (interf == MENU)
	{
		if (_kbhit())
		{
			key = _getch();
			if (SOUND)
				PlaySound(L"press.wav", NULL, SND_ASYNC);
			if (key == 's') {
				choice++;
				if (choice == 6) choice = 1;
			}
			if (key == 'w') {
				choice--;
				if (choice == 0) choice = 5;
			}
			switch (choice) {
			case 1:
				if (oldChoice != choice) 
				{
					GotoXY(100, 13);
					printf(" ");
					GotoXY(100, 15);
					printf(" ");
					GotoXY(100, 17);
					printf(" ");
					GotoXY(100, 19);
					printf(" ");
					oldChoice = 1;
					GotoXY(100, 11);
					SetColor(1);
					printf("%c", 16);
				}
				break;
			case 2:
				if (oldChoice != choice)
				{
					GotoXY(100, 11);
					printf(" ");
					GotoXY(100, 15);
					printf(" ");
					GotoXY(100, 17);
					printf(" ");
					GotoXY(100, 19);
					printf(" ");
					GotoXY(100, 13);
					SetColor(1);
					printf("%c", 16);
					oldChoice = 2;
				}
				break;
			case 3:
				if (oldChoice != choice)
				{
					GotoXY(100, 13);
					printf(" ");
					GotoXY(100, 11);
					printf(" ");
					GotoXY(100, 17);
					printf(" ");
					GotoXY(100, 19);
					printf(" ");
					GotoXY(100, 15);
					SetColor(1);
					printf("%c", 16);
					oldChoice = 3;
				}
				break;
			case 4:
				if (oldChoice != choice)
				{
					GotoXY(100, 11);
					printf(" ");
					GotoXY(100, 13);
					printf(" ");
					GotoXY(100, 15);
					printf(" ");
					GotoXY(100, 19);
					printf(" ");
					GotoXY(100, 17);
					SetColor(1);
					printf("%c", 16);
					oldChoice = 4;
				}
				break;
			case 5:
				if (oldChoice != choice)
				{
					GotoXY(100, 11);
					printf(" ");
					GotoXY(100, 13);
					printf(" ");
					GotoXY(100, 15);
					printf(" ");
					GotoXY(100, 17);
					printf(" ");
					GotoXY(100, 19);
					SetColor(1);
					printf("%c", 16);
					oldChoice = 5;
				}
				break;
			}
			// Move to another user interface
			if (key == 13)
			{
				switch (choice)
				{
				case 1:
					interf = INGAME;
					break;
				case 2:
					interf = LOADGAME;
					break;
				case 3:
					interf = SETTING;
					break;
				case 4:
					interf = INFORMATION;
					break;
				case 5:
					interf = QUITGAME;
					break;
				}
			}
		}
	}
}

void InGame(int oldgame)
{
	// If oldgame != 0, Program won't reset data and take the present data (use for saving and loading)
	if (oldgame)
		goto conti1;
	StartGame();
conti1:
	STATE = 1;
	// Create thread for snake
	thread t(ThreadFunc); 
	HANDLE handle_t = t.native_handle();
	if (oldgame) // Stop when load game from menu
		PauseGame(handle_t);
	while (1)
	{
		temp = toupper(_getch());
		if (STATE == 1)
		{
			if (LEVELUP == 2) // Move to the next level
			{
				if (LEVEL == 4)
					LEVEL = 1;
				else
					LEVEL++;
				SPEED++;
				STATE = 0; // Stop thread
				t.join();
				interf = INGAME;
				return;
			}
			if (temp == 'P')
			{
				PauseGame(handle_t);
			}
			else if (temp == 27) // ESC
			{
				STATE = 0; // Stop thread
				LEVEL = 1;
				t.join();
				interf = MENU;
				return;
			}
			// Can't save or load when the snake is moving through gate
			else if (temp == 'T' && start_char == 0) // Save game
			{
				PauseGame(handle_t);
				SaveGame();
			}
			else if (temp == 'L' && start_char == 0) // Load game
			{
				PauseGame(handle_t);
				LoadGame();
			}
			else
			{
				ResumeThread(handle_t);
				if ((temp != CHAR_LOCK) && (temp == 'D' || temp == 'A' || temp == 'W' || temp == 'S'))
				{
					if (temp == 'D') CHAR_LOCK = 'A';
					else if (temp == 'W') CHAR_LOCK = 'S';
					else if (temp == 'S') CHAR_LOCK = 'W';
					else CHAR_LOCK = 'D';
					MOVING = temp;
				}
			}
		}
		else
		{
			t.join();
			interf = GAMEOVER;
			return;
		}
	}
}

void GameOver()
{
	SetColor(3);
	system("cls");
	if (SOUND)
		PlaySound(L"gameover.wav", NULL, SND_ASYNC);
	DrawBoard(1, 1, WIDTH_CONSOLE, HEIGH_CONSOLE);
	GotoXY(38, 8); printf(">>----------------<<");
	GotoXY(38, 9); printf("|  Total Score: %d  |", SCORE);
	GotoXY(38, 10); printf(">>----------------<<");
	SetColor(11);
	GotoXY(10, 12); printf("   ___                                                                         ");
	GotoXY(10, 13); printf("  / __|   __ _    _ __     ___      o O O   ___    __ __    ___      _ _       ");
	GotoXY(10, 14); printf(" | (_ |  / _` |  | `  \\   / -_)    o       / _ \\   \\ V /   / -_)    | '_|");
	GotoXY(10, 15); printf("  \\___|  \\__,_|  |_|_|_|  \\___|   TS__[O]  \\___/   _\\_/_   \\___|   _|_|_ ");
	SetColor(5);
	GotoXY(10, 16); printf("_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"| {======|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"| ");
	GotoXY(10, 17); printf("\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'./o--000'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'");
	SmallBoard();
	// Reset global data
	LEVEL = 1;
	SPEED = 5;
	SCORE = 0;
	_getch();
	if (SOUND)
		PlaySound(L"press.wav", NULL, SND_ASYNC);
	interf = MENU;
}

void QuitGame()
{
	system("cls");
	SetColor(2);
	GotoXY(40, 5); printf("     ---_ ......._-_--.        ");
	GotoXY(40, 6); printf("    (|\\ /      / /| \\  \\    ");
	GotoXY(40, 7); printf("    /  /     .'  -=-'   `.     ");
	GotoXY(40, 8); printf("   /  /    .'             )    ");
	GotoXY(40, 9); printf(" _/  /   .'        _.)   /     ");
	GotoXY(40, 10); printf("/ o   o        _.-' /  .'      ");
	GotoXY(40, 11); printf("\\          _.-'    / .'*|     ");
	GotoXY(40, 12); printf(" \\______.-'//    .'.' \\*|    ");
	GotoXY(40, 13); printf("  \\|  \\ | //   .'.' _ |*|    ");
	GotoXY(40, 14); printf("   `   \\|//  .'.'_ _ _|*|     ");
	GotoXY(40, 15); printf("    .  .// .'.' | _ _ \\*|     ");
	GotoXY(40, 16); printf("    \\`-|\\_/ /    \\ _ _ \\*\\");
	GotoXY(40, 17); printf("     `/'\\__/      \\ _ _ \\*\\");
	GotoXY(40, 18); printf("    /^|            \\ _ _ \\*  ");
	GotoXY(40, 19); printf("   '  `             \\ _ _ \\  ");
	GotoXY(40, 20); printf("                     \\_       ");
	SetColor(12);
	GotoXY(40, 23); printf("Thanks for playing our game!!! ");
	SetColor(7);
	exit(0);
}

void Information()
{
	system("cls");
	DrawBoard(1, 1, WIDTH_CONSOLE, HEIGH_CONSOLE);
	SetColor(6);
	GotoXY(37, 3);
	printf("%c GAME'S INFORMATION", 16);
	SetColor(1);
	GotoXY(25, 5);
	printf("%c Instructor : Truong Toan Thinh", 26);
	GotoXY(25, 7);
	printf("%c Students   : Tran My Phu Lam    - 21120492", 26);
	GotoXY(25, 8);
	printf("             : Nguyen Ngoc Lan    - 21120493");
	GotoXY(25, 9);
	printf("             : Pham Manh Cuong    - 21120423");
	GotoXY(25, 10);
	printf("             : Chu Hai Linh       - 21120496");
	GotoXY(25, 11);
	printf("             : Nguyen Duc Duy Anh - 21120409");

	SetColor(6);
	GotoXY(37, 13);
	printf("%c GAME'S INSTRUCTIONS", 16);

	SetColor(1);
	GotoXY(25, 15);
	printf("%c Press P : Pause Game", 26);
	GotoXY(25, 16);
	printf("%c Press T : Save Game", 26);
	GotoXY(25, 17);
	printf("%c Press L : Load Game", 26);
	GotoXY(25, 18);
	printf("%c Press W : Move Up", 26);
	GotoXY(25, 19);
	printf("%c Press S : Move Down", 26);
	GotoXY(25, 20);
	printf("%c Press A : Move Left", 26);
	GotoXY(25, 21);
	printf("%c Press D : Move Right", 26);
	GotoXY(25, 22);
	printf("%c Avoid Hitting Walls And Yourself", 26);
	GotoXY(25, 23);
	printf("%c Try To Eat Enough Food To Pass Each Level", 26);
	SetColor(5);
	GotoXY(31, 25);
	printf("Press Any Key To Back To The Menu!");
	_getch();
	if (SOUND)
		PlaySound(L"press.wav", NULL, SND_ASYNC);
	interf = MENU;
}

void SetSnakeColor()
{
	system("cls");
	DrawBoard(1, 1, WIDTH_CONSOLE, HEIGH_CONSOLE);
	SetColor(7);
	GotoXY(35, 5); printf("  ___                  ___   ");
	GotoXY(35, 6); printf(" (o o)                (o o)  ");
	GotoXY(35, 7); printf("(  V  )     ");
	SetColor(8);
	GotoXY(47, 7); printf("COLOR");
	SetColor(7);
	GotoXY(52, 7); printf("    (  V  )");
	GotoXY(35, 8); printf("--m-m--.------------.--m-m--");
	GotoXY(35, 9); printf("     .-|------------|-.     ");
	GotoXY(35, 10); printf("     |  ");
	SetColor(1);
	GotoXY(45, 10); printf("1. Blue");
	SetColor(7);
	GotoXY(53, 10); printf("    |");
	GotoXY(35, 11); printf("     |----------------|     ");
	GotoXY(35, 12); printf("     |    ");
	SetColor(2);
	GotoXY(45, 12); printf("2. Green");
	SetColor(7);
	GotoXY(53, 12); printf("    |");
	GotoXY(35, 13); printf("     |----------------|     ");
	GotoXY(35, 14); printf("     | ");
	SetColor(3);
	GotoXY(42, 14); printf("3. Bright Blue");
	SetColor(7);
	GotoXY(56, 14); printf(" |");
	GotoXY(35, 15); printf("     |----------------|     ");
	GotoXY(35, 16); printf("     |     ");
	SetColor(4);
	GotoXY(46, 16); printf("4. Red");
	SetColor(7);
	GotoXY(52, 16); printf("     |");
	GotoXY(35, 17); printf("     |----------------|     ");
	GotoXY(35, 18); printf("     |    ");
	SetColor(5);
	GotoXY(45, 18); printf("5. Purple");
	SetColor(7);
	GotoXY(54, 18); printf("   |");
	GotoXY(35, 19); printf("     |----------------|     ");
	GotoXY(35, 20); printf("     |    ");
	SetColor(6);
	GotoXY(45, 20); printf("6. Yellow");
	SetColor(7);
	GotoXY(54, 20); printf("   |");
	GotoXY(35, 21); printf("     \'----------------\'     ");
	GotoXY(45, 23); printf("Choose: ");
	SetColor(6);
	ShowCur(1);
	int color;
	cin >> color;
	if (SOUND)
		PlaySound(L"enter.wav", NULL, SND_ASYNC);
	ShowCur(0);
	GotoXY(45, 25);
	printf("SETTING...");
	Sleep(1500);
	switch (color)
	{
	case 1:
		SNAKE_COLOR = 1;
		break;
	case 2:
		SNAKE_COLOR = 2;
		break;
	case 3:
		SNAKE_COLOR = 3;
		break;
	case 4:
		SNAKE_COLOR = 4;
		break;
	case 5:
		SNAKE_COLOR = 5;
		break;
	case 6:
		SNAKE_COLOR = 6;
		break;
	}
	interf = SETTING;
}

void SetSpeed()
{
	system("cls");
	DrawBoard(1, 1, WIDTH_CONSOLE, HEIGH_CONSOLE);
	SetColor(14);
	GotoXY(26, 9); printf(" ___                                ___");
	GotoXY(26, 10); printf(" \\ \'\\                               \\ \'\\");
	GotoXY(26, 11); printf(" _\\ _\\                              _\\ _\\");
	GotoXY(26, 12); printf(" \'\\ \\");
	SetColor(13);
	GotoXY(35, 12); printf("Enter your start speed");
	SetColor(14);
	GotoXY(57, 12); printf("    \'\\ \\");
	GotoXY(26, 13); printf("  _\\_\\     ");
	SetColor(13);
	GotoXY(39, 13); printf("(Default is 5)");
	SetColor(14);
	GotoXY(53, 13); printf("         _\\_\\");
	GotoXY(26, 14); printf(" \'\\\\                                \'\\\\");
	GotoXY(26, 15); printf("   \\\\                                 \\\\");
	GotoXY(26, 16); printf("   \'\\                                 \'\\");
	GotoXY(46, 15); 
	SetColor(3);
	int newSpeed;
	ShowCur(1);
	cin >> newSpeed;
	if (SOUND)
		PlaySound(L"enter.wav", NULL, SND_ASYNC);
	ShowCur(0);
	SPEED = newSpeed;
	GotoXY(43, 17);
	printf("SETTING...");
	Sleep(1500);
	interf = SETTING;
}

void SetSound()
{
	system("cls");
	DrawBoard(1, 1, WIDTH_CONSOLE, HEIGH_CONSOLE);
	SetColor(13);
	GotoXY(26, 9); printf("   |\\                                      |\\");
	GotoXY(26, 10); printf("   ||\\                                     ||\\");
	GotoXY(26, 11); printf("   ||\\\\                                    ||\\\\");
	GotoXY(26, 12); printf("   || \\\\");
	SetColor(6);
	GotoXY(40, 12); printf("Do you wanna play SOUND?");
	SetColor(13);
	GotoXY(66, 12); printf("   || \\\\");
	GotoXY(26, 13); printf("   ||  \\\\");
	SetColor(6);
	GotoXY(44, 13); printf("Yes - 1 / No - 0");
	SetColor(13);
	GotoXY(60, 13); printf("         ||  \\\\");
	GotoXY(26, 14); printf("   ||   ))                                 ||   ))");
	GotoXY(26, 15); printf("   ||  //                                  ||  // ");
	GotoXY(26, 16); printf(" /\'  )                                   /\'  )    ");
	GotoXY(26, 17); printf("(   /                                   (   /     ");
	GotoXY(26, 18); printf(" \'-\'                                     \'-\'      ");
	GotoXY(52, 15); 
	SetColor(3);
	int choice;
	ShowCur(1);
	cin >> choice;
	if (SOUND)
		PlaySound(L"enter.wav", NULL, SND_ASYNC);
	ShowCur(0);
	SOUND = choice;
	GotoXY(49, 19);
	printf("SETTING...");
	Sleep(1500);
	interf = SETTING;
}

void Setting()
{
	system("cls");
	SetColor(3);
	DrawBoard(1, 1, WIDTH_CONSOLE, HEIGH_CONSOLE);
	GotoXY(38, 4); printf("~~~.~~~~~~~~~~~~.~~~");
	GotoXY(38, 5); printf(" __|____________|__ ");
	GotoXY(38, 6); printf("|  ______________  |");
	GotoXY(38, 7); printf("| |  ");
	SetColor(10);
	GotoXY(43, 7); printf("Snake Color");
	SetColor(3);
	GotoXY(54, 7); printf(" | |");
	GotoXY(38, 8); printf("| |______________| |");
	GotoXY(38, 9); printf("|__.____________.__|");
	GotoXY(38, 10); printf(" __|____________|__ ");
	GotoXY(38, 11); printf("|  ______________  |");
	GotoXY(38, 12); printf("| |  ");
	SetColor(6);
	GotoXY(43, 12); printf("Game SOUND");
	SetColor(3);
	GotoXY(53, 12); printf("  | |");
	GotoXY(38, 13); printf("| |______________| |");
	GotoXY(38, 14); printf("|__.____________.__|");
	GotoXY(38, 15); printf(" __|____________|__ ");
	GotoXY(38, 16); printf("|  ______________  |");
	GotoXY(38, 17); printf("| |  ");
	SetColor(5);
	GotoXY(43, 17); printf("Start Speed");
	SetColor(3);
	GotoXY(54, 17); printf(" | |");
	GotoXY(38, 18); printf("| |______________| |");
	GotoXY(38, 19); printf("|__.____________.__|");
	GotoXY(38, 20); printf(" __|____________|__ ");
	GotoXY(38, 21); printf("|  ______________  |");
	GotoXY(38, 22); printf("| | ");
	SetColor(12);
	GotoXY(42, 22); printf("Back to Menu");
	SetColor(3);
	GotoXY(54, 22); printf(" | |");
	GotoXY(38, 23); printf("| |______________| |");
	GotoXY(38, 24); printf("|__.____________.__|");
	int choice = 1;
	int oldChoice = 1;
	int key;
	SetColor(1);
	GotoXY(32, 7);
	printf("%c--%c", 175, 16);
	while (interf == SETTING)
	{
		if (_kbhit())
		{
			if (SOUND)
				PlaySound(L"press.wav", NULL, SND_ASYNC);
			key = _getch();
			if (key == 's') {
				choice++;
				if (choice == 5) choice = 1;
			}
			if (key == 'w') {
				choice--;
				if (choice == 0) choice = 4;
			}
			switch (choice) {
			case 1:
				if (oldChoice != choice)
				{
					GotoXY(32, 12); printf("     ");
					GotoXY(32, 17); printf("     ");
					GotoXY(32, 22); printf("     ");
					oldChoice = 1;
					GotoXY(32, 7);
					SetColor(1);
					printf("%c--%c", 175, 16);
				}
				break;
			case 2:
				if (oldChoice != choice)
				{
					GotoXY(32, 7); printf("    ");
					GotoXY(32, 17); printf("    ");
					GotoXY(32, 22); printf("   ");
					GotoXY(32, 12);
					SetColor(1);
					printf("%c--%c", 175, 16);
					oldChoice = 2;
				}
				break;
			case 3:
				if (oldChoice != choice)
				{
					GotoXY(32, 7); printf("    ");
					GotoXY(32, 12); printf("    ");
					GotoXY(32, 22); printf("    ");
					GotoXY(32, 17);
					SetColor(1);
					printf("%c--%c", 175, 16);
					oldChoice = 3;
				}
				break;
			case 4:
				if (oldChoice != choice)
				{
					GotoXY(32, 7); printf("    ");
					GotoXY(32, 12); printf("    ");
					GotoXY(32, 17); printf("    ");
					GotoXY(32, 22);
					SetColor(1);
					printf("%c--%c", 175, 16);
					oldChoice = 4;
				}
				break;
			}
			if (key == 13)
			{
				if (SOUND)
					PlaySound(L"enter.wav", NULL, SND_ASYNC);
				switch (choice)
				{
				case 1:
					interf = SETCOLOR;
					break;
				case 2:
					interf = SETSOUND;
					break;
				case 3:
					interf = SETSPEED;
					break;
				case 4:
					interf = MENU;
					break;
				}
			}
		}
	}
}
