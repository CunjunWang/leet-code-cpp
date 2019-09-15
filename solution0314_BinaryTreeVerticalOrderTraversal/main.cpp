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
    vector<vector<int>> verticalOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        int minCol = 0, maxCol = 0;
        map<int, vector<int>> record;
        queue<pair<TreeNode *, int>> todo;
        todo.push(make_pair(root, 0));
        while (!todo.empty()) {
            pair<TreeNode*, int> cur = todo.front();
            todo.pop();
            TreeNode* node = cur.first;
            int column = cur.second;
            record[column].emplace_back(node->val);
            if (node->left) {
                todo.push(make_pair(node->left, column - 1));
            }
            if (node->right) {
                todo.push(make_pair(node->right, column + 1));
            }
        }

        for (auto it = record.begin(); it != record.end(); it++) {
            res.emplace_back(it->second);
        }

        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    TreeNode* node1 = new TreeNode(9);
    TreeNode* node2 = new TreeNode(20);
    TreeNode* node3 = new TreeNode(15);
    TreeNode* node4 = new TreeNode(7);
    root->left = node1;
    root->right = node2;
    node2->left = node3;
    node2->right = node4;
    vector<vector<int>> res = Solution().verticalOrder(root);
    printMatrix(res);
}