//
// Created by 王存俊 on 2019-08-28.
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

class Solution {
private:
    int sign = INT_MIN / 2;

    void setRow(vector<vector<int>> &matrix, int row, int numCols) {
        for (int j = 0; j < numCols; j++) {
            if (matrix[row][j] != 0) {
                matrix[row][j] = sign;
            }
        }
    }

    void setColumn(vector<vector<int>> &matrix, int column, int numRows) {
        for (int i = 0; i < numRows; i++) {
            if (matrix[i][column] != 0) {
                matrix[i][column] = sign;
            }
        }
    }

public:
    void setZeroes(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        if (n == 0) return;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    setRow(matrix, i, n);
                    setColumn(matrix, j, m);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == sign) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {{0, 1, 2, 0},
                                  {3, 4, 5, 2},
                                  {1, 3, 1, 5}};
    // {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    Solution().setZeroes(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}