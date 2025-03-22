#pragma once
#include <Settings.h>
#include "modules/EnvCell.h"

class EnvBoard{
    private: 
        EnvCell* board[20][20] = {};
    public:
        EnvBoard();
        ~EnvBoard(){
            for(int i = 0; i < s.num_rows; i++){
                for(int j = 0; j < s.num_cols; j++){
                    delete board[i][j];
                    board[i][j] = nullptr;
                }
            }
        }
        Settings s;
        //Medlemsfunksjoner
        void getData(); // data for den matematiske modellen
        void createGrid(); // lag gridden i starten
        void updateGrid();
        void printGrid();


    
};