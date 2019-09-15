//
// Created by 王存俊 on 2019-09-15.
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
#include "DoublyLinkedListNode.h"
#include "TreeNode.h"
#include "Helpers.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        set<vector<int>> res;
        vector<vector<int>> toReturn;
        int size = nums.size();
        if (size < 4) {
            return toReturn;
        }
        unordered_map<int, vector<pair<int, int>>> record;
        for (int i = 0; i < size; i++) {
            int numI = nums[i];
            for (int j = i + 1; j < size; j++) {
                int numJ = nums[j];
                int newTarget = target - numI - numJ;
                record[newTarget].emplace_back(make_pair(i, j));
            }
        }

        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                int numI = nums[i], numJ = nums[j];
                int sumIJ = numI + numJ;
                if (record.count(sumIJ)) {
                    auto pairs = record[sumIJ];
                    if (!pairs.empty()) {
                        for (auto it : pairs) {
                            int preI = it.first;
                            int preJ = it.second;
                            if (i != preI && i != preJ && j != preI && j != preJ) {
                                vector<int> thisRes = {nums[i], nums[j], nums[preI], nums[preJ]};
                                sort(thisRes.begin(), thisRes.end());
                                res.insert(thisRes);
                            }
                        }
                    }
                }
            }
        }

        for (auto it = res.begin(); it != res.end(); it++) {
            toReturn.emplace_back(*it);
        }

        return toReturn;
    }
};

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> res = Solution().fourSum(nums, target);
    printMatrix(res);
}