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

using namespace std;

// TODO:
class Solution {
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

        // find begin first
        int left = 0, right = size - 1;
        while (left <= right) {
            if (left == right) {
                begin = left;
                break;
            }
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        // then find last
        left = 0, right = size - 1;
        while (left <= right) {
            if (left == right) {
                last = right - 1;
                break;
            }
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return {begin, last};
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