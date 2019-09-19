//
// Created by 王存俊 on 2019-09-18.
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

// TODO
// Definition for a Node.
class Node {
public:
    int val;
    Node *next;

    Node() {}

    Node(int _val, Node *_next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node *insert(Node *head, int insertVal) {
        if (!head) {
            return new Node(insertVal, nullptr);
        }

        Node* cur = head;
        while (cur && cur->next) {
            if (cur->val <= insertVal && cur->next->val >= insertVal) {
                Node* next = cur->next;
                cur->next = new Node(insertVal, next);
                return head;
            } else if (cur->val >= cur->next->val && insertVal <= cur->next->val) {
                Node* next = cur->next;
                cur->next = new Node(insertVal, next);
                return head;
            } else if (cur->val >= cur->next->val && insertVal >= cur->val) {
                Node* next = cur->next;
                cur->next = new Node(insertVal, next);
                return head;
            }
            cur = cur->next;
        }
        return new Node(insertVal, nullptr);
    }
};

int main() {
    Node* node1 = new Node(1, nullptr);
    Node* node2 = new Node(2, nullptr);
    Node* node3 = new Node(3, nullptr);
    node1->next = node2;
    node2->next = node3;
    node3->next = node1;
    Node* head = node1;
    int val = 0;
    Node* res = Solution().insert(head, 2);
}