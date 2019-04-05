#include <iostream>
#include "wall.h"
#include "snake.h"
#include "food.h"
#include <ctime>
#include <conio.h>
#include <windows.h>

// 定位光标
void gotoxy(HANDLE hOut1, int x, int y) {
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hOut1, pos);
}

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); // 定义显示器句柄变量

int main() {
    // 添加随机数种子
    srand((unsigned int) time(NULL));

    // 是否死亡的标识
    bool isDead = false;

    // 上一次按键标识
    bool preKey = true;


    Wall wall;
    wall.initWall();
    wall.drawWall();

    Food food(wall);
    food.setFood();

    Snake snake(wall, food);
    snake.initSnake();

    gotoxy(hOut, 0, Wall::ROW);
    cout << "score：" << snake.getScore() << " points" << endl;

    while (!isDead) {
        // 接受用户输入
        char key = _getch();
        // 第一次按左键，不激活游戏
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
                    cout << "score：" << snake.getScore() << " points" << endl;
                    Sleep(snake.getSleepTime());
                } else {
                    isDead = true;
                    break;
                }
            } else {
                cout << "input error, please input again" << endl;
                break;
            }
        } while (!_kbhit()); // 没有键盘输入的时候，返回0
    }

    system("pause");
    return 0;
}