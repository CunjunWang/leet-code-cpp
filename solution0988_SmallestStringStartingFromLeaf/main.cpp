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
	string smallestFromLeaf(TreeNode *root) {
		set<string> result;
		dfs(root, "", result);
		return *result.begin();
	}

	void dfs(TreeNode *root, string solution, set<string> &result) {
		if (!root) {
			return;
		}
		string val;
		val.push_back((char) ('a' + root->val));
		if (!root->left && !root->right) {
			solution = val + solution;
			result.insert(solution);
		}
		if (root->left) {
			dfs(root->left, val + solution, result);
		}
		if (root->right) {
			dfs(root->right, val + solution, result);
		}
	}
};

int main() {
	TreeNode *root = new TreeNode(0);
	TreeNode *node1 = new TreeNode(1);
	TreeNode *node2 = new TreeNode(2);
	TreeNode *node3 = new TreeNode(3);
	TreeNode *node4 = new TreeNode(4);
	TreeNode *node5 = new TreeNode(3);
	TreeNode *node6 = new TreeNode(4);
	root->left = node1, root->right = node2;
	node1->left = node3, node1->right = node4;
	node2->left = node5, node2->right = node6;
	cout << Solution().smallestFromLeaf(root) << endl;
}