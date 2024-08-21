#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

const int SIZE = 3;

class TicTacToe
{
public:
    TicTacToe();
    void setBoard();

    void play();
    void againstPlayer();
    void againstComputer();
    void playerTurn(int &, int &, int &);
    void computerTurn(int &, int &, int &);

    bool isGameNotOver();
    bool isWon();
    bool isDraw();
    void winnerIs(int);

    void printBoard();
private:
    int board_[SIZE][SIZE];
};

#endif

