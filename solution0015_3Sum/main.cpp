//
// Created by 王存俊 on 2019-08-29.
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

// TODO
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        int size = nums.size();
        if (size <= 2)
            return res;
        unordered_map<int, bool> record;
        for (int i = 0; i < size; i++) {
            record[nums[i]] = true;
        }
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {

            }
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 0};
    // {1, 2, 0};
    // {3, 4, -1, -2, 1, 5, 16, 0, 2, 0};

    cout << Solution().firstMissingPositive(nums) << endl;
}