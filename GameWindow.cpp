#include "GameWindow.h"
#include <iostream>



void GameWindow::run(){
    playing = true;
    while(!window.should_close()){
        events();
        update();
        draw_animation();
        window.next_frame();
    }
}

void GameWindow::new_game(){
    xPosition = 0;
    //ghosts = {};
    //hinderences = {};
    std::cout << "New game starting";
    run();
}

void GameWindow::show_start_screen(){
    std::cout << "Showing start screen";
}

void GameWindow::show_over_screen(){
    std::cout << "Show over screen";
    running = false;
}

void GameWindow::update(){
    player.update();
}
void GameWindow::draw_animation(){
    window.draw_rectangle(topLeftCorner, freezone_width, s.windowHeight);
    window.draw_rectangle(topRightCorner, freezone_width, s.windowHeight);
    window.draw_rectangle(player.pos, player.width, player.height, player.color);
    
}

void GameWindow::events(){
    //Player controls
    if(window.is_key_down(KeyboardKey::D)){
        player.move('D');
    }
    if(window.is_key_down(KeyboardKey::W)){
        player.move('W');
    }
    if(window.is_key_down(KeyboardKey::S)){
        player.move('S');
    }
    if(window.is_key_down(KeyboardKey::A)){
        player.move('A');
    }
}

