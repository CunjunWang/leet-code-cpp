//
// Created by 王存俊 on 2019-09-01.
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

// Solution 1:
// do Merge 2 list k - 1 times

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
    ListNode *merge2SortedList(ListNode *l1, ListNode *l2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* temp = dummyHead;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1->next;
                temp = temp->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
                temp = temp->next;
            }
        }

        while (l1) {
            temp->next = l1;
            l1 = l1->next;
            temp = temp->next;
        }

        while (l2) {
            temp->next = l2;
            l2 = l2->next;
            temp = temp->next;
        }

        return dummyHead->next;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int size = lists.size();
        if (size == 0)
            return NULL;
        if (size == 1)
            return lists[0];

        stack<ListNode *, vector<ListNode *>> todo(lists);

        while (todo.size() >= 2) {
            ListNode *l1 = todo.top();
            todo.pop();
            ListNode *l2 = todo.top();
            todo.pop();
            ListNode *merged = merge2SortedList(l1, l2);
            todo.push(merged);
        }

        return todo.top();
    }
};

int main() {
    vector<int> nums1 = {3};
    vector<int> nums2 = {-2, -1};
    cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
}