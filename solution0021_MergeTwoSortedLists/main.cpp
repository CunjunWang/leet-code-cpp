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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummyHead = new ListNode(-1);
        ListNode *temp = dummyHead;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
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
};

int main() {
    vector<int> nums1 = {3};
    vector<int> nums2 = {-2, -1};
    cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
}