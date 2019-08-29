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
    bool checkPossibility(vector<int> &nums) {
        int size = nums.size();
        if (size <= 1)
            return size != 0;

        int startToDecrease = -1;
        for (int i = 1; i < size; i++) {
            if (nums[i] < nums[i - 1]) {
                startToDecrease = i;
                break;
            }
        }
        // already non-decreasing, or start to decrease at the end
        if (startToDecrease == -1 || startToDecrease == size - 1)
            return true;

        for (int i = startToDecrease + 1; i < size; i++) {
            if (nums[i] < nums[i - 1])
                return false;
        }

        if (startToDecrease == 1)
            return true;

        return (nums[startToDecrease + 1] >= nums[startToDecrease - 1]) ||
               (nums[startToDecrease] >= nums[startToDecrease - 2]);
    }
};

int main() {
    vector<int> nums = {2, 3, 3, 2, 3};
    cout << Solution().checkPossibility(nums) << endl;
}