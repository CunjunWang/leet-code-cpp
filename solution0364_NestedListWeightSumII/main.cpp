//
// Created by 王存俊 on 2019-09-08.
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
#include "Helpers.h"

using namespace std;

// TODO: misunderstand the problem.

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
public:
    int depthSumInverse(vector<NestedInteger> &nestedList) {
        int size = nestedList.size();
        if (size == 0)
            return 0;

        stack<pair<NestedInteger, int>> todo;
        for (int i = 0; i < size; i++) {
            NestedInteger cur = nestedList[i];
            if (cur.isInteger()) {
                todo.push(make_pair(cur, 1));
            } else {
                todo.push(make_pair(cur, 2));
            }
        }

        int sum = 0;

        while (!todo.empty()) {
            pair<NestedInteger, int> curPair = todo.top();
            todo.pop();
            NestedInteger curNest = curPair.first;
            int curDepth = curPair.second;
            if (curNest.isInteger()) {
                sum += curNest.getInteger() * curDepth;
            } else {
                vector<NestedInteger> curList = curNest.getList();
                for (int i = 0; i < curList.size(); i++) {
                    if (curList[i].isInteger()) {
                        todo.push(make_pair(curList[i], curDepth));
                    } else {
                        todo.push(make_pair(curList[i], curDepth + 1));
                    }
                }
            }
        }

        return sum;
    }
};

int main() {
}