#pragma once
#include "GameObject.h"


class Human : public GameObject{
    public:
    int vx = 5;
    int vy = 5;
    int width = 50; 
    int height = 50;
    TDT4102::Point pos {x, y};
    void move(TDT4102::AnimationWindow *main_window);
    void update();
    void set_start_pos(int new_x, int new_y);
    void draw(TDT4102::AnimationWindow *main_window) override;
};
