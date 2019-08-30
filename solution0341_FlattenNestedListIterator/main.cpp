//
// Created by 王存俊 on 2019-08-30.
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

class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
    stack<NestedInteger> data;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        int size = nestedList.size();
        for (int i = size - 1; i >= 0; --i) {
            data.push(nestedList[i]);
        }
    }

    int next() {
        int result = data.top().getInteger();
        data.pop();
        return result;
    }

    bool hasNext() {
        while (!data.empty()) {
            NestedInteger cur = data.top();
            if (cur.isInteger()) {
                return true;
            }
            data.pop();

            vector<NestedInteger> newList = cur.getList();
            for (int i = newList.size() - 1; i >= 0; i--) {
                data.push(newList[i]);
            }
        }
        return false;
    }
};

// Example 1:
//
// Input: [[1,1],2,[1,1]]
// Output: [1,1,2,1,1]
// Explanation: By calling next repeatedly until hasNext returns false,
//             the order of elements returned by next should be: [1,1,2,1,1].
//
// Example 2:
//
// Input: [1,[4,[6]]]
// Output: [1,4,6]
// Explanation: By calling next repeatedly until hasNext returns false,
//             the order of elements returned by next should be: [1,4,6].


/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main() {}