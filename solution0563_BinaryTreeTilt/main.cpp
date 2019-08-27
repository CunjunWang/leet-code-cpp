//
// Created by 王存俊 on 2019-08-27.
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


class Solution {
private:
    int res;

    int sumNode(TreeNode *node) {
        if (!node) {
            return 0;
        }
        int left = sumNode(node->left);
        int right = sumNode(node->right);
        int tilt = max(left, right) - min(left, right);
        res += tilt;
        return left + node->val + right;
    }

public:
    int findTilt(TreeNode *root) {
        sumNode(root);
        return res;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(3);
    root->left = node1;
    root->right = node2;
    cout << Solution().findTilt(root) << endl;
}