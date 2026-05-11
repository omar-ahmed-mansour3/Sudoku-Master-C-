#ifndef SUDOKUGENERATOR_HPP
#define SUDOKUGENERATOR_HPP
#include "SudokuBoard.hpp"
#include "SudokuSolver.hpp"
#include <cstdlib>


class SudokuGenerator
{
    private:
        SudokuSolver sudokuSolver;

    public:
    
    void generateRandomBoard(SudokuBoard &board);
};


#endif