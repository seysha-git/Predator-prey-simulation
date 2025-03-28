#include "GameWindow.h"
#include <iostream>

void GameWindow::run(){
    playing = true;
    while(!window.should_close() && playing){
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
void GameWindow::delete_sheep(std::shared_ptr<Sheep> new_sheep){
    all_objects.erase(std::remove(all_objects.begin(), all_objects.end(), new_sheep), all_objects.end());
    sheeps.erase(std::remove(sheeps.begin(), sheeps.end(), new_sheep), sheeps.end());
    curr_sheeps -= 1;
}


void GameWindow::new_game(){
    player->set_start_pos(100, 300);
    add_object(player);
    //add_object(std::make_shared<Ghost>(start_ghost));
    //add_ghost(std::make_shared<Ghost>(start_ghost));
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
        std::shared_ptr<Sheep> new_sheep{new Sheep{}};
        add_object(new_sheep);
        add_sheep(new_sheep);
        //add_sheep(std::move(std::make_shared<Sheep>(new_sheep)));
        curr_sheeps += 1;
    }

    //Spawn ghosts in enemy zone. 
    while(curr_ghosts < max_ghosts){
        std::shared_ptr<Ghost> new_ghost{new Ghost{}};
        add_object(new_ghost);
        add_ghost(new_ghost);
        curr_ghosts += 1;
    }

    //check colission between player and sheep
    for(int i = 0; i < sheeps.size(); i++){
      if(player->sheep_collided(sheeps.at(i))){
        //std::cout << "Hit sheep";
        player->carry_sheep();
        delete_sheep(sheeps.at(i));

      }
    }

    //Check colission between player and ghost
    for(int i = 0; i < ghosts.size(); i++){
        if(player->ghost_collided(ghosts.at(i))){
            playing = false;
        }
    }
    if(player->carry && player->left_freezone_collided(freezone_width)){
        max_ghosts += 1;
        player->release_sheep();       
    }
}
void GameWindow::draw_animation(){
    window.draw_rectangle(topLeftCorner, freezone_width, s.windowHeight);
    window.draw_rectangle(topRightCorner, freezone_width, s.windowHeight);

    for(int i = 0; i < all_objects.size(); i++){
        all_objects.at(i)->draw(&window);
    }

}



