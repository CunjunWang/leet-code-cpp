//
// Created by 王存俊 on 2019/9/30.
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

// monotomous stack, two passes
class Solution {
public:
	vector<int> nextGreaterElements(vector<int> &nums) {
		vector<int> res(nums.size(), -1);
		stack<int> mono;

		for (int t = 0; t < 2; t++) {
			for (int i = nums.size() - 1; i >= 0; i--) {
				int num = nums[i];
				while (!mono.empty() && nums[mono.top()] <= num) {
					mono.pop();
				}
				res[i] = mono.empty() ? -1 : nums[mono.top()];
				mono.push(i);
			}
		}

		return res;
	}
};

int main() {
	vector<int> nums1 = {4, 1, 2}, nums2 = {1, 3, 4, 2};
	vector<int> res = Solution().nextGreaterElements(nums1);
	printVector(res);
}