//
// Created by 王存俊 on 2019-09-05.
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

class TimeMap {
private:
    unordered_map<string, map<int, string>> record;

public:
    /** Initialize your data structure here. */
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        record[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        auto it = record[key].upper_bound(timestamp);
        return it == record[key].begin() ? "" : prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main() {
    TimeMap *obj = new TimeMap();
    obj->set("foo", "bar", 1);
    cout << obj->get("foo", 1) << endl;  // output "bar"
    cout << obj->get("foo", 3) << endl; // output "bar" since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 ie "bar"
    obj->set("foo", "bar2", 4);
    cout << obj->get("foo", 4) << endl; // output "bar2"
    cout << obj->get("foo", 5) << endl; //output "bar2"
    cout << obj->get("foo", 3);
}