//
// Created by 王存俊 on 2019-08-21.
//

class Solution {
private:
    void findPaths(TreeNode *node, int sum, vector<int>& path, vector<vector<int>>& res) {
        if (!node) return;
        path.push_back(node->val);
        if (node->val == sum && !node->left && !node->right) {
            res.push_back(path);
        }
        findPaths(node->left, sum - node->val, path,res);
        findPaths(node->right, sum - node->val, path,res);
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        findPaths(root, sum, path, res);
        return res;
    }
};
