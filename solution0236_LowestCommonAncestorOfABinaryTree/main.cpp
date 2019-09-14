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

class Solution {
private:
    TreeNode *res = NULL;

    bool search(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || !p || !q)
            return false;
        // current node is p or q
        int cur = (root->val == p->val || root->val == q->val) ? 1 : 0;

        // left subtree contains p or q
        int left = search(root->left, p, q) ? 1 : 0;

        // right subtree contains p or q
        int right = search(root->right, p, q) ? 1 : 0;

        // if any of the two flag is true
        if (left + right + cur >= 2) {
            // we have find the result;
            res = root;
        }

        // return true if any of the flag is true;
        return left + right + cur > 0;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        search(root, p, q);
        return res;
    }
};

int main() {

}