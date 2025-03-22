#pragma once

#include "AnimationWindow.h"
#include "Settings.h"
#include "EnvBoard.h"
#include "widgets/Button.h"

#include <string>
#include <vector>
#include <functional>

class SimWindow : public TDT4102::AnimationWindow {
public:
    //Medlemsvariabler og klasser
    int toggle_state = 1;
    SimWindow(TDT4102::Point position, int width, int height, const std::string& screen_title);
    Settings s;
    // Input GUI elementer
    TDT4102::Button toggleBtn;
    


    //Medlemsfunksjoner
    void draw_grid();
    void update_grid();

    void toggle_start_stop();

    
};
