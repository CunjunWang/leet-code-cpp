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
	int longestValidParentheses(string s) {
		int size = s.size();
		if (size <= 1)
			return 0;
		int res = 0;
		int left = 0, right = 0;
		for (int i = 0; i < size; i++) {
			if (s[i] == '(')
				left++;
			if (s[i] == ')')
				right++;
			if (left == right)
				res = max(left * 2, res);
			else if (right > left)
				left = right = 0;

		}
		left = right = 0;
		for (int i = size - 1; i >= 0; i--) {
			if (s[i] == '(')
				left++;
			if (s[i] == ')')
				right++;
			if (left == right)
				res = max(right * 2, res);
			else if (left > right)
				left = right = 0;
		}
		return res;
	}
};

int main() {
	int num = 5;
	vector<int> res = Solution().countBits(num);
	printVector(res);
}