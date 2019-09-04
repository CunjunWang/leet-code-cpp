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

// greedy algorithm
class Solution {
private:
    static bool compare(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }

public:
    int findMinArrowShots(vector<vector<int>> &points) {
        int size = points.size();
        if (size == 0) return 0;

        sort(points.begin(), points.end(), compare);
        int arrow = 1;
        int curEnd = points[0][1];

        for (int i = 1; i < size; i++) {
            vector<int> cur = points[i];
            if (cur[0] > curEnd) {
                arrow++;
                curEnd = cur[1];
            }
        }

        return arrow;
    }
};

int main() {}