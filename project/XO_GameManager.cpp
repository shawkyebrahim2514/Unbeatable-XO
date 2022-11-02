#include <iostream>
#include "XO_GameManager.h"

void GameManager::run() {
    Board x_o;
    Player player(1, 'x');
    XO_UnbeatableMoves unbeatableMoves;
    x_o.display_board();
    while (true) {
        if(!playerTurn(player, x_o))
            return;
        if(!unbeatableMovesTurn(unbeatableMoves, x_o))
            return;
    }
}

bool GameManager::playerTurn(Player& player, Board& board) {
    int x, y;
    player.get_move(x, y);
    while (!board.update_board (x, y, player.get_symbol())){
        player.get_move(x, y);
    }
    board.display_board();
    if (board.is_winner()){
        std::cout  << player.to_string() << " wins\n";
        return false;
    }
    if (board.is_draw()){
        std::cout << "Draw!\n";
        return false;
    }
    return true;
}

bool GameManager::unbeatableMovesTurn(XO_UnbeatableMoves& unbeatableMoves, Board& board) {
    std::pair<int, int> moves = unbeatableMoves.findBestMove(board.get_board());
    board.update_board (moves.first, moves.second, 'O');
    board.display_board();
    if (board.is_winner()){
        std::cout  << "You lose!\n";
        return false;
    }
    if (board.is_draw()){
        std::cout << "Draw!\n";
        return false;
    }
    return true;
}