//
// Created by 王存俊 on 2019-08-29.
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool traverse(TreeNode *s, TreeNode *t) {
        if (!s)
            return false;
        return (equals(s, t) || traverse(s->left, t) || traverse(s->right, t));
    }

    bool equals(TreeNode *s, TreeNode *t) {
        if (!s && !t) {
            return true;
        } else if (!s || !t) {
            return false;
        } else {
            return (s->val == t->val) && equals(s->left, t->left) && equals(s->right, t->right);
        }
    }

public:
    bool isSubtree(TreeNode *s, TreeNode *t) {
        return traverse(s, t);
    }
};

int main() {
}