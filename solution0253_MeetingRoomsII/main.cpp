//
// Created by 王存俊 on 2019-09-04.
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

class Solution {

public:

    struct Order {
        bool operator()(vector<int> &a, vector<int> &b) const {
            return a[1] > b[1] || (a[1] == b[1] && a[0] > b[0]);
        }
    };

    int minMeetingRooms(vector<vector<int>> &intervals) {
        int size = intervals.size();
        if (size == 0) return 0;
        sort(intervals.begin(), intervals.end());

        priority_queue<vector<int>, vector<vector<int>>, Order> pq;
        pq.emplace(intervals[0]);

        for (int i = 1; i < size; i++) {
            vector<int> topInterval = pq.top();
            vector<int> cur = intervals[i];
            if (cur[0] < topInterval[1]) {
                pq.emplace(cur);
            } else {
                pq.pop();
                pq.emplace(cur);
            }
        }

        return pq.size();
    }
};

int main() {

//    struct Order {
//        bool operator()(vector<int> &a, vector<int> &b) const {
//            return a[1] > b[1] || (a[1] == b[1] && a[0] > b[0]);
//        }
//    };

//    priority_queue<vector<int>, vector<vector<int>>, Order> pq;
//    vector<int> i1 = {0, 30};
//    vector<int> i2 = {5, 10};
//    vector<int> i3 = {15, 20};
//    pq.emplace(i1), pq.emplace(i2), pq.emplace(i3);
//    while (!pq.empty()) {
//        vector<int> cur = pq.top();
//        pq.pop();
//        cout << cur[0] << " " << cur[1] << endl;
//    }

    vector<vector<int>> intervals = {{0,  30},
                                     {5,  10},
                                     {15, 20}};
    cout << Solution().minMeetingRooms(intervals) << endl;
}