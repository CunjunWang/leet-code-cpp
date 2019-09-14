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
private:
    ListNode *merge(ListNode *node1, ListNode *node2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;

        while (node1 && node2) {
            if (node1->val <= node2->val) {
                cur->next = node1;
                cur = cur->next;
                node1 = node1->next;
            } else {
                cur->next = node2;
                cur = cur->next;
                node2 = node2->next;
            }
        }

        if (!node1) {
            cur->next = node2;
        } else {
            cur->next = node1;
        }

        return dummyHead->next;
    }

public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next)
            return head;

        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;

        return merge(sortList(head), sortList(fast));
    }
};

int main() {
    ListNode *head = new ListNode(5);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(1);
    ListNode *node3 = new ListNode(4);
    ListNode *node4 = new ListNode(3);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    printLinkedList(head);
    ListNode* res = Solution().sortList(head);
    printLinkedList(res);
}