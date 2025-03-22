#include "SimWindow.h"
#include <iostream>

    SimWindow::SimWindow(TDT4102::Point position, int width, int height, const std::string& screen_title): 
        AnimationWindow{position.x, position.y, width, height, screen_title},
        toggleBtn{s.toggleBtnPosition, s.btnW, s.btnH, s.btnLabel}
    {
        
        draw_rectangle(s.navLoc, s.nav_width, s.nav_height, s.navColor);
        draw_text(s.titleLoc,s.titleMessage, s.titleColor, s.title_font);
        draw_grid();
        add(toggleBtn);
        toggleBtn.setCallback(std::bind(&SimWindow::toggle_start_stop, this));
        
    }

    void SimWindow::draw_grid(){
        for(int i = 0; i < s.num_rows; i++){
            for(int j = 0; j < s.num_cols; j++){
                draw_rectangle({30+j*(s.size + s.gap), 100+i*(s.size+s.gap)}, s.size, s.size, s.cellColor);
            }
        }
    }

    void SimWindow::toggle_start_stop(){
        if(toggle_state){
            toggle_state = 0;
            toggleBtn.setLabel("Stop");
        }
        else{
            toggle_state = 1;
            toggleBtn.setLabel("Start");
        }

    }

