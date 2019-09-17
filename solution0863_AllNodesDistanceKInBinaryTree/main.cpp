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
    unordered_map<int, unordered_set<int>> graph;

    unordered_map<int, vector<int>> distances;

    void buildGraph(TreeNode *node) {
        if (!node)
            return;
        int val = node->val;
        if (node->left) {
            int leftVal = node->left->val;
            graph[val].insert(node->left->val);
            graph[leftVal].insert(node->val);
            buildGraph(node->left);
        }
        if (node->right) {
            int rightVal = node->right->val;
            graph[val].insert(node->right->val);
            graph[rightVal].insert(node->val);
            buildGraph(node->right);
        }
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int K) {
        if (!root || !target)
            return {};
        if (K == 0)
            return {target->val};

        buildGraph(root);

        vector<int> res;

        unordered_set<int> visited;
        int dist = 0;
        int targetVal = target->val;
        queue<pair<int, int>> todo;
        todo.push(make_pair(targetVal, 0));
        visited.insert(targetVal);
        while (!todo.empty()) {
            auto cur = todo.front();
            todo.pop();

            int curDist = cur.second;
            if (curDist > K) {
                break;
            }
            int curVertex = cur.first;
            curDist++;
            unordered_set<int> adj = graph[curVertex];
            for (auto it : adj) {
                if (visited.find(it) == visited.end()) {
                    visited.insert(it);
                    todo.push(make_pair(it, curDist));
                    distances[curDist].emplace_back(it);
                }
            }
        }

        return distances[K];
    }
};

int main() {
    // [3,5,1,6,2,0,8,null,null,7,4]
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(5);
    TreeNode *node3 = new TreeNode(1);
    TreeNode *node4 = new TreeNode(6);
    TreeNode *node5 = new TreeNode(2);
    TreeNode *node6 = new TreeNode(0);
    TreeNode *node7 = new TreeNode(8);
    TreeNode *node8 = new TreeNode(7);
    TreeNode *node9 = new TreeNode(4);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    node5->left = node8;
    node5->right = node9;
    int K = 2;
    vector<int> res = Solution().distanceK(node1, node2, K);
    printVector(res);
}
