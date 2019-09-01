//
// Created by 王存俊 on 2019-09-01.
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

class Solution {
private:
    int minOfThree(int x, int y, int z) {
        return min(x, min(y, z));
    }

public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int maxSideLength = dp[0][0];

        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = minOfThree(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
                }
                maxSideLength = max(dp[i][j], maxSideLength);
            }
        }

        return maxSideLength * maxSideLength;
    }
};

int main() {
    vector<vector<char>> matrix = {{1}};
    cout << Solution().maximalSquare(matrix) << endl;
}