#include<iostream>
#include "XO_UnbeatableMoves.h"
using namespace std;

char player = 'O', opponent = 'X';

//returns true/false depending upon the moves left on the board
bool XO_UnbeatableMoves::isMovesLeft(std::vector<std::vector<char>> board)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == 0)
                return true;
    return false;
}

//Evaluation function
int XO_UnbeatableMoves::evaluate(std::vector<std::vector<char>> board)
{
    // checking rows for a win
    for (int row = 0; row<3; row++)
    {
        if (board[row][0]==board[row][1] && board[row][1]==board[row][2])
        {
            if (board[row][0]==player)
                return +10;
            else if (board[row][0]==opponent)
                return -10;
        }
    }

    // checking  columns for a win
    for (int col = 0; col<3; col++)
    {
        if (board[0][col]==board[1][col] && board[1][col]==board[2][col])
        {
            if (board[0][col]==player)
                return +10;

            else if (board[0][col]==opponent)
                return -10;
        }
    }

    // checking diagonals for a win
    if (board[0][0]==board[1][1] && board[1][1]==board[2][2])
    {
        if (board[0][0]==player)
            return +10;
        else if (board[0][0]==opponent)
            return -10;
    }

    if (board[0][2]==board[1][1] && board[1][1]==board[2][0])
    {
        if (board[0][2]==player)
            return +10;
        else if (board[0][2]==opponent)
            return -10;
    }

    //if niether wins..
    return 0;
}

// function to try out every possibility
int XO_UnbeatableMoves::minimax(std::vector<std::vector<char>> board, bool isMax)
{
    int score = evaluate(board);

    // score of +10 indicates maximiser's win
    if (score == 10)
        return score;

    // score of -10 indicates minimiser's win
    if (score == -10)
        return score;

    // if no moves left
    if (!isMovesLeft(board))
        return 0;

    if (isMax)
    {
        int best = -1000;

        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Checking if cell is empty
                if (board[i][j] == 0)
                {
                    board[i][j] = player;

                    // Calling minimax recursively and choosing the maximum value
                    best = max( best,
                                minimax(board, !isMax) );

                    // Undo the move
                    board[i][j] = 0;
                }
            }
        }
        return best;
    }

        // If this minimizer's move
    else
    {
        int best = 1000;

        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {

                if (board[i][j] == 0)
                {

                    board[i][j] = opponent;

                    best = min(best,
                               minimax(board, !isMax));

                    board[i][j] = 0;
                }
            }
        }
        return best;
    }
}

// This will return the best possible move for the player
pair<int,int> XO_UnbeatableMoves::findBestMove(std::vector<std::vector<char>> board)
{
    int bestVal = -1000;
    pair<int,int> bestMove = {-1, -1};

    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {

            if (board[i][j]==0)
            {

                board[i][j] = player;

                int moveVal = minimax(board, false);

                board[i][j] = 0;

                // If the value of the current move is more than the best value
                if (moveVal > bestVal)
                {
                    bestMove.first = i;
                    bestMove.second = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}