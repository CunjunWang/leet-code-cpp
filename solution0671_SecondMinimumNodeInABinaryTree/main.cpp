//
// Created by 王存俊 on 2019-08-27.
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

class Solution {
private:
    void traverse(TreeNode *node, vector<int> &nums) {
        if (!node)
            return;
        nums.push_back(node->val);
        traverse(node->left, nums);
        traverse(node->right, nums);
    }

public:
    int findSecondMinimumValue(TreeNode *root) {
        vector<int> vals;
        traverse(root, vals);
        if (vals.size() <= 1)
            return -1;
        sort(vals.begin(), vals.end());
        int minimum = vals[0];
        for (int i = 1; i < vals.size(); i++) {
            if (vals[i] > minimum)
                return vals[i];
        }
        return -1;
    }
};

int main() {

}