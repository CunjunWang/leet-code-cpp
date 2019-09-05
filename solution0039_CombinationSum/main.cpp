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
    void generateResult(vector<int> &candidates, int curIndex, int curSum, vector<int> &curRes, int target,
                        vector<vector<int>> &res) {
        if (curSum == target) {
            res.emplace_back(curRes);
            return;
        }
        if (curIndex == candidates.size()) {
            return;
        }
        for (int i = curIndex; i < candidates.size(); i++) {
            int thisNum = candidates[i];
            if (curSum + thisNum <= target) {
                curRes.emplace_back(thisNum);
                generateResult(candidates, i, curSum + thisNum, curRes, target, res);
                curRes.pop_back();
            } else {
                break;
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> curRes;
        res.clear(), curRes.clear();
        sort(candidates.begin(), candidates.end());
        generateResult(candidates, 0, 0, curRes, target, res);
        return res;
    }
};

int main() {
    vector<int> candidates = {2, 3, 1, 6, 7};
    int target = 7;
    vector<vector<int>> res = Solution().combinationSum(candidates, target);
    printMatrix(res);
}