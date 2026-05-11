#include"SudokuGame.hpp"

void SudokuGame::run()
{
    int mode =0; 
    while(mode !=5 )
    {
        srand(time(0));
        sudokuBoard.printBoard();
        cout<<"please choose a number from 1 to 5"<<endl;
        cout<<"1) Enter a move"<<endl
            <<"2) Solve automatically"<<endl
            <<"3) Generate new puzzle"<<endl
            <<"4) load or Save current puzzle to file (not availible rn)"<<endl
            <<"5) Exit"<<endl;
        cin>> mode;

        if(mode ==1)
        {
            handleUserMove();
        }

        else if(mode ==2)
        {
            if(sudokuSolver.solveBoard(sudokuBoard)) 
            {
                cout << "Puzzle solved successfully!" << endl;
            }       
            else 
            {
                cout << "Error: This puzzle has no solution." << endl;
            }
        }
        else if(mode==3)
        {
            sudokuBoard = SudokuBoard(); 
            sudokuGenerator.generateRandomBoard(sudokuBoard);
            cout << "New puzzle generated!" << endl;
        }
    }
}


void SudokuGame :: handleUserMove()
{
    int row,col,val;
    cout<<"please insert row, col ,value, in that order"<<endl;
    cin>>row>>col>>val;
    
    //check value
    if(val<1 || val >9)
    {
        cout<<"incorrect value"<<endl;
        
    }

    else if(row<1 || row >9)
    {
        cout<<"incorrect row"<<endl;
    }

    else if(col<1 || col >9)
    {
        cout<<"incorrect col"<<endl;
    }

    else
    {
        //check if slot is already occupied
        if(!sudokuBoard.isSlotEmpty(row, col))  
        {
            cout<<"slot occupied"<<endl;
        }

        else 
        {
            //check the value and location is correct according to sudoku completion rules
            if(sudokuBoard.modifyBoard(row,col,val))
            {
                cout<<"Move accepted!" <<endl;
            }

            else //incorrect according to sudoku rules
            {
                cout<<"incorrect according to sudoku rules"<<endl;
            }
                
        }
    }
}
 