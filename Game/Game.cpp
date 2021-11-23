#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

bool gameOver;
int mapX = 0;
int mapY = 0;
int x = 1;
int pass = 1;
int y = 1;
int enemyX = 20;
int enemyY = 20;
bool levels[20] = {1};
int record = 0;
enum eDirection { LEFT, RIGHT, DOWN, UP, stop };
eDirection way;

void Draw()
{
    if (levels[0] == 1)
    {
        mapX = 20;
        mapY = 20;
    }
    system("cls");
    cout << "Record: " << record << endl;
    for (int i = 0; i <= mapX; i++)
    {
        for (int j = 0; j <= mapY; j++)
        {
            if (i == 0)
            {
                cout << "#";
            }
            if (j == 0)
            {
                cout << "#";
            }
            if (i == mapX)
            {
                cout << "#";
            }
            if (j == mapX)
            {
                cout << "#";
            }
            if (j == x && i == y)
            {
                cout << "O";
            }
            else if (j == enemyX && i == enemyY)
            {
                cout << "!";
            }
            else
            {
                if (j != 0 && i != 0)
                {
                    if (j != mapX && i != mapY)
                    {
                        cout << " ";
                    }
                }
            }
        }
        cout << endl;
    }
    Sleep(100);
    if (enemyY == y && enemyX == x)
    {
        cout << "You dead";
        gameOver = 1;
    }
    record++;
    if (record == 50)
    {
        levels[1] = 1;
    }
    if (x == 0)
    {
        way = stop;
        x++;
    }
    if (x >= mapX)
    {
        way = stop;
        x--;
    }
    if (y >= mapY)
    {
        way = stop;
        y--;
    }
    if (y == 0)
    {
        way = stop;
        y++;
    }
}

void Setup()
{
    gameOver = false;
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
        case ' ':
            way = stop;
            break;
        }
    }
}
void Logic()
{
    switch (way)
    {
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
    case stop:
        break;
    default:
        break;
    }
    pass++;
    if (pass == 2)
    {
        if (enemyX > x)
        {
            enemyX--;
        }
        if (enemyX < x)
        {
            enemyX++;
        }
        if (enemyY > y)
        {
            enemyY--;
        }
        if (enemyY < y)
        {
            enemyY++;
        }
        pass = 0;
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
