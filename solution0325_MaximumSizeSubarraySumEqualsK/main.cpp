//
// Created by 王存俊 on 2019-09-16.
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

// Prefix sum solution
class Solution {
public:
    int maxSubArrayLen(vector<int> &nums, int k) {
        int size = nums.size();
        if (size == 0)
            return 0;

        unordered_map<int, int> record;
        int sum = 0;
        int res = 0;
        for (int i = 0; i < size; i++) {
            sum += nums[i];
            if (sum == k) {
                res = i + 1;
            } else {
                int target = sum - k;
                if (record.count(target)) {
                    res = max(res, i - record[target]);
                }
            }
            if (!record.count(sum)) {
                record[sum] = i;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1, -1, 5, -2, 3, -3, 1, 1, 1, 1, 1};
    // {1, -1, 5, -2, 3, -3, 4, 1};
    int k = 3;
    cout << Solution().maxSubArrayLen(nums, k) << endl;
}