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

// dynamic programming solution
class Solution {

public:
    int combinationSum4(vector<int> &nums, int target) {
        vector<unsigned int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int j = 0; j < nums.size(); j++) {
                if (i >= nums[j]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    int target = 4;
    int res = Solution().combinationSum4(nums, target);
    cout << res << endl;
}


// DFS: TLE
//class Solution {
//private:
//    int res = 0;
//
//    void generateResult(vector<int> &nums, int target, int curIndex, int curSum) {
//        if (curSum == target) {
//            res++;
//            return;
//        }
//        if (curIndex == nums.size()) {
//            return;
//        }
//
//        for (int i = 0; i < nums.size(); i++) {
//            int curNum = nums[i];
//            if (curSum + curNum <= target) {
//                curSum += curNum;
//                generateResult(nums, target, i, curSum);
//                curSum -= curNum;
//            } else {
//                break;
//            }
//        }
//    }
//
//public:
//    int combinationSum4(vector<int> &nums, int target) {
//        sort(nums.begin(), nums.end());
//        generateResult(nums, target, 0, 0);
//        return res;
//    }
//};