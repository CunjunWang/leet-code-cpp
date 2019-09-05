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
    void generateResult(vector<int> &candidates, int target, int curIndex, int curSum,
                        vector<int> &curRes, set<vector<int>> &res) {
        if (curSum == target) {
            res.insert(curRes);
            return;
        }
        if (curIndex == candidates.size())
            return;

        // dfs
        for (int i = curIndex; i < candidates.size(); i++) {
            int thisNum = candidates[i];
            if (curSum + thisNum <= target) {
                curRes.emplace_back(thisNum);
                generateResult(candidates, target, i + 1, curSum + thisNum, curRes, res);
                curRes.pop_back();
            } else {
                // candidates is sorted, prune recursion tree;
                break;
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        set<vector<int>> res;
        vector<int> curRes;
        res.clear(), curRes.clear();
        sort(candidates.begin(), candidates.end());
        generateResult(candidates, target, 0, 0, curRes, res);
        vector<vector<int>> result;
        for (auto it = res.begin(); it != res.end(); it++) {
            result.emplace_back(*it);
        }
        return result;
    }
};

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> res = Solution().combinationSum2(candidates, target);
    printMatrix(res);
}