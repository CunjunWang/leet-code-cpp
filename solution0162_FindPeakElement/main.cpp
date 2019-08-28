//
// Created by 王存俊 on 2019-08-28.
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

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        if (nums.size() <= 1)
            return 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                if (nums[i] > nums[i + 1]) {
                    return i;
                }
            } else if (i == nums.size() - 1) {
                if (nums[i] > nums[i - 1]) {
                    return i;
                }
            } else {
                if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                    return i;
                }
            }
        }
        return 0;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << Solution().findPeakElement(nums) << endl;

    nums = {1, 2, 1, 3, 5, 6, 4};
    cout << Solution().findPeakElement(nums) << endl;
}