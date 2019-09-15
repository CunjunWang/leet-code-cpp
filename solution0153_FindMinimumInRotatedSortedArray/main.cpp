//
// Created by 王存俊 on 2019-09-15.
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
#include "DoublyLinkedListNode.h"
#include "TreeNode.h"
#include "Helpers.h"

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int size = nums.size();
        assert(size > 0);
        if (size == 1)
            return nums[0];

        int left = 0, right = size - 1;

        if (nums[right] > nums[0])
            return nums[0];

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[mid + 1])
                return nums[mid + 1];

            if (nums[mid - 1] > nums[mid])
                return nums[mid];

            if (nums[mid] > nums[left]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};

int main() {
    vector<int> nums = {2, 1};
    int res = Solution().findMin(nums);
    cout << res << endl;
}