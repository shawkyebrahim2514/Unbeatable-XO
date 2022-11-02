#ifndef XO_XO_UNBEATABLEMOVES_H
#define XO_XO_UNBEATABLEMOVES_H
#include <vector>

class XO_UnbeatableMoves{
public:
    bool isMovesLeft(std::vector<std::vector<char>> board);
    int evaluate(std::vector<std::vector<char>> board);
    int minimax(std::vector<std::vector<char>> board, bool isMax);
    std::pair<int,int> findBestMove(std::vector<std::vector<char>> board);
};

#endif
