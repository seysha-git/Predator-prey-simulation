#pragma once
#include "GameObject.h"


class Ghost : public GameObject{
    public:
    //Medlems funksjoner
    void update();
    void move();
};