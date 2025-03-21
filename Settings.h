#pragma once

#include "AnimationWindow.h"
#include <string>

struct Settings {
    int windowPositionX = 300;
    int windowPositionY = 100;
    int windowWidth = 1000;
    int windowHeight = 800;
    int title_font = 40;

    static constexpr int nav_width = 1000;
    static constexpr int nav_height = 80;

    TDT4102::Point navLoc{0, 0};
    TDT4102::Point titleLoc{40, 20};
    std::string titleMessage = "Doodlebug vs Ant";


    TDT4102::Color navColor = TDT4102::Color::dark_green;
    TDT4102::Color titleColor = TDT4102::Color::white_smoke;
};




