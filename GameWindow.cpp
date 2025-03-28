#include "GameWindow.h"
#include <iostream>

void GameWindow::run(){
    playing     = true;
    while(!window.should_close()){
        update();
        draw_animation();
        window.next_frame();
    }
}
void GameWindow::add_object(std::shared_ptr<GameObject> new_object){
    all_objects.emplace_back(new_object);
}
void GameWindow::add_sheep(std::shared_ptr<Sheep> new_sheep){
    sheeps.emplace_back(new_sheep);
}
void GameWindow::add_ghost(std::shared_ptr<Ghost> new_ghost){
    ghosts.emplace_back(new_ghost);
}

void GameWindow::new_game(){
    player->set_start_pos(100, 300);
    add_object(player);
    add_object(std::make_shared<Ghost>(start_ghost));
    add_ghost(std::make_shared<Ghost>(start_ghost));
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
    for(int i = 0; i < all_objects.size(); i++){
        all_objects.at(i)->update(&window);
    }
    //spawn right_side sheeps
    while(curr_sheeps < s.max_sheep_danger){
        Sheep new_sheep;
        add_object(std::move(std::make_shared<Sheep>(new_sheep)));
        add_sheep(std::move(std::make_shared<Sheep>(new_sheep)));
        curr_sheeps += 1;
    }
    //check colission between player and sheep
    
    for(int i = 0; i < sheeps.size(); i++){
      if(player->sheep_collided(sheeps.at(i))){
        std::cout << " " << '\n';
      }
    }
    



    
}
void GameWindow::draw_animation(){
    window.draw_rectangle(topLeftCorner, freezone_width, s.windowHeight);
    window.draw_rectangle(topRightCorner, freezone_width, s.windowHeight);

    for(int i = 0; i < all_objects.size(); i++){
        all_objects.at(i)->draw(&window);
    }

}



