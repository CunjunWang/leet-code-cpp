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
    unordered_map<double, vector<int>> diffRecord;
    priority_queue<double, vector<double>, greater<double>> pq;

    void computeDifferences(TreeNode *node, double target) {
        if (!node)
            return;
        int val = node->val;
        double diff = abs(val - target);
        if (diffRecord[diff].empty()) {
            pq.emplace(diff);
        }
        diffRecord[diff].emplace_back(val);

        computeDifferences(node->left, target);
        computeDifferences(node->right, target);
    }

public:
    vector<int> closestKValues(TreeNode *root, double target, int k) {
        computeDifferences(root, target);
        vector<int> res;
        while (k > 0) {
            double diff = pq.top();
            pq.pop();
            vector<int> vals = diffRecord[diff];
            int size = vals.size();
            int loop = min(size, k);
            k -= loop;
            while (loop > 0) {
                int val = vals.back();
                vals.pop_back();
                res.emplace_back(val);
                loop--;
            }
        }
        return res;
    }
};

int main() {
    TreeNode *root = new TreeNode(4);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(7);
    TreeNode *node3 = new TreeNode(1);
    TreeNode *node4 = new TreeNode(3);
    TreeNode *node5 = new TreeNode(6);
    TreeNode *node6 = new TreeNode(9);
    TreeNode *node7 = new TreeNode(5);
    TreeNode *node8 = new TreeNode(8);
    TreeNode *node9 = new TreeNode(10);
    root->left = node1, root->right = node2;
    node1->left = node3, node1->right = node4;
    node2->left = node5, node2->right = node6;
    node5->left = node7;
    node6->left = node8, node6->right = node9;
    double target = 4;
    int k = 10;
    vector<int> res = Solution().closestKValues(root, target, k);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}