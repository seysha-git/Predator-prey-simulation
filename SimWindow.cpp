#include "SimWindow.h"
#include <iostream>

SimWindow::SimWindow(TDT4102::Point position, int width, int height, const std::string& screen_title)
    : AnimationWindow{position.x, position.y, width, height, screen_title} 
{
    Settings settings;
    draw_rectangle(settings.navLoc, settings.nav_width, settings.nav_height, settings.navColor);
    draw_text(settings.titleLoc,settings.titleMessage, settings.titleColor, settings.title_font);
}

