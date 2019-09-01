//
// Created by 王存俊 on 2019-09-01.
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
class Codec {
private:
    string res;

    void doSerialize(TreeNode *node, ostringstream &out) {
        if (!node) {
            out << "NULL ";
        } else {
            out << node->val << ' ';
            doSerialize(node->left, out);
            doSerialize(node->right, out);
        }
    }

    TreeNode *doDeserialize(istringstream &in) {
        string val;
        in >> val;
        if (val == "NULL")
            return NULL;
        TreeNode *node = new TreeNode(stoi(val));
        node->left = doDeserialize(in);
        node->right = doDeserialize(in);
        return node;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        ostringstream out;
        doSerialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        istringstream in(data);
        return doDeserialize(in);
    }
};
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
    Codec* obj = new Codec();
    TreeNode *root = new TreeNode(3);
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(4);
    root->left = node1, root->right = node2;
    cout << obj->serialize(root) << endl;
}