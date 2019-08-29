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

class MyCalendar {
private:
    vector<vector<int>> intervals;

public:
    MyCalendar() {}

    bool book(int start, int end) {
        for (int i = 0; i < intervals.size(); i++) {
            vector<int> interval = intervals[i];
            int thisStart = interval[0];
            int thisEnd = interval[1];
            if ((thisStart >= start && thisStart < end) || (thisEnd > start && thisEnd <= end) ||
                (thisStart <= start && thisEnd >= end))
                return false;
        }
        vector<int> newInterval = {start, end};
        intervals.push_back(newInterval);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

int main() {
    MyCalendar *obj = new MyCalendar();
    cout << obj->book(47, 50) << endl;
    cout << obj->book(33, 41) << endl;
    cout << obj->book(39, 45) << endl;
    cout << obj->book(33, 42) << endl;
    cout << obj->book(25, 32) << endl;
    cout << obj->book(26, 35) << endl;
    cout << obj->book(19, 25) << endl;
    cout << obj->book(3, 8) << endl;
    cout << obj->book(8, 13) << endl;
    cout << obj->book(18, 27) << endl;
}