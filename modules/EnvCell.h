#pragma once
#include "AnimationWindow.h"
#include "Settings.h"
#include "Organism.h"

class EnvCell{
    public:
    Settings s;
    EnvCell(int i, int j);
    int i, j;
    TDT4102::Color cellColor;
};