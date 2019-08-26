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

// TODO with DP
class Solution {
private:
    bool jump(vector<int> &nums, int curIndex, int target) {
        int curVal = nums[curIndex];
        if (curVal >= target || (curIndex + curVal >= target - 1)) {
            return true;
        }
        if (curVal == 0 && curIndex != target - 1) {
            return false;
        }
        bool res = false;
        for (int i = curVal; i > 0; i--) {
            res = res || jump(nums, curIndex + i, target);
        }
        return res;
    }

public:
    bool canJump(vector<int> &nums) {
        int target = nums.size();
        if (target == 0) return false;
        return jump(nums, 0, target);
    }
};

int main() {
    vector<int> nums = {3, 2, 1, 0, 4};
    cout << Solution().canJump(nums) << endl;
}