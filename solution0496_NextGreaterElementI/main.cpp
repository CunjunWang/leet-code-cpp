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

// monotonous stack method
class Solution {
public:
	vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
		vector<int> res;

		stack<int> monoStack;
		unordered_map<int, int> record;

		for (int i = 0; i < nums2.size(); i++) {
			int num = nums2[i];
			while (!monoStack.empty() && num > monoStack.top()) {
				int top = monoStack.top();
				record[top] = num;
				monoStack.pop();
			}
			monoStack.push(num);
		}

		for (int i = 0; i < nums1.size(); i++) {
			if (record.count(nums1[i])) {
				res.emplace_back(record[nums1[i]]);
			} else {
				res.emplace_back(-1);
			}
		}

		return res;
	}
};

int main() {
	vector<int> nums1 = {4, 1, 2}, nums2 = {1, 3, 4, 2};
	vector<int> res = Solution().nextGreaterElement(nums1, nums2);
	printVector(res);
}