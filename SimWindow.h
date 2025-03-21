#pragma once

#include "AnimationWindow.h"
#include "settings.h"
#include "widgets/Button.h"
#include "widgets/TextInput.h"
#include "widgets/DropdownList.h"

#include <string>
#include <vector>
#include <functional>

class SimWindow : public TDT4102::AnimationWindow {
public:
    static constexpr int pad = 30;
    static constexpr int btnW = 200;
    static constexpr int btnH = 90;

    SimWindow(TDT4102::Point position, int width, int height, const std::string& screen_title);
private:
    
};
