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
    int findLengthOfLCIS(vector<int> &nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        int res = 0;
        int cur = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                cur++;
            } else {
                res = max(res, cur);
                cur = 1;
            }
        }
        res = max(res, cur);
        return res;
    }
};

int main() {
    vector<int> nums = {1,3,5,7};
    cout << Solution().findLengthOfLCIS(nums) << endl;
}