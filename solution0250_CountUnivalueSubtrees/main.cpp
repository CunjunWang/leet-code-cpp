//
// Created by 王存俊 on 2019-09-19.
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
    int res = 0;

    bool traverse(TreeNode *node) {
        if (!node->left && !node->right) {
            res++;
            return true;
        }
        bool uni = true;

        // check if all of the node's children are univalue subtrees
        // and if they have the same value also recursively call is_uni for children
        if (node->left) {
            uni = traverse(node->left) && uni && node->left->val == node->val;
        }

        if (node->right) {
            uni = traverse(node->right) && uni && node->right->val == node->val;
        }

        // return if a univalue tree exists here and increment if it does
        if (!uni) return false;

        res++;
        return true;

    }

public:
    int countUnivalSubtrees(TreeNode *root) {
        if (!root) return 0;
        traverse(root);
        return res;
    }
};

int main() {

}