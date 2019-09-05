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

// 1. Separate logs into digitLogs and letterLogs according to the first character
// after the first space. Note that for letter logs,
// Each identifier is moved to the end of the string in order to facilitate sorting. (to handle ties with identifiers)
// 2. Sort letterLogs
// 3. Recover letterLogs so that the identifiers are moved back the the beginning of logs.
// 4. Concatenate letterLogs with digitLogs, return letterLogs.
class Solution {
public:
    vector<string> reorderLogFiles(vector<string> &logs) {
        vector<string> digitLogs, letterLogs;
        for (string &s : logs) {
            int i = 0;
            while (s[i] != ' ') ++i;
            if (isalpha(s[i + 1])) {
                letterLogs.push_back(s.substr(i + 1) + " " + s.substr(0, i));
            } else {
                digitLogs.push_back(s);
            }
        }
        sort(letterLogs.begin(), letterLogs.end());
        for (string &s : letterLogs) {
            int i = s.size() - 1;
            while (s[i] != ' ') --i;
            s = s.substr(i + 1) + " " + s.substr(0, i);
        }
        for (string &s : digitLogs) {
            letterLogs.push_back(s);
        }
        return letterLogs;
    }
};

int main() {
}