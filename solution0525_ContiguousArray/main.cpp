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
    int findMaxLength(vector<int> &nums) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == 0)
                nums[i] = -1;
        }
        map<int, int> record;

        // if all array has the same number of 0 and 1:
        record[0] = -1;

        int sum = 0;
        int res = 0;
        for (int i = 0; i < size; i++) {
            sum += nums[i];
            if (record.count(sum)) {
                res = max(res, i - record[sum]);
            } else {
                record[sum] = i;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {0, 0, 0, 1, 1, 0, 1};
    cout << Solution().findMaxLength(nums) << endl;
}