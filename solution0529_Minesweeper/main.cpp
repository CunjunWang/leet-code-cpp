//
// Created by 王存俊 on 2019-09-08.
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

class Solution {
private:
    vector<vector<char>> graph;
    int m, n;
    int d[8][2] = {{1,  0},
                   {0,  1},
                   {-1, 0},
                   {0,  -1},
                   {1,  1},
                   {1,  -1},
                   {-1, 1},
                   {-1, -1}};

    bool inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void dfs(int x, int y, vector<vector<bool>> &visited) {
        stack<pair<int, int>> todo;
        todo.push(make_pair(x, y));
        visited[x][y] = true;
        while (!todo.empty()) {
            pair<int, int> cur = todo.top();
            todo.pop();

            int adjMineCount = 0;
            for (int i = 0; i < 8; i++) {
                int newX = cur.first + d[i][0];
                int newY = cur.second + d[i][1];
                if (inArea(newX, newY) && graph[newX][newY] == 'M') {
                    adjMineCount++;
                }
            }

            if (graph[cur.first][cur.second] == 'E') {
                if (adjMineCount == 0) {
                    graph[cur.first][cur.second] = 'B';
                } else {
                    graph[cur.first][cur.second] = adjMineCount + '0';
                }
            }

            if (!isdigit(graph[cur.first][cur.second])) {
                for (int i = 0; i < 8; i++) {
                    int newX = cur.first + d[i][0];
                    int newY = cur.second + d[i][1];
                    if (inArea(newX, newY) && !visited[newX][newY]) {
                        visited[newX][newY] = true;
                        todo.push(make_pair(newX, newY));
                    }
                }
            }
        }
    }

public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click) {
        graph = board;
        m = board.size();
        if (m == 0)
            return graph;
        n = board[0].size();
        if (n == 0)
            return graph;
        if (click.size() < 2)
            return graph;
        int clickX = click[0], clickY = click[1];
        if (!inArea(clickX, clickY))
            return graph;
        if (graph[clickX][clickY] == 'M') {
            graph[clickX][clickY] = 'X';
            return graph;
        }
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // do dfs from click point
        dfs(clickX, clickY, visited);

        return graph;
    }
};

int main() {
    vector<vector<char>> board = {{'E', 'E', 'E', 'E', 'E'},
                                  {'E', 'E', 'M', 'E', 'E'},
                                  {'E', 'E', 'E', 'E', 'E'},
                                  {'E', 'E', 'E', 'E', 'E'}};
    vector<int> click = {3, 0};
    vector<vector<char>> res = Solution().updateBoard(board, click);
    printMatrix(res);
}