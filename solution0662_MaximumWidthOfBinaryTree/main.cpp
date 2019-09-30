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

// TODO
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int widthOfBinaryTree(TreeNode *root) {
		return dfs(root, 0, 1, vector<pair<int, int>>() = {});
	}

	int dfs(TreeNode *root, long long level, long long order, vector<pair<int, int>> &vec) {
		if (!root)
			return 0;
		if (vec.size() == level)
			vec.emplace_back(order, order);
		else
			vec[level].second = order;

		return vec[level].second - vec[level].first + 1 <
			   max(dfs(root->left, level + 1, 2 * order, vec), dfs(root->right, level + 1, 2 * order + 1, vec)) ?
			   max(dfs(root->left, level + 1, 2 * order, vec), dfs(root->right, level + 1, 2 * order + 1, vec)) :
			   vec[level].second - vec[level].first + 1;
	}
};

int main() {
	TreeNode *root = new TreeNode(1);
	TreeNode *node1 = new TreeNode(1);
	TreeNode *node2 = new TreeNode(1);
	TreeNode *node3 = new TreeNode(1);
	TreeNode *node4 = new TreeNode(1);
	TreeNode *node5 = new TreeNode(1);
	TreeNode *node6 = new TreeNode(1);
	root->left = node1, root->right = node2;
	node1->left = node3;
	node2->right = node4;
	node2->left = node5;
	// node2->right = node6;
	cout << Solution().widthOfBinaryTree(root) << endl;
}