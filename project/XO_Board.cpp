#include <iostream>
#include <iomanip>
#include "XO_Board.h"

Board::Board(){
    board.resize(3, std::vector<char> (3, 0));
}

std::vector<std::vector<char>> Board::get_board() {
    return this->board;
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool Board::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 2 || y < 0 || y > 2) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else return false;
}

// Display the board and the pieces on it
void Board::display_board() {
    std::cout << std::string(3, ' ');
    for (int i = 1; i <= 3; ++i) {
        std::cout << std::string(5,' ') << i << std::string(6, ' ');
    }
    std::cout << '\n' << std::string(3, ' ') << std::string(37, '-') << '\n';
    for (int i: {0,1,2}) {
        std::cout << ' ' << i + 1 << " |";
        for (int j: {0,1,2}) {
            std::cout << std::string(5,' ') << board[i][j] << std::string(5, ' ') << '|';
        }
        std::cout << '\n' << std::string(3, ' ') << std::string(37, '-') << '\n';
    }
    std::cout << '\n';
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool Board::is_winner() {
    char row_win[3], col_win[3], diag_win[2];

    for (int i:{0,1,2}) {
        row_win[i] = board[i][0] & board[i][1] & board[i][2];
        col_win[i] = board[0][i] & board[1][i] & board[2][i];
    }

    diag_win[0] = board[0][0] & board[1][1] & board[2][2];
    diag_win[1] = board[2][0] & board[1][1] & board[0][2];

    for (int i:{0,1,2})
        if ( (row_win[i] && (row_win[i] == board[i][0])) || (col_win[i] && (col_win[i] == board[0][i])) )
            return true;

    if ((diag_win[0] && diag_win[0] == board[1][1]) || (diag_win[1] && diag_win[1] == board[1][1]))
        return true;
    return false;
}

// Return true if 9 moves are done and no winner
bool Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}