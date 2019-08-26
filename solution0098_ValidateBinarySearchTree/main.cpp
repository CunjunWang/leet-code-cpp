//
// Created by 王存俊 on 2019-08-26.
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
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <sstream>
#include <cassert>
#include <set>
#include "TreeNode.h"
#include "ListNode.h"

using namespace std;


class Solution {
private:
    void inOrder(TreeNode *node, vector<int> &vals) {
        if (!node)
            return;
        inOrder(node->left, vals);
        vals.push_back(node->val);
        inOrder(node->right, vals);
    }

public:
    bool isValidBST(TreeNode *root) {
        vector<int> vals;
        inOrder(root, vals);
        if (vals.size() <= 1)
            return true;
        for (int i = 1; i < vals.size(); i++) {
            if (vals[i] <= vals[i - 1])
                return false;
        }
        return true;
    }
};

int main() {
}