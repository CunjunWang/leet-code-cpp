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
	int maxTurbulenceSize(vector<int> &A) {
		int size = A.size();
		if (size <= 1)
			return size;

		int res = 0, counter = 0;
		for (int i = 0; i < size - 1; i++) {
			if (A[i] > A[i + 1])
				counter = counter > 0 ? counter + 1 : 1;
			else if (A[i] < A[i + 1])
				counter = counter < 0 ? counter - 1 : -1;
			else
				counter = 0;
			res = max(res, abs(counter));
			counter = counter * -1;
		}
		return res + 1;
	}
};

int main() {
	vector<int> A = {0, 1, 1, 0, 1, 0, 1, 1, 0, 0};
	int res = Solution().maxTurbulenceSize(A);
	cout << res << endl;
}