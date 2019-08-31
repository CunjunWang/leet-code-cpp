//
// Created by 王存俊 on 2019-08-31.
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

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (!l1 && !l2) return NULL;
        if (!l2) return l1;
        if (!l1) return l2;

        stack<ListNode *> s1, s2;

        ListNode *temp = l1;
        while (temp) {
            s1.push(temp);
            temp = temp->next;
        }
        temp = l2;
        while (temp) {
            s2.push(temp);
            temp = temp->next;
        }

        int carry = 0;
        stack<ListNode *> res;
        while (!s1.empty() && !s2.empty()) {
            ListNode *node1 = s1.top();
            s1.pop();
            ListNode *node2 = s2.top();
            s2.pop();

            int val = node1->val + node2->val + carry;
            carry = val >= 10 ? 1 : 0;
            val = val % 10;
            ListNode *newNode = new ListNode(val);
            res.push(newNode);
        }

        if (s1.empty()) s1 = s2;

        while (!s1.empty()) {
            ListNode *node = s1.top();
            s1.pop();
            int val = node->val + carry;
            carry = val >= 10 ? 1 : 0;
            val = val % 10;
            ListNode *newNode = new ListNode(val);
            res.push(newNode);
        }

        ListNode* newHead;
        if (carry == 1) {
            newHead = new ListNode(1);
        } else {
            newHead = res.top();
            res.pop();
        }
        temp = newHead;
        while (!res.empty()) {
            temp->next = res.top();
            res.pop();
            temp = temp->next;
        }

        return newHead;
    }
};

void printListNode(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

int main() {
//    ListNode* head1 = new ListNode(7);
//    ListNode* node11 = new ListNode(2);
//    ListNode* node12 = new ListNode(4);
//    ListNode* node13 = new ListNode(3);
//    head1->next = node11;
//    node11->next = node12;
//    node12->next = node13;
//
//    ListNode* head2 = new ListNode(5);
//    ListNode* node21 = new ListNode(6);
//    ListNode* node22 = new ListNode(4);
//    head2->next = node21;
//    node21->next = node22;

    ListNode* head1 = new ListNode(0);
    ListNode* head2 = new ListNode(0);

    printListNode(head1);
    printListNode(head2);

    ListNode* result = Solution().addTwoNumbers(head1, head2);
    printListNode(result);
}