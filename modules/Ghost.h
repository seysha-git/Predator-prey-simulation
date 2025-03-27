#pragma once
#include "GameObject.h"
#include <cmath>
#include <random>


class Ghost : public GameObject{
    public:
    //Medlems funksjoner
    int vel_x = 3;
    int vel_y = 2;
    double radius{50};

    std::random_device rd;
    std::default_random_engine generator{rd()};
    std::uniform_int_distribution<int> distribution_x{s.freezone_width, s.windowWidth - s.freezone_width};
    std::uniform_int_distribution<int> distribution_y{static_cast<int>(radius), s.windowHeight - static_cast<int>(radius)};
    int start_x = distribution_x(generator);
    int start_y = distribution_y(generator);
    TDT4102::Point pos {start_x, start_y};
    void update();
    void draw(TDT4102::AnimationWindow *main_window) override;
};