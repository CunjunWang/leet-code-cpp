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
    int threeSumClosest(vector<int> &nums, int target) {

    }

    // brute force
//    int threeSumClosest(vector<int> &nums, int target) {
//        int size = nums.size();
//        assert(size >= 3);
//        int minDiff = INT_MAX, res = 0;
//        for (int i = 0; i < size; i++) {
//            for (int j = i + 1; j < size; j++) {
//                for (int k = j + 1; k < size; k++) {
//                    int sum = nums[i] + nums[j] + nums[k];
//                    int diff = abs(sum - target);
//                    if (diff <= minDiff) {
//                        minDiff = diff;
//                        res = sum;
//                    }
//                }
//            }
//        }
//        return res;
    }
};

int main() {
}