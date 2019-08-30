//
// Created by 王存俊 on 2019-08-30.
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

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int size = nums.size();
        // find the first at the decrease pattern
        int end = size - 1;
        while (end >= 1 && nums[end] <= nums[end - 1]) {
            end--;
        }
        // nums is decreasing, it is the last permutation
        // just sort to generate the first permutation
        if (end == 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        end--;
        int index = 0;
        for (int i = size - 1; i > end; i--) {
            if (nums[i] > nums[end]) {
                index = i;
                break;
            }
        }
        swap(nums[end], nums[index]);
        int len = size - end - 1;
        for (int k = 0; k < len / 2; k++) {
            swap(nums[k + end + 1], nums[size - 1 - k]);
        }
        return;
    }
};

int main() {
    vector<int> nums = {5, 1, 1};
    // {6, 2, 1, 5, 4, 3, 0, 7};
    Solution().nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
}