//
// Created by 王存俊 on 2019-08-10.
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
#include "TreeNode.h"
#include "ListNode.h"

using namespace std;

// TODO: TLE
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>> &paths) {
        vector<int> color(N, 1);

        if (N == 0)
            return {};

        if (paths.empty())
            return color;

        // build a graph use adjacent matrix
        vector<vector<bool>> g(N, vector<bool>(N, false));
        for (int i = 0; i < paths.size(); i++) {
            vector<int> path = paths[i];
            g[path[0] - 1][path[1] - 1] = g[path[1] - 1][path[0] - 1] = true;
        }



        // bfs
        set<int> starts;
        for (int i = 0; i < paths.size(); i++) {
            starts.insert(paths[i][0]);
        }
        queue<int> todo; // next index
        for (auto iter = starts.begin(); iter != starts.end(); iter++) {
            todo.push(*iter);
        }

        while (!todo.empty()) {
            int cur = todo.front();
            todo.pop();

            vector<bool> available = {true, true, true, true};
            for (int i = 0; i < g[cur - 1].size(); i++) {
                // if connected
                if (g[cur - 1][i]) {
                    if (color[i] != -1) {
                        available[color[i] - 1] = false;
                    } else {
                        todo.push(i + 1);
                    }
                }
            }
            for (int j = 0; j < 4; j++) {
                if (available[j]) {
                    color[cur - 1] = j + 1;
                    break;
                }
            }
        }

        return color;
    }
};

int main() {
    int N = 4;
    vector<vector<int>> paths = {{1, 2},
                                 {3, 4}};
    vector<int> colors = Solution().gardenNoAdj(N, paths);
    for (int i = 0; i < colors.size(); i++) {
        cout << colors[i] << " ";
    }

}