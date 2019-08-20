//
// Created by 王存俊 on 2019-08-20.
//

// TODO;
class Solution {
private:
    int minHeight = INT_MAX;
    int maxHeight = -1;

    void isBalancedRec(TreeNode *node, int cur) {
        if (!node) return;
        cur++;
        minHeight = min(minHeight, cur);
        maxHeight = max(maxHeight, cur);
        isBalancedRec(node->left, cur);
        isBalancedRec(node->right, cur);
    }

public:
    bool isBalanced(TreeNode *root) {
        isBalancedRec(root, 0);
        return maxHeight - minHeight <= 1;
    }
};

int main() {
    TreeNode *root = new TreeNode(3);
    TreeNode *node1 = new TreeNode(9);
    TreeNode *node2 = new TreeNode(20);
    TreeNode *node3 = new TreeNode(15);
    TreeNode *node4 = new TreeNode(7);
    root->left = node1;
    root->right = node2;
    node2->left = node3;
    node2->right = node4;
    cout << Solution().isBalanced(root) << endl;
}