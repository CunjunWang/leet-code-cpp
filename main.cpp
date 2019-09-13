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
        int begin = -1, end = -1;
        // first find begin
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
            if (right <= left) {
                if (nums[left] == target) {
                    begin = left;
                }
                break;
            }
        }
        if (begin == -1) {
            return {-1, -1};
        }
        // then find end
        left = begin + 1, right = size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
            if (left >= right) {
                if (nums[right] == target) {
                    end = right;
                } else {
                    end = right - 1;
                }
                break;
            }
        }
        if (end == -1) {
            return {begin, begin};
        }

        return {begin, end};
    }
};

int main() {
    vector<int> nums = {3, 3, 3};
    int target = 3;
    vector<int> res = Solution().searchRange(nums, target);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}