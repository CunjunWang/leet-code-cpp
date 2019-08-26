//
// Created by 王存俊 on 2019-08-25.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include <sstream>
#include <set>
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head)
            return NULL;
        int size = 1;
        ListNode *temp = head;
        while (temp->next) {
            size++;
            temp = temp->next;
        }
        k = k % size;
        if (k == 0)
            return head;

        ListNode *rotateHead = head;
        int curIndex = 0;
        while (rotateHead->next) {
            rotateHead = rotateHead->next;
            curIndex++;
            if (curIndex == size - k - 1)
                break;
        }
        ListNode* rotatePre = rotateHead;
        rotateHead = rotateHead->next;

        rotatePre->next = NULL;
        temp->next = head;
        head = rotateHead;
        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    head->next = node1;
    int k = 1;
    cout << Solution().rotateRight(head, k) << endl;
}