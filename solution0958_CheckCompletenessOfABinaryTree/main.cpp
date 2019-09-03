//
// Created by 王存俊 on 2019-09-02.
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
class Solution {
public:
    bool isCompleteTree(TreeNode *root) {
        if (!root)
            return true;

        vector<TreeNode *> todo;
        todo.emplace_back(root);
        int i = 0;
        while (i < todo.size()) {
            TreeNode *cur = todo[i];
            if (cur) {
                todo.emplace_back(cur->left);
                todo.emplace_back(cur->right);
            } else {
                break;
            }
            i++;
        }
        cout << todo.size() << endl;
        while (i < todo.size() && !todo[i]) {
            i++;
        }

        return i == todo.size();
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(3);
    TreeNode *node3 = new TreeNode(4);
    TreeNode *node4 = new TreeNode(5);
    TreeNode *node5 = new TreeNode(6);
    root->left = node1, root->right = node2;
    node1->left = node3;
    node2->left = node4, node2->right = node5;
    cout << Solution().isCompleteTree(root) << endl;
}