//
// Created by 王存俊 on 2019-08-18.
//

class Solution {

private:
    vector<string> result;

    void pathRecursive(TreeNode *node, string cur) {
        if (!node) return;

        if (!node->left && !node->right) {
            cur += to_string(node->val);
            result.push_back(cur);
        } else {
            cur = cur + to_string(node->val) + "->";
        }
        pathRecursive(node->left, cur);
        pathRecursive(node->right, cur);
    }

public:
    vector<string> binaryTreePaths(TreeNode *root) {
        pathRecursive(root, "");
        return result;
    }
};