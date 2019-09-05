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
    void generateResult(int n, long long curNum, long long curProduct,
                        vector<int> &curRes, vector<vector<int>> &res) {
        if (curProduct == n) {
            res.emplace_back(curRes);
            return;
        }

        // prune1: i <= n / 2
        for (long long i = curNum; i <= n / 2; i++) {
            if (n % i == 0) {
                if (curProduct * i <= n) {
                    curRes.emplace_back(i);
                    generateResult(n, i, curProduct * i, curRes, res);
                    curRes.pop_back();
                } else {
                    // prune2
                    break;
                }
            }
        }
    }

public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        if (n <= 1) {
            return res;
        }
        vector<int> curRes;
        res.clear(), curRes.clear();
        generateResult(n, 2, 1, curRes, res);
        return res;
    }
};

int main() {
    int n = 12;
    vector<vector<int>> res = Solution().getFactors(n);
    printMatrix(res);
}