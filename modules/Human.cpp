#include "Human.h"



void Human::move(char state){
    switch (state)
    {
    case 'W':
        pos.y -= vy;
        break;
    
    case 'S':
        pos.y += vy;
        break;
    
    case 'A':
        pos.x -= vx;
        break;
    
    case 'D':
        pos.x += vx;
        break;
    
    default:
        break;
    }
}

void Human::update(){
    if(pos.x + width>= s.windowWidth){
        pos.x = s.windowWidth - width;
    }
    if(pos.y + height>= s.windowHeight){
        pos.y = s.windowHeight - height;
    }
    if(pos.y<=0){
        pos.y = 0;
    }
    if(pos.x<= 0){
        pos.x = 0;
    }
}