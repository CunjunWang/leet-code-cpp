//
// Created by 王存俊 on 2019-08-31.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <sstream>
#include <cassert>
#include <list>
#include <set>
#include <unordered_set>
#include "TreeNode.h"
#include "ListNode.h"
#include "Helpers.h"

using namespace std;

// TODO
class TicTacToe {
private:
    int n;
    vector<vector<char>> board;
    vector<int> rowCount, colCount;
    vector<int> rowBelong, colBelong;

    bool validMove(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < n && board[x][y] == '\0';
    }

public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        vector<vector<char>> board(n, vector<char>(n, '\0'));
        this->board = board;
        this->n = n;
        rowCount = vector<int>(n);
        colCount = vector<int>(n);
        rowBelong = vector<int>(n, -1);
        colBelong = vector<int>(n, -1);
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        assert(validMove(row, col));
        board[row][col] = player + '0';
        rowCount[row]++;
        colCount[col]++;
        if (rowBelong[row] == -1) {
            rowBelong[row] = player;
        } else if (rowBelong[row] + player == 1) {
            rowBelong[row] = -1;
        }
        if (rowCount[row] == n && rowBelong[row] == player) {
            return player;
        }
        if
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

int main() {
    TicTacToe *obj = new TicTacToe(4);
    obj->move(1, 1, 1);
}