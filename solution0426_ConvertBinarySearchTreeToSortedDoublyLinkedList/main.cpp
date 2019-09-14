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
#include "DoublyLinkedListNode.h"
#include "Helpers.h"

using namespace std;

class Solution {
private:
    Node *head;
    Node *tail;

    void inOrderTraverse(Node *node) {
        if (!node)
            return;
        inOrderTraverse(node->left);
        if (!head)
            head = node;
        else {
            node->left = tail;
            tail->right = node;
        }
        tail = node;
        inOrderTraverse(node->right);
    }

public:
    Node *treeToDoublyList(Node *root) {
        if (!root)
            return NULL;
        head = NULL;
        tail = NULL;
        inOrderTraverse(root);
        head->left = tail;
        tail->right = head;
        return head;
    }
};

int main() {


}