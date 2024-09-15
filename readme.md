# tic-tac-toe

Proiectul reprezintă o implementare a jocului X și O (sau Tic-Tac-Toe) în C++, organizat într-o structură modulară.

#### Jocul X și O:

**Scopul Jocului:** Este un joc pentru doi jucători, unde fiecare jucător marchează pe rând spațiile de pe o tablă 3x3. Scopul este să aliniezi trei simboluri identice (X sau O) pe orizontală, verticală sau diagonală.

```
#pragma once

enum class Player {
    None,
    X,
    O
};
```

**Player:** este un tip de date enumerat care reprezintă starea fiecărei poziții pe tabla de joc și identifică jucătorii.
**None:** Reprezintă o poziție liberă pe tabla de joc, care nu este ocupată de niciun jucător.
**X:** Reprezintă jucătorul care utilizează simbolul X.
**O:** Reprezintă jucătorul care utilizează simbolul O.

```
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
```

**std::array<std::array<Player, BOARD_SIZE>, BOARD_SIZE>** este un tip de date complex care reprezintă tabla de joc. Este o matrice 2D cu dimensiunea BOARD_SIZE x BOARD_SIZE (3x3 pentru jocul X și O), unde fiecare element este de tip Player.

**Board** este o structură care conține:

- **grid:** O matrice 2D de dimensiune fixă, care stochează starea fiecărei poziții pe tablă.
- Funcții:
  - **printBoard():** Afișează tabla de joc.
  - **isFull():** Verifică dacă tabla este completă.
  - **checkWin(Player player):** Verifică dacă jucătorul specificat a câștigat.
  - **makeMove(int row, int col, Player player):** Face o mutare pentru un jucător

```
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
```

**Game** este o clasă care gestionează logica jocului, incluzând:

- **board:** Un obiect de tip Board, care reprezintă tabla de joc.
- **currentPlayer:** Jucătorul curent care urmează să facă mutarea.
- **winner:** Jucătorul câștigător, dacă există.
- **gameOver:** Indicator care arată dacă jocul s-a terminat.
- Funcții publice:
  - **start():** Începe un nou joc.
  - **makeMove(int row, int col):** Face o mutare pe tabla de joc.
  - **isGameOver():** Verifică dacă jocul s-a terminat.
  - **getCurrentPlayer():** Returnează jucătorul curent.
  - **getWinner():** Returnează câștigătorul jocului (dacă există).
- Funcții private:
  - **switchPlayer():** Schimbă jucătorul curent.
  - **checkGameOver():** Verifică starea jocului și stabilește câștigătorul.
