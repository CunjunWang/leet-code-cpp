//
// Created by 王存俊 on 2019-08-31.
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
#include "DoublyLinkedListNode.h"
#include "TreeNode.h"
#include "Helpers.h"

using namespace std;

// TODO:
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        unordered_set<int> visitedIndex;
        vector<int> res;
        for (int i = 0; i < edges.size(); i++) {
            vector<int> curEdge = edges[i];
            int v = curEdge[0], w = curEdge[1];
            if (visitedIndex.count(v) && visitedIndex.count(w)) {
                res = curEdge;
            } else {
                visitedIndex.insert(v);
                visitedIndex.insert(w);
            }
        }
        return res;
    }
};

int main() {
}