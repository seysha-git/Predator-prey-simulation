#include "GameWindow.h"
#include <iostream>

void GameWindow::run(){
    playing = true;
    while(!window.should_close()){
        update();
        draw_animation();
        window.next_frame();
    }
}
void GameWindow::add_object(GameObject *new_object){
    all_objects.push_back(new_object);
}

void GameWindow::new_game(){
    player.set_start_pos(100, 300);
    add_object(&player);
    add_object(&start_ghost);
    run();
}

void GameWindow::show_start_screen(){
    std::cout << "Showing start screen";
}

void GameWindow::show_over_screen(){
    std::cout << '\n' << "Show over screen";
    running = false;
}

void GameWindow::update(){
    player.update();
    start_ghost.update();

    player.move(&window);
}
void GameWindow::draw_animation(){
    window.draw_rectangle(topLeftCorner, freezone_width, s.windowHeight);
    window.draw_rectangle(topRightCorner, freezone_width, s.windowHeight);

    for(int i = 0; i < all_objects.size(); i++){
        all_objects.at(i)->draw(&window);
    }
}



