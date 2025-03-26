#pragma once
#include "GameObject.h"


class Human : public GameObject{
    public:
    int vx = 5;
    int vy = 5;
    int width = 50; 
    int height = 50;
    void move(char state);
    void update();
};
