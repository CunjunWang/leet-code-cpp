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

// Solution 1 :
// use stacks

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        int size = intervals.size();
        if (size <= 1)
            return intervals;

        vector<vector<int>> res;

        stack<vector<int>> todo;
        sort(intervals.begin(), intervals.end());
        for (int i = size - 1; i >= 0; i--) {
            todo.push(intervals[i]);
        }

        while (todo.size() >= 2) {
            vector<int> thisInterval = todo.top();
            todo.pop();
            vector<int> nextInterval = todo.top();
            todo.pop();

            int thisStart = thisInterval[0];
            int thisEnd = thisInterval[1];
            int nextStart = nextInterval[0];
            int nextEnd = nextInterval[1];

            // can merge
            if (thisEnd >= nextStart) {
                int end = max(thisEnd, nextEnd);
                vector<int> merged = {thisStart, end};
                todo.push(merged);
            } else {
                res.push_back(thisInterval);
                todo.push(nextInterval);
            }
        }

        res.push_back(todo.top());

        return res;
    }
};

int main() {
    vector<vector<int>> intervals = {{1, 4},
                                     {4, 5}};
    // {{1,  3}, {2,  6}, {8,  10}, {15, 18}};
    vector<vector<int>> res = Solution().merge(intervals);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}