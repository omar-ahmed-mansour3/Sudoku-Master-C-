#include "SudokuBoard.hpp"
    // no arg const
    // initializes all board as empty 
    SudokuBoard::SudokuBoard(): board (9,vector<int>(9,0)) {}
   


    void SudokuBoard::printBoard() const 
    {
        cout << "--- Sudoku Board ---" << endl;
        for (int r = 0; r < 9; ++r) 
        {
            // --------- every 3 rows
            if (r % 3 == 0) {
                cout << "------+-------+------" <<endl;
            }

            for (int c = 0; c < 9; ++c) 
            {
                // Print '|' every 3 columns
                if (c % 3 == 0 && c != 0) 
                {
                    cout << "| ";
                }

                // check if empty
                if (board[r][c] == 0) 
                {
                    cout << ". "; 
                } 
                
                else 
                {
                    cout << board[r][c] << " ";
                }
            }
            cout <<endl;
            
        }
        cout << "------+-------+------" <<endl;
    }

    bool SudokuBoard::isBoardFull() const 
    {
        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++) 
            {
                if (board[r][c] == 0) 
                {
                    return false; 
                }
            }
        }
        return true; 
    }


    //*******************************FUNCTIONS FOR INTERNAL USE, INDEX FROM 0 TO 8 *************************/
    bool SudokuBoard::modifyBoardInternal(int row , int col, int  val)
    {
        //checking logic
        if(val<0 || val >9) return false;
        //checkingpuzzle
        if(!isEntryCorrectInternal(row, col, val)) return false;

        board[row][col] = val;
        return true;
        
    }

    bool SudokuBoard:: isEntryCorrectInternal(int row, int col , int val) const 
    {
        if (val == 0) return true;// needed for the sudoko solver and generator to be able to reset board

        for(int i =0; i <9 ; i++)//check row
        {
            if(val == board[row][i])return false;
        }

        for(int i =0; i <9 ; i++)//check col
        {
            if(val == board[i][col]) return false;
        }

        //check the box
        // get top-left corner of the 3x3 box
        int startRow = row - (row % 3);
        int startCol = col - (col % 3);
        for( int r = startRow ; r < startRow +3 ; r++)
        {
            for(int c = startCol; c < startCol+3; c++)
            {
                if(val == board[r][c]) return false;
            }
        }
        return true;
    }

    bool SudokuBoard:: isSlotEmptyInternal(int row, int col) const
    {
        if(board[row][col]==0) return true;
        return false;
    }


    //*******************************FUNCTIONS FOR user  USE, INDEX FROM 1 TO 9 *************************/
    bool SudokuBoard::modifyBoard(int row, int col, int val) 
    {
        return modifyBoardInternal(row - 1, col - 1, val);
    }

    bool SudokuBoard::isEntryCorrect(int row, int col, int val) const 
{
    return isEntryCorrectInternal(row - 1, col - 1, val);
}

    bool SudokuBoard::isSlotEmpty(int row, int col) const 
    {
        return isSlotEmptyInternal(row - 1, col - 1);
    }





    // save file function 

    //load file function
    


