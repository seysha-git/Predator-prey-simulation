#pragma once

#include "AnimationWindow.h"
#include "Settings.h"
#include "./modules/Human.h"
#include "./modules/Ghost.h"
#include "./modules/Hinderence.h"
#include "./modules/GameObject.h"
#include <string>
#include <vector>
#include <functional>

class GameWindow {
public:
    //Medlemsvariabler og klasser
    Settings s;
    TDT4102::AnimationWindow window{200, 80, s.windowWidth, s.windowHeight};
    //Medlemsvariabler
    bool playing;
    std::vector<Ghost> ghosts;
    //std::vector<Hinderence> hinderences;
    std::vector<GameObject*> all_objects;
    TDT4102::Point topLeftCorner {0, 0};
    int freezone_width = 200;
    TDT4102::Point topRightCorner {s.windowWidth - freezone_width, 0};
    bool running = true;
    int xPosition;
    Human player;
    Ghost start_ghost;
    //Medlemsfunksjoner
    void new_game();
    void run();
    void events();
    void update();
    void add_object(GameObject *new_object);
    void show_start_screen();
    void show_over_screen();

    void draw_animation();
    void draw_text();
};
