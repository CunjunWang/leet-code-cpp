//
// Created by 王存俊 on 2019-08-26.
//

#ifndef LEET_CODE_CPP_NODE_H
#define LEET_CODE_CPP_NODE_H

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node() {}

    Node(int _val, Node *_next, Node *_random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

#endif //LEET_CODE_CPP_NODE_H
