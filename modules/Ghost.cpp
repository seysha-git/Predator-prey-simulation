#include "Ghost.h"
#include <iostream>
#include <cmath>

void Ghost::update() {
    if ((pos.x + radius + vel_x) >= s.windowWidth - s.freezone_width+20) {
        vel_x *= -1;
    }
    else if (pos.x + vel_x<= s.freezone_width) {
        vel_x *= -1;
    }

    if ((pos.y + radius + vel_y) >= s.windowHeight) {
        vel_y *= -1;
    }
    else if (pos.y + vel_y <= 0) {
        vel_y *= -1;
    }

    pos.x += vel_x;
    pos.y += vel_y;
}

void Ghost::draw(TDT4102::AnimationWindow *main_window) {
    std::cout << pos.x << "  " << pos.y;
    main_window->draw_circle(pos, radius, TDT4102::Color::black);
}

