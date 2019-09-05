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