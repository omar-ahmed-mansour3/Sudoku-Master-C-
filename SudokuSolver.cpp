#include "SudokuSolver.hpp"

bool SudokuSolver:: solveBoard(SudokuBoard &sudokuBoard)
{
    //base condition
    if(sudokuBoard.isBoardFull()) {return true;}

    int row,col;


    //find the first empty slot 
    bool found =0;
    for(int i =0; i<9 && !found; i++)
    {
        for(int j=0; j<9;j++)
        {
            if(sudokuBoard.isSlotEmptyInternal(i,j))
            {
                row =i;
                col=j;
                found =1;
                break;
            }
        }
    }

    //recursive loop

    for(int i=1; i<=9;i++)
    {
        if(sudokuBoard.isEntryCorrectInternal(row,col,i))//check if entry is valid according to rules
        {
            //fill the slot and recursive call
            sudokuBoard.modifyBoardInternal(row,col,i);

            if(solveBoard(sudokuBoard))
            {
                return true; 
            }
            sudokuBoard.modifyBoardInternal(row,col,0);//if this solution causes other slots to be un-solvable--> reset it
        }
    }

    return false;
    
}