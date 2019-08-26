//
// Created by 王存俊 on 2019-08-26.
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


class Node {
public:
    int val;
    vector<Node *> neighbors;

    Node() {}

    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    unordered_map<Node *, Node *> copies;

public:
    // solution1: bfs
//    Node *cloneGraph(Node *node) {
//        if (!node)
//            return NULL;
//
//        Node *copyNode = new Node(node->val, {});
//        copies[node] = copyNode;
//
//        queue<Node *> q;
//        q.push(node);
//        while (!q.empty()) {
//            Node *cur = q.front();
//            q.pop();
//            for (Node *neighbor : cur->neighbors) {
//                // 该相邻node还没复制过
//                if (copies.find(neighbor) == copies.end()) {
//                    q.push(neighbor);
//                    Node *newNode = new Node(neighbor->val, {});
//                    copies[neighbor] = newNode;
//                }
//                // 加入邻居
//                copies[cur]->neighbors.push_back(copies[neighbor]);
//            }
//        }
//
//        return copies[node];
//    }

    // solution2: dfs
    Node *cloneGraph(Node *node) {
        if (!node)
            return NULL;

        Node *copyNode = new Node(node->val, {});
        copies[node] = copyNode;

        stack<Node *> todo;
        todo.push(node);
        while (!todo.empty()) {
            Node *cur = todo.top();
            todo.pop();
            for (Node *neighbor : cur->neighbors) {
                // 该相邻node还没复制过
                if (copies.find(neighbor) == copies.end()) {
                    todo.push(neighbor);
                    Node *newNode = new Node(neighbor->val, {});
                    copies[neighbor] = newNode;
                }
                // 加入邻居
                copies[cur]->neighbors.push_back(copies[neighbor]);
            }
        }

        return copies[node];
    }
};

int main() {
}