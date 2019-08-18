//
// Created by 王存俊 on 2019-08-18.
//

#ifndef LEET_CODE_CPP_TREENODE_H
#define LEET_CODE_CPP_TREENODE_H

#include <cstdlib>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif //LEET_CODE_CPP_TREENODE_H
