//
// Created by 王存俊 on 2019-08-27.
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
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        int res = 0;
        int product = 1;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            product *= nums[j];
            while (i <= j && product >= k) {
                product /= nums[i];
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
};

int main() {
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    cout << Solution().numSubarrayProductLessThanK(nums, k) << endl;
}