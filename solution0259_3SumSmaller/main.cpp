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
#include "TreeNode.h"
#include "ListNode.h"

using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int> &nums, int target) {
        int size = nums.size();
        if (size <= 2)
            return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < size - 2; i++) {
            int left = i + 1, right = size - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < target) {
                    res += right - left;
                    left++;
                } else {
                    right--;
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {0, -4, -1, 1, -1, 2};
    int target = -5;
    cout << Solution().threeSumSmaller(nums, target) << endl;
}