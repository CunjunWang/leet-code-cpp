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
private:
	int res;

	int maxGain(TreeNode* node) {
		if (!node)
			return 0;

		int leftGain = max(maxGain(node->left), 0);
		int rightGain = max(maxGain(node->right), 0);

		int gainSum = node->val + leftGain + rightGain;

		res = max(res, gainSum);

		return node->val + max(leftGain, rightGain);
	}

public:
	int maxPathSum(TreeNode *root) {
		res = INT_MIN;
		maxGain(root);
		return res;
	}
};

int main() {

}