//
// Created by 王存俊 on 2019-09-18.
//

// TODO:
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
    bool checkBST(TreeNode *root) {
        if (!root)
            return true;
        if (root->left && !root->right) {
            return (root->left->val < root->val) && checkBST(root->left);
        } else if (root->right && !root->left) {
            return (root->right->val > root->val) && checkBST(root->right);
        } else if (!root->left && !root->right) {
            return true;
        } else {
            return (root->left->val < root->val && root->val < root->right->val) &&
                   checkBST(root->left) && checkBST(root->right);
        }
    }

public:
    int largestBSTSubtree(TreeNode *root) {
        checkBST(root);
    }
};