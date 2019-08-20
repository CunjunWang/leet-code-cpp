#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include <sstream>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        int pVal = p->val;
        int qVal = q->val;
        int rootVal = root->val;
        if (pVal > rootVal && qVal > rootVal) {
            return lowestCommonAncestor(root->right, p, q);
        } else if (pVal < rootVal && qVal < rootVal){
            return lowestCommonAncestor(root->left, p, q);
        } else {
            return root;
        }
    }
};

int main() {

}