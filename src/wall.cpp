#include "wall.h"
#include <iostream>

using namespace std;

void Wall::initWall() {
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            // 放墙壁
            if (i == 0 || j == 0 || i == ROW - 1 || j == COL - 1) {
                gameArray[i][j] = '*';
            } else {
                gameArray[i][j] = ' ';
            }
        }
    }
}

void Wall::drawWall() {
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            cout << gameArray[i][j] << " ";
        }
        if (i == 5){
            cout << "  create by fanfan";
        }
        if (i == 6){
            cout << "  a: left";
        }
        if (i == 7){
            cout << "  d: right";
        }
        if (i == 8){
            cout << "  w: up";
        }
        if (i == 9){
            cout << "  s: bottom";
        }
        cout << endl;
    }
}

void Wall::setWall(int x, int y, char c) {
    gameArray[x][y] = c;
}

char Wall::getWall(int x, int y) {
    return gameArray[x][y];
}
