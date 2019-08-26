//
// Created by 王存俊 on 2019-08-25.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include <sstream>
#include <set>
#include "TreeNode.h"
#include "ListNode.h"

using namespace std;

// TODO:
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() <= 2)
            return nums.size();

        int slow = 1;
        int fast = 1;
        int curCount = 1;
        for (; fast < nums.size(); fast++) {
            if (nums[slow] == nums[slow - 1] && curCount < 2) {
                curCount++;
                slow++;
            }
            if (nums[fast] != nums[slow]) {
                nums[slow] = nums[fast];
                curCount = 1;
                slow++;
            }
        }
        return slow;
    }
};

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    cout << Solution().removeDuplicates(nums) << endl;
}