//
// Created by 王存俊 on 2019-08-26.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <sstream>
#include <set>
#include "TreeNode.h"
#include "ListNode.h"

using namespace std;

class Solution {
private:
    int m, n;

    // 方向
    int d[4][2] = {{-1, 0},
                   {0,  1},
                   {1,  0},
                   {0,  -1}};

    bool inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    // bfs遍历
    bool bfsSearch(int startX, int startY, const vector<vector<char>> &board,
                   vector<vector<bool>> &visited, vector<pair<int, int>> &record) {
        queue<pair<int, int>> q;
        bool res = true;
        q.push(pair<int, int>(startX, startY));
        visited[startX][startY] = true;
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            // 记录访问过的O
            record.push_back(pair<int, int>(cur.first, cur.second));
            // 对每个点, 遍历四个方向
            for (int i = 0; i < 4; i++) {
                int newX = cur.first + d[i][0];
                int newY = cur.second + d[i][1];
                if (!inArea(newX, newY)) { // 若下一个方向不在图内了, 返回false
                    res = false;
                } else if (board[newX][newY] == 'O' && !visited[newX][newY]) { // 若下一个方向还在图内, 未访问过, 而且为O,
                    visited[newX][newY] = true;
                    q.push(pair<int, int>(newX, newY));
                }
            }
        }

        return res;
    }

public:

    void solve(vector<vector<char>> &board) {
        m = board.size();
        if (m == 0) return;
        n = board[0].size();
        if (n == 0) return;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> record;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 若遇到了O, 开始bfs
                if (board[i][j] == 'O' && !visited[i][j]) {
                    // 清空记录
                    record.clear();
                    // 若bfs结果为true, 表示从该点开始完全被X包围
                    if (bfsSearch(i, j, board, visited, record)) {
                        // 把通过该点bfs获得的O全都置为X
                        for (int k = 0; k < record.size(); k++) {
                            board[record[k].first][record[k].second] = 'X';
                        }
                    }
                }
            }
        }
        return;
    }
};

int main() {
    vector<vector<char>> board = {{'X', 'O', 'O', 'X', 'X', 'X', 'O', 'X', 'O', 'O'},
                                  {'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                                  {'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X'},
                                  {'X', 'O', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'O'},
                                  {'O', 'X', 'X', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
                                  {'X', 'X', 'O', 'X', 'X', 'O', 'O', 'X', 'X', 'X'},
                                  {'O', 'X', 'X', 'O', 'O', 'X', 'O', 'X', 'X', 'O'},
                                  {'O', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X'},
                                  {'X', 'O', 'O', 'X', 'X', 'O', 'X', 'X', 'O', 'O'},
                                  {'X', 'X', 'X', 'O', 'O', 'X', 'O', 'X', 'X', 'O'}};
    //{{'O', 'O', 'O', 'O', 'X', 'X'},{'O', 'O', 'O', 'O', 'O', 'O'},{'O', 'X', 'O', 'X', 'O', 'O'},{'O', 'X', 'O', 'O', 'X', 'O'},{'O', 'X', 'O', 'X', 'O', 'O'},{'O', 'X', 'O', 'O', 'O', 'O'}};
    // {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};



    Solution().solve(board);

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}