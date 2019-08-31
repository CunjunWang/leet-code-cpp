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

using namespace std;

// BFS
class Solution {
private:
    vector<int> calculateCoordinator(int num, int N) {
        int x = (num - 1) / N;
        int y = (num - 1) % N;
        if (x % 2 == 1) {
            y = N - 1 - y;
        }
        x = N - 1 - x;
        return {x, y};
    }

public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int size = board.size();
        int N = size * size;
        unordered_map<int, int> steps;
        // bfs
        steps[1] = 0;
        queue<int> todo;
        todo.push(1);

        while (!todo.empty()) {
            int cur = todo.front();
            todo.pop();
            if (cur == N)
                return steps[cur];

            for (int i = 1; i <= 6; i++) {
                int next = cur + i;
                if (next > N)
                    break;

                vector<int> nextCor = calculateCoordinator(next, size);
                int nextX = nextCor[0], nextY = nextCor[1];
                int nextPos = board[nextX][nextY];
                if (nextPos != -1) {
                    next = nextPos;
                }
                if (steps.count(next) == 0) {
                    steps[next] = steps[cur] + 1;
                    todo.push(next);
                }
            }
        }
        return -1;
    }
};

int main() {
    vector<vector<int>> board = {{-1, -1},
                                 {-1, 1}};
//            {{-1, -1, -1, -1, -1, -1},
//                                 {-1, -1, -1, -1, -1, -1},
//                                 {-1, -1, -1, -1, -1, -1},
//                                 {-1, 35, -1, -1, 13, -1},
//                                 {-1, -1, -1, -1, -1, -1},
//                                 {-1, 15, -1, -1, -1, -1}};
    cout << Solution().snakesAndLadders(board) << endl;
}