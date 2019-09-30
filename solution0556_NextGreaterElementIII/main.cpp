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
	int nextGreaterElement(int n) {
		if (n < 10)
			return -1;

		string s = to_string(n);

		int i = s.size() - 2;
		while (i >= 0 && s[i] >= s[i + 1]) {
			i--;
		}
		if (i < 0) {
			return -1;
		}
		int j;
		for (j = s.size() - 1; j >= 0; j--) {
			if (s[j] > s[i]) {
				char t = s[i];
				s[i] = s[j];
				s[j] = t;
				break;
			}
		}

		string sub = s.substr(i + 1);
		string pre = s.substr(0, i + 1);
		sort(sub.begin(), sub.end());
		try {
			return stoi(pre + sub);
		} catch (...) {
			return -1;
		}
	}
};

int main() {
	int n = 1999999999;
	cout << Solution().nextGreaterElement(n) << endl;
}