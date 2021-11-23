#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

bool gameOver;
int x = 1;
int y = 1;

enum eDirection { Death = 0, LEFT, RIGHT, DOWN, UP };

eDirection way; void Draw()
{
	system("cls");
	for (int i = 0; i <= y; i++)
	{
		cout << endl;
	}
	for (int i = 0; i <= x; i++)
	{
		cout << " ";
	}
	cout << "O";
	Sleep(100);
}

void Setup()
{
	gameOver = false;
	way = Death;
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			way = LEFT;
			break;
		case 'd':
			way = RIGHT;
			break;
		case 's':
			way = DOWN;
			break;
		case 'w':
			way = UP;
			break;
		}
	}
}

void Logic()
{
	switch (way)
	{
	case Death:
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
}


int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
	}
}

