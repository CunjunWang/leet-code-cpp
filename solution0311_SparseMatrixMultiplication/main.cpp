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
	vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
		int m = A.size(), n = A[0].size(), k = B[0].size();
		assert(n == B.size());
		vector<vector<int>> C(m, vector<int>(k, 0));

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (A[i][j] != 0) {
					for (int p = 0; p < k; p++) {
						if (B[j][p] != 0)
							C[i][p] += A[i][j] * B[j][p];
					}
				}
			}
		}
		return C;
	}
};

int main() {
}