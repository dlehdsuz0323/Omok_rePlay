

#include <iostream>
#include <time.h>
#include <conio.h> //
#include <Windows.h> //



using namespace std;

#define HIGH   20
#define WIDTH  20

#define EMPTY       0
#define WHITEPLAYER 1
#define BLACKPLAYER 2

struct POSITION
{
	int x;
	int y;
};

POSITION CURSOR;

int TIME[HIGH * WIDTH];
int map[WIDTH][HIGH] = { 0 };
int turnCheck = 0;		// 0 = white
int turnOfTime = 1;     // 1 = white
int endturn = 0;
int timeSet = 0;
int rePlay_fileCur = 0;
int TIME_arr = 0;

void printMap(void);
void blockControll(void);
void checkWin(void);
void quitGame(void);
void printMenu(void);
void inputMenu(void);

void WidthWinCheck(int _y, int _x, int type);
void HighWinCheck(int _y, int _x, int type);
void RightCrossWinCheck(int _y, int _x, int type);
void LeftCrossWinCheck(int _y, int _x, int type);

void printMenu(void)
{
	cout << endl;
	cout << "1. ÀÔ·Â" << endl;
	cout << "2. Ãâ·Â" << endl;
	cout << endl;
}


void inputMenu(void)
{
	int num;

	cin >> num;

	switch (num)
	{
	case 1:
	{
		FILE* rePlay = fopen("rePlay.txt", "w");
		FILE* time = fopen("time.txt", "w");

		while (true)
		{
			blockControll();
		}

		fclose(rePlay);
		fclose(time);
		break;
	}

	case 2:

		for (int i = 0; i < (HIGH * WIDTH); i++)
		{
		FILE* rePlay = fopen("rePlay.txt", "r");
		FILE* time = fopen("time.txt", "r");
		for (int j = 0; j < (HIGH * WIDTH); j++)
		{
			fscanf(time, "%d ", &TIME[j]);
			if (TIME[j] == NULL)
			{
				break;
			}
		}
			if (turnOfTime <= endturn)
			{
				for (int i = 0; i <= TIME[TIME_arr]; i++)
				{ 
					Sleep(1);
					printMap();
					system("cls");
				}
			}
				else
			{
					quitGame();
			}
			if (turnOfTime % 2 == 1)
			{
				fseek(rePlay, rePlay_fileCur, SEEK_CUR);
				fscanf(rePlay, "%d %d ", &CURSOR.y, &CURSOR.x);

				map[CURSOR.y][CURSOR.x] = WHITEPLAYER;

				if (CURSOR.x < 10 && CURSOR.y < 10)
				{
					rePlay_fileCur += 4;
					turnOfTime++;
				}
				else if (CURSOR.x < 10 && CURSOR.y > 10)
				{
					rePlay_fileCur += 5;
					turnOfTime++;
				}
				else if (CURSOR.x < 10 && CURSOR.y >= 10)	
				{
					rePlay_fileCur += 5;
					turnOfTime++;
				}
				else if (CURSOR.x >= 10 && CURSOR.y < 10)
				{
					rePlay_fileCur += 5;
					turnOfTime++;
				}
				else if (CURSOR.x > 10 && CURSOR.y < 10)
				{
					rePlay_fileCur += 5;
					turnOfTime++;
				}
				else if (CURSOR.x >= 10 && CURSOR.y >= 10)
				{
					rePlay_fileCur += 6;
					turnOfTime++;
				}

				TIME_arr++;
			}

			else if (turnOfTime % 2 == 0)
			{
				fseek(rePlay, rePlay_fileCur, SEEK_CUR);
				fscanf(rePlay, "%d %d ", &CURSOR.y, &CURSOR.x);
				map[CURSOR.y][CURSOR.x] = BLACKPLAYER;

				if (CURSOR.x < 10 && CURSOR.y < 10)
				{
					rePlay_fileCur += 4;
					turnOfTime++;
				}
				else if (CURSOR.x < 10 && CURSOR.y > 10)
				{
					rePlay_fileCur += 5;
					turnOfTime++;
				}
				else if (CURSOR.x < 10 && CURSOR.y >= 10)
				{
					rePlay_fileCur += 5;
					turnOfTime++;
				}
				else if (CURSOR.x >= 10 && CURSOR.y < 10)
				{
					rePlay_fileCur += 5;
					turnOfTime++;
				}
				else if (CURSOR.x > 10 && CURSOR.y < 10)
				{
					rePlay_fileCur += 5;
					turnOfTime++;
				}
				else if (CURSOR.x >= 10 && CURSOR.y >= 10)
				{
					rePlay_fileCur += 6;
					turnOfTime++;
				}

				TIME_arr++;
			}
			fclose(rePlay);
			fclose(time);
		}
	}
}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void printMap(void)
{
	gotoxy(0, 0);
	if (turnCheck == 0)
	{
		cout << turnOfTime << "Èæµ¹Â÷·Ê  " << endl;
	}
	else if (turnCheck == 1)
	{
		cout << turnOfTime << "¹éµ¹Â÷·Ê  " << endl;
	}

	for (int i = 0; i < HIGH; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
		//	gotoxy(40, 10);
			if (i == CURSOR.y && j == CURSOR.x)
			{
				cout << "¡Ù";
			}

			else if (map[i][j] == WHITEPLAYER) // 1,3,5,7,9....
			{
				cout << "¡Û";
			}
			else if (map[i][j] == BLACKPLAYER) // 2,4,6,8,10....
			{
				cout << "¡Ü";
			}

			else if (map[i][j] == 0)
			{
				if (i == 0 && j == 0)
					cout << "¦£";
				else if (i == 0 && j == HIGH - 1)
					cout << "¦¤";
				else if (i == 0)
					cout << "¦¨";
				else if (i == WIDTH - 1 && j == 0)
					cout << "¦¦";
				else if (i == WIDTH - 1 && j == HIGH - 1)
					cout << "¦¥";
				else if (i == WIDTH - 1)
					cout << "¦ª";
				else if (j == 0)
					cout << "¦§";
				else if (j == HIGH - 1)
					cout << "¦©";
				else
					cout << "¦«";
				cout << " ";
			}
		}
		cout << endl;
	}
}


void blockControll(void)
{
	timeSet++;

	//if (kbhit())
	{
		
		char input = getch();
		switch (input)
		{

		case 'w':
			CURSOR.y--;
			break;
		case 's':
			CURSOR.y++;
			break;
		case 'a':
			CURSOR.x--;
			break;
		case 'd':
			CURSOR.x++;
			break;
		case 'k':
		{
			FILE* rePlay = fopen("rePlay.txt", "a");
			FILE* turn = fopen("turnOfTime.txt", "w+");
			FILE* time = fopen("time.txt", "a");
			{
				for (int i = 0; i < HIGH; i++)
				{
					for (int j = 0; j < WIDTH; j++)
					{
						if (turnCheck == 0)
						{
							if (i == CURSOR.y && j == CURSOR.x)
							{
								map[CURSOR.y][CURSOR.x] = WHITEPLAYER;

								fprintf(rePlay, "%d %d ", CURSOR.y, CURSOR.x);
							}
						}

						if (turnCheck == 1)
						{
							if (i == CURSOR.y && j == CURSOR.x)
							{
								map[CURSOR.y][CURSOR.x] = BLACKPLAYER;

								fprintf(rePlay, "%d %d ", CURSOR.y, CURSOR.x);
							}
						}
					}
				}
				if (turnCheck == 0)
				{
					turnCheck++;
				}
				else if (turnCheck == 1)
				{
					turnCheck--;
				}
				turnOfTime++;
				fprintf(turn, "%d ", turnOfTime);

				TIME[TIME_arr] = timeSet;
				fprintf(time, "%d ", TIME[TIME_arr]);

				TIME_arr++;
				timeSet = 0;

				fclose(rePlay);
				fclose(turn);
				break;
			}
		}
		}
	}  //switch end

	   // input > update > draw

	system("cls");
	checkWin();
	printMap();

}
void quitGame(void)
{
	exit(0);
}

void checkWin(void)

{
	for (int i = 0; i < HIGH; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (turnCheck == 1)
			{
				WidthWinCheck(i, j, WHITEPLAYER);
				HighWinCheck(i, j, WHITEPLAYER);
				RightCrossWinCheck(i, j, WHITEPLAYER);
				LeftCrossWinCheck(i, j, WHITEPLAYER);
			}

			else if (turnCheck == 0)
			{
				WidthWinCheck(i, j, BLACKPLAYER);
				HighWinCheck(i, j, BLACKPLAYER);
				RightCrossWinCheck(i, j, BLACKPLAYER);
				LeftCrossWinCheck(i, j, BLACKPLAYER);
			}
		}
	}
}

void WidthWinCheck(int _y, int _x, int type)
{
	int count = 0;

	while (map[_y][_x++] == type)
	{
		count++;
	}
	if (count == 5)
	{
		if (turnCheck == 0)
		{
			cout << "¹éµ¹½Â" << endl << endl;
			printMap();
			quitGame();
		}

		else if (turnCheck == 1)
		{
			cout << "Èæµ¹½Â" << endl << endl;
			printMap();
			quitGame();
		}
	}
}

void HighWinCheck(int _y, int _x, int type)
{
	int count = 0;

	while (map[_y++][_x] == type)

		count++;

	if (count == 5)
	{
		if (turnCheck == 0)
		{
			cout << "¹éµ¹½Â" << endl << endl;
			printMap();
			quitGame();
		}

		else if (turnCheck == 1)
		{
			cout << "Èæµ¹½Â" << endl << endl;
			printMap();
			quitGame();
		}
	}

}

void RightCrossWinCheck(int _y, int _x, int type)
{
	int count = 0;

	while (map[_y++][_x++] == type)

		count++;

	if (count == 5)
	{
		if (turnCheck == 0)
		{
			cout << "¹éµ¹½Â" << endl << endl;
			printMap();
			quitGame();
		}

		else if (turnCheck == 1)
		{
			cout << "Èæµ¹½Â" << endl << endl;
			printMap();
			quitGame();
		}
	}
}

void LeftCrossWinCheck(int _y, int _x, int type)
{
	int count = 0;

	while (map[_y++][_x--] == type)

		count++;

	if (count == 5)
	{
		if (turnCheck == 0)
		{
			cout << "¹éµ¹½Â" << endl << endl;
			printMap();
			quitGame();
		}

		else if (turnCheck == 1)
		{
			cout << "Èæµ¹½Â" << endl << endl;
			printMap();
			quitGame();
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void)
{
	FILE* turn = fopen("turnOfTime.txt", "a+");
	fscanf(turn, "%d ", &turnOfTime);
	endturn = turnOfTime;
	turnOfTime = 1;
	timeSet= 0;

	CURSOR.x = HIGH / 2;
	CURSOR.y = WIDTH / 2;

	printMenu();
	while (true)
	{
		inputMenu();
	}
}