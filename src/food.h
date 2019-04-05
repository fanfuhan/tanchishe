#ifndef TANCHISHE_FOOD_H
#define TANCHISHE_FOOD_H

#include <iostream>
#include "wall.h"
using namespace std;

class Food{
public:
    Food(Wall &tempWall);
    // 设置食物
    void setFood();
private:
    int foodX;
    int foodY;
    Wall &wall;
};
#endif //TANCHISHE_FOOD_H
