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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head || m == n)
            return head;
        ListNode *dummyHead = new ListNode(-1);
        ListNode *start = NULL;
        ListNode *end = NULL;
        ListNode *startPrev = NULL;
        ListNode *endNext = NULL;

        dummyHead->next = head;
        ListNode *prev = dummyHead;
        ListNode *cur = head;
        int count = 1;

        while (count < m) {
            count++;
            prev = cur;
            cur = cur->next;
        }
        start = cur;
        startPrev = prev;

        while (cur) {
            if (count == n + 1) {
                end = prev;
                endNext = cur;
                break;
            }
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            count++;
        }
        if (!end) {
            end = prev;
            endNext = cur;
        }

        startPrev->next = end;
        start->next = endNext;

        return dummyHead->next;
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
    int m = 2, n = 4;

//    ListNode *head = new ListNode(3);
//    ListNode *node1 = new ListNode(5);
//    head->next = node1;
//    int m = 1, n = 2;
    ListNode* res = Solution().reverseBetween(head, m, n);
    printLinkedList(res);
}