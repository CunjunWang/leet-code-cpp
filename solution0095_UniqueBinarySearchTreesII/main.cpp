//
// Created by 王存俊 on 2019-09-16.
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
private:
    vector<TreeNode *> generateResult(int start, int end) {
        vector<TreeNode *> res;
        if (start > end) {
            res.emplace_back(nullptr);
            return res;
        }

        // pick up a root
        for (int i = start; i <= end; i++) {
            // all possible left subtrees if i is choosen to be a root
            vector<TreeNode *> leftTrees = generateResult(start, i - 1);

            // all possible right subtrees if i is choosen to be a root
            vector<TreeNode *> rightTrees = generateResult(i + 1, end);

            // connect left and right trees to the root i
            for (TreeNode *l : leftTrees) {
                for (TreeNode *r : rightTrees) {
                    TreeNode *currentTree = new TreeNode(i);
                    currentTree->left = l;
                    currentTree->right = r;
                    res.emplace_back(currentTree);
                }
            }
        }

        return res;
    }

public:
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> res;
        if (n == 0)
            return res;
        return generateResult(1, n);
    }
};

int main() {
    Solution().generateTrees(3);
}