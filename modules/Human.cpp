#include "Human.h"
#include <iostream>


void Human::move(TDT4102::AnimationWindow *main_window){
    if(main_window->is_key_down(KeyboardKey::D)){
        pos.x += vx;
        std::cout << '\n' << "Position: " << pos.x << '\n';
    }
    if(main_window->is_key_down(KeyboardKey::W)){
        pos.y -= vy;
    }
    if(main_window->is_key_down(KeyboardKey::S)){
        pos.y += vy;
    }
    if(main_window->is_key_down(KeyboardKey::A)){
        pos.x -= vx;
    }
}

void Human::update(){
    if(pos.x + width >= s.windowWidth){
        pos.x = s.windowWidth - width;
    }
    if(pos.y + height >= s.windowHeight){
        pos.y = s.windowHeight - height;
    }
    if(pos.y<=0){
        pos.y = 0;
    }
    if(pos.x<= 0){
        pos.x = 0;
    }
}

void Human::set_start_pos(int new_x, int new_y){
    pos.x = new_x;
    pos.y = new_y;
}

void Human::draw(TDT4102::AnimationWindow *main_window) {
    std::cout << "Drawing human: (" << pos.x << ", " << pos.y << ")\n";
    main_window->draw_rectangle(pos, width, height, color);
}