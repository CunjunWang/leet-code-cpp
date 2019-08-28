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
#include "TreeNode.h"
#include "ListNode.h"

using namespace std;

class Solution {
private:
    int m, n;
    int d[8][2] = {{-1, 0},
                   {-1, 1},
                   {0,  1},
                   {1,  1},
                   {1,  0},
                   {1,  -1},
                   {0,  -1},
                   {-1, -1}};
    vector<vector<bool>> visited;

    bool inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

public:
    void gameOfLife(vector<vector<int>> &board) {
        m = board.size();
        if (m == 0) return;
        n = board[0].size();
        if (n == 0) return;

//        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        int deadSign = 2, liveSign = 3;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int liveNeighbor = 0;
                // int deadNeighbor = 0;
                bool live = board[i][j] == 1;
                for (int k = 0; k < 8; k++) {
                    int newX = i + d[k][0];
                    int newY = j + d[k][1];
                    if (inArea(newX, newY) &&
                        (board[newX][newY] == 1 || board[newX][newY] == 2)) {
                        liveNeighbor++;
                    }
                }
                if (live) {
                    if (liveNeighbor < 2 || liveNeighbor > 3) {
                        board[i][j] = 2;
                    }
                } else {
                    if (liveNeighbor == 3)
                        board[i][j] = 3;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == deadSign) {
                    board[i][j] = 0;
                } else if (board[i][j] == liveSign) {
                    board[i][j] = 1;
                }
            }
        }

        return;
    }
};

int main() {
    vector<vector<int>> board = {{0, 1, 0},
                                 {0, 0, 1},
                                 {1, 1, 1},
                                 {0, 0, 0}};
    // {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    Solution().gameOfLife(board);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}