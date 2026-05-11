#ifndef SUDOKUGAME_HPP
#define SUDOKUGAME_HPP

#include "SudokuBoard.hpp"
#include "SudokuSolver.hpp"
#include "SudokuGenerator.hpp"
#include <iostream>
class SudokuGame
{
    private:
        SudokuBoard sudokuBoard;
        SudokuSolver sudokuSolver;
        SudokuGenerator sudokuGenerator;

    public:
        void run();
        void handleUserMove();
};

#endif