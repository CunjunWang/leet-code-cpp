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


// Definition for a Node.
class Node {
public:
	int val;
	Node *left;
	Node *right;
	Node *next;

	Node() {}

	Node(int _val, Node *_left, Node *_right, Node *_next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};

class Solution {
public:
	Node *connect(Node *root) {
		if (!root)
			return root;

		queue<Node *> todo;
		todo.push(root);
		while (!todo.empty()) {
			int size = todo.size();
			vector<Node *> list;
			for (int i = 0; i < size; i++) {
				Node *cur = todo.front();
				todo.pop();
				list.emplace_back(cur);
				if (cur->left)
					todo.push(cur->left);
				if (cur->right)
					todo.push(cur->right);
			}
			for (int i = 0; i < size; i++) {
				if (i == size - 1) {
					list[i]->next = NULL;
				} else {
					list[i]->next = list[i + 1];
				}
			}
		}
		return root;
	}
};

int main() {
}