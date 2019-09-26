//
// Created by 王存俊 on 2019/9/26.
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
#include "Helpers.h"

using namespace std;

// DP + prefix sum
class Solution {
public:
	int numberOfArithmeticSlices(vector<int> &A) {
		int size = A.size();
		if (size <= 2)
			return 0;
		vector<int> dp(size, 0);
		int sum = 0;
		for (int i = 2; i < size; i++) {
			if (A[i - 1] - A[i - 2] == A[i] - A[i - 1]) {
				dp[i] = dp[i - 1] + 1;
				sum += dp[i];
			} else {
				dp[i] = 0;
			}
		}
		return sum;
	}
};

int main() {
	int num = 5;
	vector<int> res = Solution().countBits(num);
	printVector(res);
}