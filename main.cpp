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
    void doTraverse(TreeNode *node, vector<int> &list) {
        if (!node)
            return;

        list.push_back(node->val);
        doTraverse(node->left, list);
        doTraverse(node->right, list);
    }

public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        doTraverse(root, res);
        return res;
    }
};

int main() {
}