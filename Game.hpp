#pragma once

#include "Board.hpp"
#include "Player.hpp"

class Game {
public:
    Game();

    void start();
    void makeMove(int row, int col);
    bool isGameOver() const;
    Player getCurrentPlayer() const;
    Player getWinner() const;

private:
    Board board;
    Player currentPlayer;
    Player winner;
    bool gameOver;

    void switchPlayer();
    void checkGameOver();
};
