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

class Solution {
public:
	void wiggleSort(vector<int> &nums) {
		sort(nums.begin(), nums.end());
		if (nums.size() <= 2)
			return;
		for (int i = 1; i < nums.size(); i = i + 2) {
			if (i + 1 < nums.size()) {
				swap(nums[i], nums[i + 1]);
			}
		}
	}
};

int main() {
	vector<int> nums = {3, 5, 2, 1, 6, 4};
	Solution().wiggleSort(nums);
	printVector(nums);
}