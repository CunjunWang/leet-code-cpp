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
#include <cassert>
#include <list>
#include <set>
#include "TreeNode.h"
#include "ListNode.h"

using namespace std;

// DP solution
class Solution {
private:
    int m, n;
    int d[4][2] = {{-1, 0},
                   {0,  1},
                   {1,  0},
                   {0,  -1}};

    bool inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
        m = matrix.size();
        if (m == 0) return matrix;
        n = matrix[0].size();
        if (n == 0) return matrix;

        vector<vector<int>> res(m, vector<int>(n, m + n + 1));
        // initialize res
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    res[i][j] = 0;
                }
            }
        }

        // top to bottom
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = min(res[i - 1][j] + 1, res[i][j]);
            }
        }

        // left to right
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                res[i][j] = min(res[i][j - 1] + 1, res[i][j]);
            }
        }

        // bottom to top
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                res[i][j] = min(res[i + 1][j] + 1, res[i][j]);
            }
        }

        // right to left
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                res[i][j] = min(res[i][j + 1] + 1, res[i][j]);
            }
        }

        return res;
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 0, 1, 1, 0, 0, 1, 0, 0, 1},
                                  {0, 1, 1, 0, 1, 0, 1, 0, 1, 1},
                                  {0, 0, 1, 0, 1, 0, 0, 1, 0, 0},
                                  {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
                                  {0, 1, 0, 1, 1, 0, 0, 0, 0, 1},
                                  {0, 0, 1, 0, 1, 1, 1, 0, 1, 0},
                                  {0, 1, 0, 1, 0, 1, 0, 0, 1, 1},
                                  {1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
                                  {1, 1, 1, 1, 1, 1, 1, 0, 1, 0},
                                  {1, 1, 1, 1, 0, 1, 0, 0, 1, 1}};
    vector<vector<int>> res = Solution().updateMatrix(matrix);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}