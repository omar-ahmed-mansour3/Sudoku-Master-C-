#include "SudokuGenerator.hpp"

void SudokuGenerator::generateRandomBoard(SudokuBoard &board)
{
    sudokuSolver.solveBoard(board);//this will always result in the same board 
    
    int numbers_removed,row,col;
    numbers_removed = (rand()%40) +20; // delete from 20 up to 60 slots
    for(int i =0; i< numbers_removed; i++)
    {
        row = rand()%9; 
        col = rand()%9 ;
        board.modifyBoardInternal(row,col,0);

    }
}

