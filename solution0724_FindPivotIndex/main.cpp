//
// Created by 王存俊 on 2019-08-24.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include <sstream>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        if (nums.size() <= 2)
            return -1;
        int leftSum = 0;
        int rightSum = 0;
        for (int i : nums)
            rightSum += i;

        for (int i = 0; i < nums.size(); i++) {
            if (i >= 1) {
                leftSum += nums[i - 1];
                rightSum -= nums[i - 1];
            }
            if (rightSum - nums[i] == leftSum) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    cout << Solution().pivotIndex(nums) << endl;
}