//
// Created by 王存俊 on 2019-08-29.
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

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>> &intervals) {
        int size = intervals.size();
        if (size <= 1)
            return true;
        sort(intervals.begin(), intervals.end());
        int curEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            vector<int> nextInterval = intervals[i];
            int nextStart = nextInterval[0];
            int nextEnd = nextInterval[1];
            if (nextStart >= curEnd) {
                curEnd = nextEnd;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<vector<int>> intervals = {{7, 10},
                                     {2, 4}};
    // {{15, 20}, {0,  30}, {5,  10}};
    cout << Solution().canAttendMeetings(intervals) << endl;
}