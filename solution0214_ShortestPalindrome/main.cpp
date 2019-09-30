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

// TODO:
// MLE
class Solution {
public:
	string shortestPalindrome(string s) {
		int size = s.size();
		if (size == 0)
			return "";
		if (size == 1)
			return s;

		string rev(s);
		reverse(rev.begin(), rev.end());

		for (int i = 0; i < size; i++) {
			if (s.substr(0, size - i) == rev.substr(i))
				return rev.substr(0, i) + s;
		}
		return "";
	}
};

int main() {

}