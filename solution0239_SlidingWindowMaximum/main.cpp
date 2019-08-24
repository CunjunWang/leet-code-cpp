//
// Created by 王存俊 on 2019-08-23.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include <sstream>
#include "TreeNode.h"

using namespace std;

// TODO:
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> result;

        if (nums.empty() || k == 0) {
            return result;
        }

        if (k == 1) {
            return nums;
        }

        int l = 0, r = k - 1;

        vector<int> temp;
        for (int i = 0; i < k; i++) {
            temp.push_back(nums[i]);
        }
        int maximum = *max_element(temp.begin(), temp.end());
        result.push_back(maximum);

        while (l < nums.size() - k) {
            maximum = max(maximum, nums[++r]);
            l++;
            result.push_back(maximum);
        }
        return result;
    }
};

int main() {
    vector<int> nums = {1, 3, 1, 2, 0, 5};
    int k = 3;
    vector<int> result = Solution().maxSlidingWindow(nums, k);
    for (int i : result) {
        cout << i << " ";
    }
}