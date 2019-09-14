//
// Created by 王存俊 on 2019-09-14.
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
    void reorderList(ListNode *head) {
        if (!head || !head->next) {
            return;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            if (!fast->next->next) {
                fast = fast->next;
            } else {
                fast = fast->next->next;
            }
        }

        fast = slow->next;
        slow->next = nullptr;

        stack<ListNode *> secondHalf;
        while (fast) {
            secondHalf.push(fast);
            fast = fast->next;
        }

        ListNode *cur = head;
        while (cur && !secondHalf.empty()) {
            ListNode *next = cur->next;
            cur->next = secondHalf.top();;
            secondHalf.pop();
            cur->next->next = next;
            cur = next;
        }

    }
};

int main() {
    ListNode *head = new ListNode(1);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(4);
    ListNode *node4 = new ListNode(5);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    printLinkedList(head);
    Solution().reorderList(head);
    printLinkedList(head);

}