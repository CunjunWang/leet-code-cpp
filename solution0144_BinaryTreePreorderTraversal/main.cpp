//
// Created by 王存俊 on 2019-08-27.
//

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
    void doTraverse(TreeNode *node, vector<int> &list) {
        if (!node)
            return;

        list.push_back(node->val);
        doTraverse(node->left, list);
        doTraverse(node->right, list);
    }

public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        doTraverse(root, res);
        return res;
    }
};