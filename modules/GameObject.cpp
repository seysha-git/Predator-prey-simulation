#include "GameObject.h"
#include <iostream>

void GameObject::draw(TDT4102::AnimationWindow *main_window){
    main_window->draw_rectangle(pos, width, height, color);

}