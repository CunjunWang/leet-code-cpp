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
	int countNumbersWithUniqueDigits(int n) {
		if (n > 10 || n < 0)
			return 0;
		if (n == 0)
			return 1;
		vector<int> memo(10, 1);
		memo[0] = 9;
		int res = 10;
		for (int i = 1; i < n; i++) {
			int count = (10 - i) * memo[i - 1];
			memo[i] = count;
			res += count;
		}
		return res;
	}
};

int main() {
	int num = 3;
	int res = Solution().countNumbersWithUniqueDigits(num);
	cout << res << endl;
}