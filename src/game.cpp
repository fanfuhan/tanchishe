#include <iostream>
#include "wall.h"
#include "snake.h"
#include "food.h"
#include <ctime>
#include <conio.h>
#include <windows.h>

// ��λ���
void gotoxy(HANDLE hOut1, int x, int y) {
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hOut1, pos);
}

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); // ������ʾ���������

int main() {
    // ������������
    srand((unsigned int) time(NULL));

    // �Ƿ������ı�ʶ
    bool isDead = false;

    // ��һ�ΰ�����ʶ
    bool preKey = true;


    Wall wall;
    wall.initWall();
    wall.drawWall();

    Food food(wall);
    food.setFood();

    Snake snake(wall, food);
    snake.initSnake();

    gotoxy(hOut, 0, Wall::ROW);
    cout << "score��" << snake.getScore() << " points" << endl;

    while (!isDead) {
        // �����û�����
        char key = _getch();
        // ��һ�ΰ��������������Ϸ
        if (preKey && key == snake.LEFT) {
            continue;
        }
        preKey = false;
        do {
            if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT) {
                if (snake.move(key)) {
                    //system("cls");
                    //wall.drawWall();
                    gotoxy(hOut, 0, Wall::ROW);
                    cout << "score��" << snake.getScore() << " points" << endl;
                    Sleep(snake.getSleepTime());
                } else {
                    isDead = true;
                    break;
                }
            } else {
                cout << "input error, please input again" << endl;
                break;
            }
        } while (!_kbhit()); // û�м��������ʱ�򣬷���0
    }

    system("pause");
    return 0;
}