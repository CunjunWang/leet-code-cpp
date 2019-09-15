//
// Created by 王存俊 on 2019-09-15.
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
#include "DoublyLinkedListNode.h"
#include "TreeNode.h"
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty() || inorder.empty())
            return NULL;

        int rootVal = preorder[0];
        preorder.erase(preorder.begin());
        TreeNode *root = new TreeNode(rootVal);
        int rootInInorder = find(inorder.begin(), inorder.end(), rootVal) - inorder.begin();

        vector<int> leftInorder = vector<int>(inorder.begin(), inorder.begin() + rootInInorder);
        vector<int> rightInorder = vector<int>(inorder.begin() + 1 + rootInInorder, inorder.end());

        root->left = buildTree(preorder, leftInorder);
        root->right = buildTree(preorder, rightInorder);

        return root;
    }
};

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode* res = Solution().buildTree(preorder, inorder);
    cout << res << endl;
}