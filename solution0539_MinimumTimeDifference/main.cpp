//
// Created by 王存俊 on 2019-09-13.
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

private:
    int timeDiff(string &time1, string &time2) {
        int m1 = stoi(time1.substr(3));
        int h1 = stoi(time1.substr(0, 2));
        int m2 = stoi(time2.substr(3));
        int h2 = stoi(time2.substr(0, 2));
        int diff = h1 * 60 + m1 - (h2 * 60 + m2);
        diff = min(diff, 1440 - diff);
        return diff;
    }

public:
    int findMinDifference(vector<string> &timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int size = timePoints.size();
        int minDiff = 1440;
        for (int i = 1; i < size; i++) {
            int diff = abs(timeDiff(timePoints[i-1], timePoints[i]));
            diff = min(diff, 1440 - diff);
            minDiff = min(minDiff, diff);
        }
        int diff = abs(timeDiff(timePoints[0], timePoints[size - 1]));
        diff = min(diff, 1440 - diff);
        minDiff = min(minDiff, diff);
        return minDiff;
    }
};

int main() {
    vector<string> timePoints = {"05:31", "22:08", "00:35"};
    int res = Solution().findMinDifference(timePoints);
    cout << res << endl;
}