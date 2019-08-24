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
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if (m == 0) return false;
        if (m == 1) return true;
        int n = matrix[0].size();
        if (n == 0) return false;
        if (n == 1) return true;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    visited[i][j] = true;
                    int val = matrix[i][j];
                    int startx = i, starty = j;
                    while (startx < m - 1 && starty < n - 1) {
                        int nextVal = matrix[++startx][++starty];
                        if (nextVal != val)
                            return false;
                        visited[startx][starty] = true;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {5, 1, 2, 3},
                                  {9, 5, 1, 2}};
    Solution().isToeplitzMatrix(matrix);
}