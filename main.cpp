#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include <sstream>
#include "TreeNode.h"

using namespace std;

class Solution {

private:
    int count(TreeNode* node, int sum) {
        if (!node) return 0;
        int isMe = node->val == sum ? 1 : 0;
        int left = count(node->left, sum - node->val);
        int right = count(node->right, sum - node->val);
        return isMe + left + right;
    }

public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        int fromThis = count(root, sum);
        int fromLeft = pathSum(root->left, sum);
        int fromRight = pathSum(root->right, sum);
        return fromThis + fromLeft + fromRight;
    }
};

int main() {

}