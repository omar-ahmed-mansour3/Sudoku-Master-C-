#ifndef SUDOKUBOARD_HPP
#define SUDOKUBOARD_HPP

#include <vector> 
#include <iostream>
using namespace std;

class SudokuBoard {

private:
   vector<vector<int>> board; 
   

public:
    // no arg const
    SudokuBoard();

    // BACKEND:0-8 indices
    bool modifyBoardInternal(int row, int col, int val);
    bool isEntryCorrectInternal(int row, int col, int val) const;
    bool isSlotEmptyInternal(int row, int col) const;


    // FRONTEND: These always expect 1-9 indices from the user
    bool modifyBoard(int row , int col, int  val); 
    bool isEntryCorrect(int row, int col, int val) const;
    bool isSlotEmpty(int row, int col)const;

    bool isBoardFull() const;
    void printBoard() const;

    // save file function 

    //load file function

};

#endif