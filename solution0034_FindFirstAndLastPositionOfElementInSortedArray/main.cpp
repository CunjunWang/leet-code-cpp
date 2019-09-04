//
// Created by 王存俊 on 2019-08-31.
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

class Solution {
private:
    int searchIndex(vector<int> &nums, int target) {

    }

public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int size = nums.size();
        if (size == 0) {
            return {-1, -1};
        }
        if (size == 1) {
            if (nums[0] == target) {
                return {0, 0};
            } else {
                return {-1, -1};
            }
        }
        int begin = -1, last = -1;

        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                // todo:
            }
        }
    }
};

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> res = Solution().searchRange(nums, target);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}