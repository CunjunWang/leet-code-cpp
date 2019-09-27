//
// Created by 王存俊 on 2019/9/27.
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
private:
	void generateResult(string &s, vector<string> &curRes, vector<vector<string>> &res) {
		if (isPalindrome(s)) {
			curRes.emplace_back(s);
			res.emplace_back(curRes);
			curRes.pop_back();
			if (s.size() <= 1) {
				return;
			}
		}

		for (int i = 1; i < s.size(); i++) {
			string pre = s.substr(0, i);
			string suf = s.substr(i);

			if (isPalindrome(pre)) {
				curRes.emplace_back(pre);
				generateResult(suf, curRes, res);
				curRes.pop_back();
			} else {
				continue;
			}
		}
	}

	bool isPalindrome(string &s) {
		int size = s.size();
		if (size <= 1)
			return true;
		int left = 0, right = size - 1;
		while (left <= right) {
			if (s[left] != s[right])
				return false;
			left++, right--;
		}
		return true;
	}

public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		vector<string> curRes;
		if (s.empty())
			return res;
		if (s.size() == 1) {
			curRes.emplace_back(s);
			res.emplace_back(curRes);
			return res;
		}
		generateResult(s, curRes, res);
		return res;
	}
};

int main() {
	string str = "bb";
	vector<vector<string>> res = Solution().partition(str);
	printMatrix(res);
}