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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    queue<int> elements;

    void inOrderTraverse(TreeNode *root) {
        if (!root)
            return;
        inOrderTraverse(root->left);
        elements.push(root->val);
        inOrderTraverse(root->right);
    }

public:
    BSTIterator(TreeNode *root) {
        inOrderTraverse(root);
    }

    /** @return the next smallest number */
    int next() {
        int res = elements.front();
        elements.pop();
        return res;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !elements.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {


}