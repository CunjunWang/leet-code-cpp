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

private:
    void generateSubarray(vector<int> &nums, vector<vector<int>> &container,
                          vector<int> &subset, int start) {
        if (start == nums.size()) {
            container.push_back(subset);
            return;
        }

        subset.push_back(nums[start]);
        generateSubarray(nums, container, subset, start + 1);
        subset.pop_back();
        generateSubarray(nums, container, subset, start + 1);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> subsetContainer;
        vector<int> subset;
        generateSubarray(nums, subsetContainer, subset, 0);
        return subsetContainer;
    }
};


int main() {
}