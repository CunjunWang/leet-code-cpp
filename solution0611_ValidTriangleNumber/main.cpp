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
    int triangleNumber(vector<int> &nums) {
        int size = nums.size();
        if (size <= 2)
            return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < size - 2; i++) {
            int a = nums[i];
            int left = i + 1, right = left + 1;
            while (left < right && right < size) {
                int b = nums[left], c = nums[right];
                if (a + b > c) {
                    res++;
                    right++;
                    if (right >= size) {
                        left++;
                        right = left + 1;
                    }
                } else {
                    left++;
                    right = left + 1;
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    cout << Solution().triangleNumber(nums) << endl;
}