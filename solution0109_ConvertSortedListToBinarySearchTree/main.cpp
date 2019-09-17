//
// Created by 王存俊 on 2019-09-17.
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head)
            return NULL;

        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *slow = head;
        ListNode *prev = dummyHead;
        ListNode *fast = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            prev = prev->next;
        }

        TreeNode *node = new TreeNode(slow->val);

        if (head == slow) {
            return node;
        }

        prev->next = NULL;
        dummyHead->next = NULL;
        node->left = sortedListToBST(head);
        node->right = sortedListToBST(slow->next);

        return node;
    }
};

int main() {
    // [-10,-3,0,5,9]
    ListNode *node1 = new ListNode(-10);
    ListNode *node2 = new ListNode(-3);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(5);
    ListNode *node5 = new ListNode(9);
    node1->next = node2, node2->next = node3, node3->next = node4, node4->next = node5;
    Solution().sortedListToBST(node1);

}