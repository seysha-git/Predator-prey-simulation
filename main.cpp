#include <iostream>
#include "SimWindow.h"

int main() {
    Settings settings;
    
    TDT4102::Color navColor = TDT4102::Color::dark_green;
    TDT4102::Color titleColor = TDT4102::Color::white_smoke;
    
    SimWindow window({settings.windowPositionX, settings.windowPositionY}, settings.windowWidth, settings.windowHeight, "My window");
    window.wait_for_close();
    return 0; 
}
