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
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if (m == 0) return {};
        int n = matrix[0].size();
        if (n == 0) return {};

        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        vector<int> res;

        while (res.size() < m * n) {
            for (int cp = left; cp <= right; cp++) {
                res.push_back(matrix[top][cp]);
            }
            top++;
            if (top > bottom) break;
            for (int rp = top; rp <= bottom; rp++) {
                res.push_back(matrix[rp][right]);
            }
            right--;
            if (right < left) break;
            for (int cp = right; cp >= left; cp--) {
                res.push_back(matrix[bottom][cp]);
            }
            bottom--;
            if (top > bottom) break;
            for (int rp = bottom; rp >= top; rp--) {
                res.push_back(matrix[rp][left]);
            }
            left++;
            if (right < left) break;
        }

        return res;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,  2,  3,  4,  5},
                                  {6,  7,  8,  9,  10},
                                  {11, 12, 13, 14, 15},
                                  {16, 17, 18, 19, 20},
                                  {21, 22, 23, 24, 25},
                                  {26, 27, 28, 29, 30},
                                  {31, 32, 33, 34, 35}};
    vector<int> res = Solution().spiralOrder(matrix);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}