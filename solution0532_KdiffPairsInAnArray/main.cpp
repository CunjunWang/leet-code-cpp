//
// Created by 王存俊 on 2019-08-25.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include <sstream>
#include <set>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        if (nums.size() <= 1)
            return 0;
        map<int, int> record;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (record[nums[i]] == 0) {
                if (record[nums[i] + k] != 0 || record[nums[i] - k] != 0) {
                    res++;
                }
            } else {
                record[nums[i]]++;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {3, 1, 4, 1, 5};
    int k = 2;
    cout << Solution().findPairs(nums, k) << endl;
}