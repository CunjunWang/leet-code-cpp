//
// Created by 王存俊 on 2019-09-05.
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
#include "Helpers.h"

using namespace std;

class Solution {
private:
    void generateResult(int k, int target, int curSize, int curSum, int curNum,
                        vector<int> &curRes, vector<vector<int>> &res) {
        if (curSize == k) {
            if (curSum == target) {
                res.emplace_back(curRes);
                return;
            } else {
                return;
            }
        }
        for (int i = curNum; i < 10; i++) {
            if (curSum + i <= target) {
                curRes.emplace_back(i);
                generateResult(k, target, curSize + 1, curSum + i, i + 1, curRes, res);
                curRes.pop_back();
            } else {
                // prune recursion tree;
                break;
            }
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curRes;
        res.clear(), curRes.clear();
        generateResult(k, n, 0, 0, 1, curRes, res);
        return res;
    }
};

int main() {
    int k = 3, n = 9;
    vector<vector<int>> res = Solution().combinationSum3(k, n);
    printMatrix(res);
}