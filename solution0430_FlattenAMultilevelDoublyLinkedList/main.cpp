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
	Node *prev;
	Node *next;
	Node *child;

	Node() {}

	Node(int _val, Node *_prev, Node *_next, Node *_child) {
		val = _val;
		prev = _prev;
		next = _next;
		child = _child;
	}
};

class Solution {
public:
	Node *flatten(Node *head) {
		if (!head)
			return head;

		Node* cur = head;
		while (cur) {
			if (!cur->child)
				cur = cur->next;
			else {
				Node* next = cur->next;
				Node* flattenHead = flatten(cur->child);
				cur->next = flattenHead;
				flattenHead->prev = cur;
				cur->child = NULL;
				while (cur->next) {
					cur = cur->next;
				}
				if (next) {
					cur->next = next;
				}
				cur = cur->next;
			}
		}
		return head;
	}
};

int main() {
	string str = "bb";
	vector<vector<string>> res = Solution().flatten(str);
	printMatrix(res);
}