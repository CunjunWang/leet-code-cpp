//
// Created by 王存俊 on 2019-09-17.
//

#ifndef LEET_CODE_CPP_QUADTREENODE_H
#define LEET_CODE_CPP_QUADTREENODE_H

class Node {
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

#endif //LEET_CODE_CPP_QUADTREENODE_H
