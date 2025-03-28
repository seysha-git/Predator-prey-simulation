#include "Human.h"
#include <iostream>


void Human::move(TDT4102::AnimationWindow *main_window){

    if(main_window->is_key_down(KeyboardKey::D)){
        pos.x += vx;
        //std::cout << '\n' << "Move: " << pos.x << '\n';
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
    std::cout << '\n' << "Moving position: " << pos.x << '\n';
}

void Human::update(TDT4102::AnimationWindow *main_window){
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
    move(main_window);
}

void Human::set_start_pos(int new_x, int new_y){
    pos.x = new_x;
    pos.y = new_y;
}


bool Human::sheep_collided(std::shared_ptr<Sheep> sheep) {
    int sheep_pos_x = sheep->pos.x;
    int sheep_pos_y = sheep->pos.y;
    int sheep_width = sheep->width;
    int sheep_height = sheep->height;

    std::cout << "Sheep: " << sheep_pos_x << " Me: " << pos.x << "||" << pos.y;
    return true;
}


void Human::draw(TDT4102::AnimationWindow *main_window) {
    //std::cout << "Pos" << pos.x << " " << pos.y << '\n';
    main_window->draw_rectangle(pos, width, height, color);
}
