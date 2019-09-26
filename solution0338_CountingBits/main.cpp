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

class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> dp(num + 1, 0);
		if (num < 1)
			return dp;
		int curPow2 = 1;
		for (int i = 1; i <= num; i++) {
			if (i == curPow2) {
				dp[i] = 1;
				curPow2 *= 2;
			} else {
				dp[i] = dp[curPow2 / 2] + dp[i - curPow2 / 2];
			}
		}
		return dp;
	}
};

int main() {
	int num = 5;
	vector<int> res = Solution().countBits(num);
	printVector(res);
}