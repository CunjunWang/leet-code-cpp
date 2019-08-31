//
// Created by 王存俊 on 2019-08-31.
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
    int result = -1;

    void findClosest(TreeNode* root, double target, double diff) {
        if (!root)
            return;

        int val = root->val;
        double curDiff = abs(val - target);
        if (curDiff <= diff) {
            diff = curDiff;
            result = val;
        }
        findClosest(root->left, target, diff);
        findClosest(root->right, target, diff);
    }

public:
    int closestValue(TreeNode *root, double target) {
        double diff = LONG_LONG_MAX;
        findClosest(root, target, diff);
        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(0);
    double target = 2147483648.0;
    cout << Solution().closestValue(root, target) << endl;
}