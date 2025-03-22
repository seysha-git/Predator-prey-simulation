#include <iostream>
#include "SimWindow.h"

int main() {
    Settings settings;
    SimWindow window({settings.windowPositionX, settings.windowPositionY}, settings.windowWidth, settings.windowHeight, "My window");
    window.wait_for_close();
    return 0; 
}
