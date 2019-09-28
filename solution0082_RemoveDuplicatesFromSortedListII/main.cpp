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
	ListNode *deleteDuplicates(ListNode *head) {
		if (!head || !head->next)
			return head;
		ListNode *dummyHead = new ListNode(-1);
		dummyHead->next = head;

		ListNode *prev = dummyHead;
		ListNode *cur = head;
		while (cur) {
			if (cur->next) {
				if (cur->next->val == cur->val) {
					cur = cur->next;
				} else {
					if (prev->next == cur) {
						cur = cur->next;
						prev = prev->next;
					} else {
						cur = cur->next;
						prev->next = cur;
					}
				}
			} else {
				if (prev->next == cur) {
					break;
				} else {
					if (prev->next->val == cur->val) {
						prev->next = cur->next;
						cur = cur->next;
					} else {
						break;
					}
				}
			}
		}
		return dummyHead->next;
	}
};

int main() {
	ListNode *head = new ListNode(1);
	ListNode *node1 = new ListNode(1);
//	ListNode *node2 = new ListNode(3);
//	ListNode *node3 = new ListNode(3);
//	ListNode *node4 = new ListNode(4);
//	ListNode *node5 = new ListNode(4);
//	ListNode *node6 = new ListNode(5);

//	ListNode *head = new ListNode(1);
//	ListNode *node1 = new ListNode(1);
//	ListNode *node2 = new ListNode(1);
//	ListNode *node3 = new ListNode(2);
//	ListNode *node4 = new ListNode(3);

	head->next = node1;
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = node4;
//	node4->next = node5;
//	node5->next = node6;
	ListNode *res = Solution().deleteDuplicates(head);
	printLinkedList(res);
}