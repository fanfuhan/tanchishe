#ifndef TANCHISHE_SNAKE_H
#define TANCHISHE_SNAKE_H

#include <iostream>
#include "wall.h"
#include "food.h"

using namespace std;

class Snake {
public:
    Snake(Wall &tempWall, Food &tempFood);

    enum {
        UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd'
    };
    struct Point {
        int x;
        int y;
        Point *next;
    };

    // 初始化
    void initSnake();

    // 销毁节点
    void destroyPoint();

    // 添加节点
    void addPoint(int x, int y);

    // 删除节点
    void delPoint();

    // 移动蛇
    bool move(char key);

    // 设定难度
    // 获取刷屏时间
    int getSleepTime();

    // 获取蛇身段
    int countList();

    // 获取分数
    int getScore();

private:
    Point *pHead;
    Wall &wall;
    Food &food;
    bool isRool;  // 判断循环表示
};

#endif //TANCHISHE_SNAKE_H
