#include <iostream>
#include "food.h"
#include <windows.h>

void gotoxy2(HANDLE hOut2, int x, int y) {
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hOut2, pos);
}

HANDLE hOut2 = GetStdHandle(STD_OUTPUT_HANDLE); // 定义显示器句柄变量

void Food::setFood() {
    while (true){
        foodX = rand() % (Wall::ROW - 2) + 1;
        foodY = rand() % (Wall::COL - 2) + 1;
        // 如果随机的位置是蛇头或蛇身，就重新生成随机数
        if (wall.getWall(foodX, foodY) == ' '){
            wall.setWall(foodX, foodY, '#');
            gotoxy2(hOut2, foodY * 2, foodX);
            cout << "#";
            break;
        }
    }
}

Food::Food(Wall &tempWall) : wall(tempWall){
}
