//
//  BoardGame.cpp
//  CS_204_HW6
//
//  Created by Ege Berk Yurtkoruyan on 15.04.2020.
//  Copyright © 2020 cs204 hw. All rights reserved.
//

#include "BoardGame.h"

/*////////////////////////--------  THE BOARD CLASS --------////////////////////////*/
// CONSTRUCTOR
Board::Board(){
    for(int r = 0 ; r < 2 ; r++){
        for(int c = 0 ; c < 6 ; c++)
            theBoard[r][c] = '-';
    }
}

/*//////////////////////////////////////////////////////////////////////////////////*/
// PRINTS THE BOARD CHAR BY CHAR
void Board::displayBoard(){
    
    for(int r = 0 ; r < 2 ; r++){
        for(int c = 0 ; c < 6 ; c++)
            std::cout << theBoard[r][c] << " ";
        
        std::cout << "\n";
    }
}

/*//////////////////////////////////////////////////////////////////////////////////*/
// RETURNS THE CHARACTER AT GIVEN POINTS.
char& Board::getOwner(int x, int y){
    return theBoard[x][y];
}

/*//////////////////////////////////////////////////////////////////////////////////*/
// CHANGES THE GIVEN POINT IF IT HAS NOT BEEN CHANGED PREVIOUSLY.
void Board::setOwner(int x, int y, char character){
    if(getOwner(x, y) == '-'){
        char& cicikus = getOwner(x, y);
        cicikus = character;
    }
}

/*//////////////////////////////////////////////////////////////////////////////////*/
// RETURNS TRUE IF THE BOARD IS NOT FILLED COMPLETELY.
bool Board::isFull(){
    
    for(int r = 0 ; r < 2 ; r++){
        for(int c = 0 ; c < 6 ; c++){
            
            if(theBoard[r][c] == '-')
                return false;
        }
    }
    return true;
}
/*//////////////////////////////////////////////////////////////////////////////////*/
// COUNTS THE CELLS OWNED BY GIVEN CHARACTER (PLAYER)
int Board::countOwnedCells(char character){
    
    int counter = 0;
    
    for(int r = 0 ; r < 2 ; r++){
        for(int c = 0 ; c < 6 ; c++){
            if (theBoard[r][c] == character)
                counter++;
        }
    }
    return counter;
}

/*//////////////////////////////////////////////////////////////////////////////////*/

//
//                  *      *
//
//
//               \____________/
//

/*////////////////////////--------  THE PLAYER CLASS --------////////////////////////*/
// CONSTRUCTOR
Player::Player(Board & myBoard, char character, int num)
:game_board(myBoard){
    currentRow = 0;
    currentCol = 0;
    player_char = character;
    route = num;
}

/*//////////////////////////////////////////////////////////////////////////////////*/

int Player::getRow(){
    return currentRow;
}

/*//////////////////////////////////////////////////////////////////////////////////*/

int Player::getCol(){
    return currentCol;
}

/*//////////////////////////////////////////////////////////////////////////////////*/

void Player::move(int dice){
    
    while(dice != 0){
        if(route == 1){
            if(currentRow == 0){
                if(currentCol != 5)
                    currentCol++;
                else
                    currentRow++;
            }else{
                if(currentCol != 0)
                    currentCol--;
                else
                    currentRow--;
            }
        }else{
            if(currentRow == 0){
                if(currentCol != 0)
                    currentCol--;
                else
                    currentRow++;
            }else{
                if(currentCol != 5)
                    currentCol++;
                else
                    currentRow--;
            }
        }
        dice--;
    }
}

/*//////////////////////////////////////////////////////////////////////////////////*/

void Player::claimOwnership(){
    game_board.setOwner(currentRow, currentCol, player_char);
}

/*//////////////////////////////////////////////////////////////////////////////////*/

bool Player::wins(){
    int num = game_board.countOwnedCells(player_char);
    
    if(num > 6)
        return true;
    else
        return false;
}

/*//////////////////////////////////////////////////////////////////////////////////*/
