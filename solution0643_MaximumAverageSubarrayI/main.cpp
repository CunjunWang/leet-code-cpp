//
// Created by 王存俊 on 2019/9/29.
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
	double findMaxAverage(vector<int> &nums, int k) {
		int size = nums.size();
		if (size == 0)
			return 0;
		if (size == 1)
			return nums[0];

		double sum = 0.0;
		for (int i = 0; i < k; i++) {
			sum += nums[i];
		}
		double res = sum;

		for (int i = 0, j = i + k; j < size; i++, j++) {
			sum = sum - nums[i] + nums[j];
			res = max(res, sum);
		}

		return res / k;
	}
};

int main() {
	vector<int> A = {1, 12, -5, -6, 50, 3};
	int k = 4;
	double res = Solution().findMaxAverage(A, k);
	cout << res << endl;
}