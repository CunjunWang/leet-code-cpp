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

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        int size = nums.size();
        if (size <= 2)
            return res;

        sort(nums.begin(), nums.end());
        if (nums[0] > 0 || nums[size - 1] < 0)
            return res;

        for (int i = 0; i < size - 2; i++) {
            // 剪枝, 因为此时array已经sort过了,
            // 如果nums[i]都已经非负了, 一定不可能3个数和为0
            if (nums[i] > 0)
                break;

            // 去重
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int target = 0 - nums[i], l = i + 1, r = size - 1;

            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    // 左右都要去重
                    while (l < r && nums[l] == nums[l + 1])
                        ++l;
                    while (l < r && nums[r] == nums[r - 1])
                        --r;
                    ++l;
                    --r;
                } else if (nums[l] + nums[r] < target)
                    ++l;
                else
                    --r;
            }
        }

        return res;
    }
};

int main() {
    vector<int> nums = {0, 0, 0, 0};
    vector<vector<int>> res = Solution().threeSum(nums);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}