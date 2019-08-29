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
    TreeNode *doPrune(TreeNode *node) {
        if (!node) {
            return NULL;
        }
        int leftCount = countValue(node->left);
        int rightCount = countValue(node->right);

        if (leftCount == 0) {
            node->left = NULL;
        } else {
            node->left = doPrune(node->left);
        }
        if (rightCount == 0) {
            node->right = NULL;
        } else {
            node->right = doPrune(node->right);
        }

        return node;
    }

    int countValue(TreeNode *node) {
        if (!node)
            return 0;
        int leftValue = countValue(node->left);
        int rightValue = countValue(node->right);
        return node->val + leftValue + rightValue;
    }

public:
    TreeNode *pruneTree(TreeNode *root) {
        return doPrune(root);
    }
};

int main() {
}