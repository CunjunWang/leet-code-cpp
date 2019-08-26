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

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        if (n == 0) return;

        // first, upside-down
        for (int i = 0; i < m / 2; i++) {
            for (int j = 0; j < n; j++) {
                swap(matrix[i][j], matrix[m - 1 - i][j]);
            }
        }

        // then, mirror at the main diagonal
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {{1,  2,  3,  4,  5},
                                  {6,  7,  8,  9,  10},
                                  {11, 12, 13, 14, 15},
                                  {16, 17, 18, 19, 20},
                                  {21, 22, 23, 24, 25}};
    Solution().rotate(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}