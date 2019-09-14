//
// Created by 王存俊 on 2019-09-14.
//

#ifndef LEET_CODE_CPP_DOUBLYLINKEDLISTNODE_H
#define LEET_CODE_CPP_DOUBLYLINKEDLISTNODE_H

class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

#endif //LEET_CODE_CPP_DOUBLYLINKEDLISTNODE_H
