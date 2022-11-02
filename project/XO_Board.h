#ifndef XO_XO_BOARD_H
#define XO_XO_BOARD_H
#include <iostream>
#include <vector>

class Board {
protected:
    std::vector<std::vector<char>> board;
    int  n_moves = 0;

public:
    Board();
    // Return true  if move is valid and put it on board
    // within board boundaries in empty cell
    // Return false otherwise
    bool update_board (int x, int y, char symbol);
    // Returns true if there is any winner
    // either X or O
    // Written in a complex way. DO NOT DO LIKE THIS.
    bool is_winner();
    // Return true if 9 moves are done and no winner
    bool is_draw();
    // Display the board and the pieces on it
    void display_board();
    std::vector<std::vector<char>> get_board();
};

#endif
