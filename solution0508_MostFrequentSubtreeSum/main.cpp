//
// Created by 王存俊 on 2019-08-29.
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
    int calSum(TreeNode *node, map<int, int> &sumRecord) {
        if (!node)
            return 0;

        int leftSum = calSum(node->left, sumRecord);
        int rightSum = calSum(node->right, sumRecord);

        int sum = leftSum + rightSum + node->val;
        sumRecord[sum]++;

        return sum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode *root) {
        map<int, int> sumRecord;
        int sum = calSum(root, sumRecord);

        int maxVal = -1;
        for (auto &it : sumRecord) {
            maxVal = max(maxVal, it.second);
        }

        vector<int> res;
        for (auto &it : sumRecord) {
            if (it.second == maxVal) {
                res.push_back(it.first);
            }
        }
        return res;
    }
};

int main() {
    TreeNode *root = new TreeNode(5);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(-3);
    root->left = node1, root->right = node2;
    vector<int> res = Solution().findFrequentTreeSum(root);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}