#include "TicTacToe.hpp"

#include <iostream>
#include <cassert>

TicTacToe::TicTacToe()
{
    setBoard();
}

void
TicTacToe::setBoard()
{
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board_[i][j] = 0;
        }
    }
}

void
TicTacToe::play()
{
    std::cout << "Play against player: 1." << std::endl;
    std::cout << "Play against computer: 2." << std::endl;
    std::cout << "\tpick > ";
    int against;
    std::cin >> against;
    if (against < 1 || against > 2) {
        std::cerr << "Error 1: wrong pick." << std::endl;
        ::exit(1);
    }
    against == 1 ? againstPlayer() : againstComputer();
}

void
TicTacToe::againstPlayer()
{
    int row;
    int column;
    int turn = 0;
    printBoard();
    while (isGameNotOver()) {
        playerTurn(row, column, turn);
    }
    if (isWon()) {
        winnerIs(board_[row][column]);
    } else {
        std::cout << "It is a draw." << std::endl;
    }
}

void
TicTacToe::againstComputer()
{
    std::cout << "\nPlayer plays first: 1." << std::endl;
    std::cout << "Computer plays first: 2." << std::endl;
    std::cout << "\tpick > ";
    int first;
    std::cin >> first;
    if (first < 1 || first > 2) {
        std::cerr << "Error 1: wrong pick." << std::endl;
        ::exit(1);
    }
    srand(time(0));
    int row;
    int column;
    int turn = 0;
    printBoard();
    if (first == 1) {
        while (isGameNotOver()) {
            playerTurn(row, column, turn);
            std::cout << std::endl;
            if (isGameNotOver()) {
                computerTurn(row, column, turn);
            }
        }
    } else {
        while (isGameNotOver()) {
            std::cout << std::endl;
            computerTurn(row, column, turn);
            std::cout << std::endl;
            if (isGameNotOver()) {
                playerTurn(row, column, turn);
            }
        }
    }
    if (isWon()) {
        winnerIs(board_[row][column]);
    } else {
        std::cout << "It is a draw." << std::endl;
    }
}

void 
TicTacToe::playerTurn(int &row, int &column, int &turn)
{
    std::cout << "row = ";
    std::cin >> row;
    std::cout << "column = ";
    std::cin >> column;
    if (row < 0 || row >= SIZE || column < 0 || column >= SIZE || board_[row][column] > 0) {
        std::cout << "Try again." << std::endl;
        --turn;
        return;
    }
    board_[row][column] = (turn % 2 == 0 ? 1 : 2);
    ++turn;
    printBoard();
}

void
TicTacToe::computerTurn(int &row, int &column, int &turn)
{
    do {
        row = rand() % SIZE;
        column = rand() % SIZE;
    } while (board_[row][column] != 0);
    board_[row][column] = (turn % 2 == 0 ? 1 : 2);
    ++turn;
    printBoard();
}

bool
TicTacToe::isGameNotOver()
{
    return !(isWon() || isDraw());
}

bool
TicTacToe::isWon()
{
   if (board_[0][0] != 0 && board_[0][0] == board_[0][1] && board_[0][0] == board_[0][2]) {
       return true;
   }
   if (board_[1][0] != 0 && board_[1][0] == board_[1][1] && board_[1][0] == board_[1][2]) {
       return true;
   }
   if (board_[2][0] != 0 && board_[2][0] == board_[2][1] && board_[2][0] == board_[2][2]) {
       return true;
   }
   if (board_[0][0] != 0 && board_[0][0] == board_[1][0] && board_[0][0] == board_[2][0]) {
       return true;
   }
   if (board_[0][1] != 0 && board_[0][1] == board_[1][1] && board_[0][1] == board_[2][1]) {
       return true;
   }
   if (board_[0][2] != 0 && board_[0][2] == board_[1][2] && board_[0][2] == board_[2][2]) {
       return true;
   }
   if (board_[0][0] != 0 && board_[0][0] == board_[1][1] && board_[0][0] == board_[2][2]) {
       return true;
   }
   if (board_[0][2] != 0 && board_[0][2] == board_[1][1] && board_[0][2] == board_[2][0]) {
       return true;
   }
   return false;
}

bool
TicTacToe::isDraw()
{
    if (isWon()) {
        return false;
    } else {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board_[i][j] == 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

void
TicTacToe::winnerIs(int winner)
{
    std::cout << (winner == 1 ? "X" : "O") << " has won." << std::endl;
}

void
TicTacToe::printBoard()
{
    std::cout << "\t    0   1   2  " << std::endl;
    std::cout << "\t  ┏━━━┳━━━┳━━━┓" << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        std::cout << '\t' << i << " ┃";
        for (int j = 0; j < SIZE; ++j) {
            switch (board_[i][j]) {
            case 0: std::cout << "   ┃"; break;
            case 1: std::cout << " X ┃"; break;
            case 2: std::cout << " O ┃"; break;
            default: assert(0);         break;
            }
        }
        std::cout << ' ' << i << std::endl;
        if (i != SIZE - 1) {
            std::cout << "\t  ┣━━━╋━━━╋━━━┫" << std::endl;
        } else {
            std::cout << "\t  ┗━━━┻━━━┻━━━┛" << std::endl;
            std::cout << "\t    0   1   2  " << std::endl;
        }
    }
}

