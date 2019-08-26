//
// Created by 王存俊 on 2019-08-26.
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
#include "TreeNode.h"
#include "ListNode.h"

using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node() {}

    Node(int _val, Node *_next, Node *_random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    // O(n) time, O(1) space solution, with hashtable
    Node *copyRandomList(Node *head) {
        if (!head)
            return NULL;


        // first pass, record all nodes in a hashtable
        unordered_map<Node *, Node *> record;

        Node *cur = head;
        while (cur) {
            Node *copy = new Node(cur->val, cur->next, cur->random);
            record[cur] = copy;
            cur = cur->next;
        }

        // second pass, add pointers to copied node
        cur = head;
        while (cur) {
            Node *copy = record[cur];
            copy->next = record[cur->next];
            copy->random = record[cur->random];
            cur = cur->next;
        }

        return record[head];
    }
};

int main() {
    Node *head = new Node(1, nullptr, nullptr);
    Node *node1 = new Node(2, nullptr, nullptr);
    head->next = node1;
    head->random = node1;
    node1->random = node1;
    Solution().copyRandomList(head);
}