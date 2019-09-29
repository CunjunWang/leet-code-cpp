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
	int sum = 0;

	void doRecursion(TreeNode *node, string &cur) {
		if (!node)
			return;

		cur += to_string(node->val);
		// leaf
		if (!node->left && !node->right) {
			sum += stoi(cur);
			return;
		}

		doRecursion(node->left, cur);
		if (node->left) {
			cur = cur.substr(0, cur.size() - 1);
		}

		doRecursion(node->right, cur);
		if (node->right) {
			cur = cur.substr(0, cur.size() - 1);
		}
	}

public:
	int sumNumbers(TreeNode *root) {
		string cur = "";
		doRecursion(root, cur);
		return sum;
	}
};

int main() {
	TreeNode *root = new TreeNode(1);
	TreeNode *node1 = new TreeNode(5);
	TreeNode *node2 = new TreeNode(3);
	root->left = node1;
	root->right = node2;
	cout << Solution().sumNumbers(root) << endl;
}