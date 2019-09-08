//
// Created by 王存俊 on 2019-09-08.
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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if (!root)
            return res;
        queue<TreeNode *> todo;
        todo.push(root);
        while (!todo.empty()) {
            int size = todo.size();
            for (int i = 0; i < size; i++) {
                TreeNode *cur = todo.front();
                todo.pop();
                if (i == size - 1)
                    res.emplace_back(cur->val);
                if (cur->left) {
                    todo.push(cur->left);
                }
                if (cur->right) {
                    todo.push(cur->right);
                }
            }
        }
        return res;
    }
};

int main() {
}