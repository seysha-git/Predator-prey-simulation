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

    int human_pos_x = this->pos.x;
    int human_pos_y = this->pos.y;
    int human_width = this->width;
    int human_height = this->height;

    bool no_overlap_x = (human_pos_x + human_width <= sheep_pos_x) || (sheep_pos_x + sheep_width <= human_pos_x);
    
    bool no_overlap_y = (human_pos_y + human_height <= sheep_pos_y) || (sheep_pos_y + sheep_height <= human_pos_y);
    
    return !(no_overlap_x || no_overlap_y);
}


void Human::draw(TDT4102::AnimationWindow *main_window) {
    //std::cout << "Pos" << pos.x << " " << pos.y << '\n';
    main_window->draw_rectangle(pos, width, height, color);
}
