#include <iostream>
#include "snake.h"
#include <windows.h>

void gotoxy1(HANDLE hOut1, int x, int y) {
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hOut1, pos);
}

HANDLE hOut1 = GetStdHandle(STD_OUTPUT_HANDLE); // 定义显示器句柄变量

void Snake::initSnake() {
    destroyPoint();
    addPoint(5, 3);
    addPoint(5, 4);
    addPoint(5, 5);
}

void Snake::destroyPoint() {
    Point *pCur = pHead;
    while (pHead != NULL) {
        pCur = pHead->next;
        delete pHead;
        pHead = pCur;
    }
}

void Snake::addPoint(int x, int y) {
    // 创建新节点
    Point *newPoint = new Point;
    newPoint->x = x;
    newPoint->y = y;
    newPoint->next = NULL;

    // 如果原来头节点不为空，变为身子
    if (pHead != NULL) {
        wall.setWall(pHead->x, pHead->y, '=');
        gotoxy1(hOut1, pHead->y * 2, pHead->x);
        cout << "=";
    }
    newPoint->next = pHead;
    pHead = newPoint;
    wall.setWall(pHead->x, pHead->y, '@');
    gotoxy1(hOut1, pHead->y * 2, pHead->x);
    cout << "@";
}

Snake::Snake(Wall &tempWall, Food &tempFood) : wall(tempWall), food(tempFood) {
    pHead = NULL;
    isRool = false;
}

void Snake::delPoint() {
    // 两个节点以上，才去做删除操作
    if (pHead == NULL || pHead->next == NULL) {
        return;
    }
    Point *pCur = pHead->next, *pPre = pHead;
    while (pCur->next != NULL) {
        pPre = pPre->next;
        pCur = pCur->next;
    }
    // 删除尾节点
    wall.setWall(pCur->x, pCur->y, ' ');
    gotoxy1(hOut1, pCur->y * 2, pCur->x);
    cout << " ";

    delete pCur;
    pCur = NULL;
    pPre->next = NULL;
}

bool Snake::move(char key) {
    int x = pHead->x;
    int y = pHead->y;
    switch (key) {
        case UP:
            x--;
            break;
        case DOWN:
            x++;
            break;
        case LEFT:
            y--;
            break;
        case RIGHT:
            y++;
            break;
        default:
            break;
    }

    // 判断 如果下一步碰到的是尾巴，不应该死亡
    Point *pCur = pHead->next, *pPre = pHead;
    while (pCur->next != NULL) {
        pPre = pPre->next;
        pCur = pCur->next;
    }

    if (pCur->x == x && pCur->y == y) {
        isRool = true;
    } else {
        // 判断用户要到达的位置是否成功
        if (wall.getWall(x, y) == '*' || wall.getWall(x, y) == '=') {
            addPoint(x, y);
            delPoint();
            system("cls");
            wall.drawWall();
            cout << "final score: " << getScore() << " points" << endl;
            cout << "GAME OVER!" << endl;

            return false;
        }
    }

    // 移动成功分两种：吃到食物，未吃到食物
    if (wall.getWall(x, y) == '#') {
        addPoint(x, y);
        // 重新设置食物
        food.setFood();
    } else {
        addPoint(x, y);
        delPoint();
        if (isRool) {
            wall.setWall(x, y, '@');
            gotoxy1(hOut1, pHead->y * 2, pHead->x);
            cout << "@";
        }
    }
    return true;
}

int Snake::getSleepTime() {
    int sleepTime = 0;
    int size = countList();
    if (size < 5) {
        sleepTime = 300;
    } else if (size >= 5 && size <= 10) {
        sleepTime = 200;
    } else {
        sleepTime = 100;
    }
    return sleepTime;
}

int Snake::countList() {
    int size = 0;
    Point *tmpPoint = pHead;
    while (tmpPoint != NULL) {
        size++;
        tmpPoint = tmpPoint->next;
    }
    return size;
}

int Snake::getScore() {
    int size = countList();
    int score = (size - 3) * 10;
    return score;
}
