//
//  BoardGame.h
//  CS_204_HW6
//
//  Created by Ege Berk Yurtkoruyan on 15.04.2020.
//  Copyright © 2020 cs204 hw. All rights reserved.
//

#ifndef BoardGame_h
#define BoardGame_h
#include<iostream>
class Board{
    
public:
    
    Board();
    void displayBoard();
    char& getOwner(int, int);
    void setOwner(int, int, char);
    bool isFull();
    int countOwnedCells(char);
    
private:
    char theBoard[2][6];

};

class Player{

public:
    
    Player(Board&, char, int);
    int getRow();
    int getCol();
    void move(int);
    void claimOwnership();
    bool wins();

    
private:
    int currentRow , currentCol;
    char player_char;
    int route;
    Board & game_board;
};
#endif /* BoardGame_h */
