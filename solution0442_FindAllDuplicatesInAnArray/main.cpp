//
// Created by 王存俊 on 2019-09-14.
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
public:
    vector<int> findDuplicates(vector<int> &nums) {
        int size = nums.size();
        vector<int> res;
        if (size <= 1) {
            return res;
        }

        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
            else
                i++;
        }

        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1)
                res.push_back(nums[i]);
        }

        return res;
    }
};

int main() {
    vector<int> nums = {5, 4, 6, 7, 9, 3, 10, 9, 5, 6};
    vector<int> res = Solution().findDuplicates(nums);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}