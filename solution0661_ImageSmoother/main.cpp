//
// Created by 王存俊 on 2019-08-24.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include <sstream>
#include "TreeNode.h"

using namespace std;

class Solution {
private:
    vector<vector<int>> d = {{1,  0},
                             {1,  1},
                             {0,  1},
                             {-1, 1},
                             {-1, 0},
                             {-1, -1},
                             {0,  -1},
                             {1,  -1}};
    int m, n;

    bool inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &M) {
        m = M.size();
        n = M[0].size();
        if (m == 1 && n == 1) return M;
        vector<vector<int>> res(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int pointCount = 1;
                int sum = M[i][j];
                for (int k = 0; k < 8; k++) {
                    int newX = i + d[k][0];
                    int newY = j + d[k][1];
                    if (inArea(newX, newY)) {
                        pointCount++;
                        sum += M[newX][newY];
                    }
                }
                res[i][j] = sum / pointCount;
            }
        }

        return res;
    }
};

int main() {
    vector<vector<int>> M = {{1, 1, 1},
                             {1, 0, 1},
                             {1, 1, 1}};
    Solution().imageSmoother(M);
}