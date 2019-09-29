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
#include "ListNode.h"
#include "Helpers.h"

using namespace std;

class Solution {
public:
	int lastRemaining(int n) {
		bool fromLeft = true;
		int remain = n;
		int head = 1;
		int step = 1;
		while (remain > 1) {
			if (fromLeft || remain % 2 == 1) {
				head = head + step;
			}
			remain = remain / 2;
			step = step * 2;
			fromLeft = !fromLeft;
		}
		return head;
	}
};

int main() {
	string str = "bb";
	vector<vector<string>> res = Solution().flatten(str);
	printMatrix(res);
}