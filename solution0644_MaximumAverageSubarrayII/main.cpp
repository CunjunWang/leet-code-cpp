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

// prefix sum, TLE
class Solution {
public:
	double findMaxAverage(vector<int> &nums, int k) {
		int size = nums.size();
		for (int i = 1; i < size; i++)
			nums[i] += nums[i - 1];
		if (size == 1)
			return 0.0 + nums[0];
		double res = 0.0;
		double sum = 0.0;
		while (k <= size) {
			for (int i = k - 1; i < size; i++) {
				if (i == k - 1) {
					sum = nums[i];
				} else {
					sum = nums[i] - nums[i - k];
				}
				res = max(res, sum / k);
			}
			k++;
		}
		return res;
	}
};

int main() {
	vector<int> A = {1, 12, -5, -6, 50, 3};
	int k = 4;
	double res = Solution().findMaxAverage(A, k);
	cout << res << endl;
}