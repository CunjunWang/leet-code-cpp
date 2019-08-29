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

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int size = nums.size();
        if (size == 0)
            return 1;
        if (size == 1) {
            if (nums[0] <= 0 || nums[0] > 1)
                return 1;
            else
                return 2;
        }
        bool hasOne = false;
        for (int i = 0; i < size; i++) {
            if (nums[i] == 1)
                hasOne = true;
            if (nums[i] <= 0 || nums[i] > size) {
                nums[i] = 1;
            }
        }
        if (!hasOne)
            return 1;

        for (int i = 0; i < size; i++) {
            int index = abs(nums[i]);
            if (index == size) {
                nums[0] = -1 * abs(nums[0]);
            } else {
                nums[index] = -1 * abs(nums[index]);
            }
        }

        for (int i = 1; i < size; i++) {
            if (nums[i] > 0) {
                return i;
            }
        }

        if (nums[0] > 0)
            return size;

        return size + 1;
    }
};


int main() {
    vector<int> nums = {1, 2, 0};
    // {1, 2, 0};
    // {3, 4, -1, -2, 1, 5, 16, 0, 2, 0};

    cout << Solution().firstMissingPositive(nums) << endl;
}