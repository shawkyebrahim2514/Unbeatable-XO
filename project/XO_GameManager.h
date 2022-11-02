#ifndef XO_XO_GAMEMANAGER_H
#define XO_XO_GAMEMANAGER_H
#include "XO_Player.h"
#include "XO_Board.h"
#include "XO_UnbeatableMoves.h"

class GameManager {
public:
    void run();
    // This method creates board and players
    // It displays board
    // While True
    //   For each player
    //      It takes a valid move as x, y pair (between 0 - 2)
    //      It updates board and displays it
    //      If winner, declare so and end
    //      If draw, declare so and end
    bool playerTurn(Player& player, Board& board);
    bool unbeatableMovesTurn(XO_UnbeatableMoves& unbeatableMoves, Board& board);
};

#endif
