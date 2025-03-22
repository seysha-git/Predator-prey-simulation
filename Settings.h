#pragma once

#include "AnimationWindow.h"
#include <string>

struct Settings {
    const int windowPositionX = 300;
    const int windowPositionY = 100;
    const int windowWidth = 1000;
    const int windowHeight = 800;
    const int title_font = 40;
    const static constexpr int pad = 30;
    
    const static constexpr int nav_width = 1000;
    const static constexpr int nav_height = 80;
    const static constexpr int num_rows = 17;
    const static constexpr int num_cols = 24;
    const static constexpr int gap = 10;
    const static constexpr int size = 30;


    const TDT4102::Point navLoc{0, 0};
    const TDT4102::Point titleLoc{40, 20};
    const std::string titleMessage = "Doodlebug vs Ant";

    const TDT4102::Point toggleBtnPosition {windowWidth-200, 5};
    const unsigned int btnW = 150;
    const unsigned int btnH = 75;
    const std::string btnLabel = "Start";

    TDT4102::Color navColor = TDT4102::Color::dark_green;
    TDT4102::Color cellColor = TDT4102::Color::dark_grey;
    TDT4102::Color titleColor = TDT4102::Color::white_smoke;

    
};




