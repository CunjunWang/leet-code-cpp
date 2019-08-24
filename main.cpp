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
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1)
            return 0;
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            res += max(0, prices[i] - prices[i - 1]);
        }
        return res;
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {5, 1, 2, 3},
                                  {9, 5, 1, 2}};
    Solution().isToeplitzMatrix(matrix);
}