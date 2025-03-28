#pragma once

#include "AnimationWindow.h"
#include "Settings.h"
#include "./modules/Human.h"
#include "./modules/Ghost.h"
#include "./modules/Sheep.h"
#include "./modules/GameObject.h"
#include <string>
#include <vector>
#include <functional>

class GameWindow {
public:
    //Medlemsvariabler og klasser
    Settings s;
    TDT4102::AnimationWindow window{200, 80, s.windowWidth, s.windowHeight};
    std::vector<std::shared_ptr<GameObject>> all_objects;
    std::vector<std::shared_ptr<Ghost>> ghosts;
    std::vector<std::shared_ptr<Sheep>> sheeps;
    TDT4102::Point topLeftCorner {0, 0};
    Ghost start_ghost;
    std::shared_ptr<Human> player{new Human{}};
    int freezone_width = 200;
    TDT4102::Point topRightCorner {s.windowWidth - freezone_width, 0};
    int curr_sheeps = 0;
    bool playing;
    bool running = true;

    //Medlemsfunksjoner
    void new_game();
    void run();
    void update();
    void add_object(std::shared_ptr<GameObject> new_object);
    void add_sheep(std::shared_ptr<Sheep> new_sheep);
    void add_ghost(std::shared_ptr<Ghost> new_ghost);
    void show_start_screen();
    void show_over_screen();

    void draw_animation();
    //void draw_text();
};
