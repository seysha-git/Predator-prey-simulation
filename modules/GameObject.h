#pragma once
#include <AnimationWindow.h>
#include "../Settings.h"

class GameObject {
public:
//Medlems variabler 
Settings s;
int x = 50;
int y = s.windowHeight/2;
int width, height;
TDT4102::Color color = s.cellColor;
TDT4102::Point pos {x, y};

//Medlems funksjoner
GameObject() : width(50), height(50) {} 
GameObject(int width, int height) : width(width), height(height) {};
void update();
};