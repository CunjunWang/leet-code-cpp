//
// Created by 王存俊 on 2019-09-17.
//

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

// TODO:
class Solution {
public:
    Node *construct(vector<vector<int>> &grid) {
        int m = grid.size();
        if (m == 0)
            return NULL;
        int n = grid[0].size();
        if (n == 0)
            return NULL;
    }
};