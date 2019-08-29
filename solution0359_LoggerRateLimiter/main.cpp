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

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
class Logger {
private:
    unordered_map<string, list<int>> record;

public:
    /** Initialize your data structure here. */
    Logger() {}

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (record[message].empty()) {
            record[message].push_front(timestamp);
            return true;
        } else {
            int lastTime = record[message].front();
            if (timestamp - lastTime >= 10) {
                record[message].push_front(timestamp);
                record[message].pop_back();
                return true;
            } else {
                return false;
            }
        }
    }
};

int main() {
    Logger *logger = new Logger();

    // logging string "foo" at timestamp 1
    cout << logger->shouldPrintMessage(0, "A") << endl;

    // logging string "bar" at timestamp 2
    cout << logger->shouldPrintMessage(0, "B") << endl;

    // logging string "foo" at timestamp 3
    cout << logger->shouldPrintMessage(0, "C") << endl;

    // logging string "bar" at timestamp 8
    cout << logger->shouldPrintMessage(0, "A") << endl;

    // logging string "foo" at timestamp 10
    cout << logger->shouldPrintMessage(0, "B") << endl;

    // logging string "foo" at timestamp 11
    cout << logger->shouldPrintMessage(0, "C") << endl;

    // logging string "bar" at timestamp 8
    cout << logger->shouldPrintMessage(0, "A") << endl;

}