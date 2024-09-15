#pragma once

#include <array>
#include "Player.hpp"

constexpr int BOARD_SIZE = 3;

struct Board {
    std::array<std::array<Player, BOARD_SIZE>, BOARD_SIZE> grid;

    Board();

    void printBoard() const;
    bool isFull() const;
    bool checkWin(Player player) const;
    bool makeMove(int row, int col, Player player);
};
