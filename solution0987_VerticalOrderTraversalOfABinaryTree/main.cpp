//
// Created by 王存俊 on 2019-09-17.
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

    struct Node {
        TreeNode *treeNode;
        int x;
        int y;
    };

    struct CompareNode {
        bool operator()(Node node1, Node node2) {
            if (node1.y == node2.y) {
                return node1.treeNode->val > node2.treeNode->val;
            }
            return node1.y > node2.y;
        }
    };

    map<int, priority_queue<Node, vector<Node>, CompareNode>> record;

public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        if (!root)
            return {};

        queue<Node> todo;
        todo.push({root, 0, 0});
        while (!todo.empty()) {
            Node cur = todo.front();
            todo.pop();

            TreeNode *treeNode = cur.treeNode;
            int x = cur.x;
            int y = cur.y;
            if (treeNode->left) {
                todo.push({treeNode->left, x - 1, y + 1});
            }
            if (treeNode->right) {
                todo.push({treeNode->right, x + 1, y + 1});
            }

            record[x].push({treeNode, x, y});
        }

        vector<vector<int>> res;
        for (auto it : record) {
            auto curQueue = it.second;
            vector<int> curRes;
            while (!curQueue.empty()) {
                Node cur = curQueue.top();
                curRes.emplace_back(cur.treeNode->val);
                curQueue.pop();
            }
            res.push_back(curRes);
        }

        return res;
    }
};


int main() {
    TreeNode *node1 = new TreeNode(0);
    TreeNode *node2 = new TreeNode(5);
    TreeNode *node3 = new TreeNode(1);
    TreeNode *node4 = new TreeNode(9);
    TreeNode *node5 = new TreeNode(2);
    TreeNode *node6 = new TreeNode(3);
    TreeNode *node7 = new TreeNode(4);
    TreeNode *node8 = new TreeNode(8);
    TreeNode *node9 = new TreeNode(6);
    TreeNode *node10 = new TreeNode(7);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node3->left = node5;
    node5->right = node6;
    node6->left = node7;
    node6->right = node8;
    node7->left = node9;
    node9->left = node10;
    vector<vector<int>> res = Solution().verticalTraversal(node1);
    printMatrix(res);
}