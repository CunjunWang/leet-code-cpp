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
    string decodeString(string s) {
        int size = s.size();
        string res = "";
        string suffix = "";
        string prefix = "";
        string build = "";
        string unit = "";
        string curNum = "";
        stack<char> todo;

        int start = size - 1;
        for (; start >= 0; start--) {
            if (s[start] != ']') {
                suffix = s[start] + suffix;
                if (start == 0) {
                    return suffix;
                }
            } else {
                break;
            }
        }
        int end = 0;
        for (; end < size; end++) {
            char c = s[end];
            if (!isdigit(c) && c != '[') {
                prefix += c;
//                if (end == size - 1) {
//                    return prefix;
//                }
            } else {
                break;
            }
        }
        for (int i = start; i >= end; i--) {
            char c = s[i];
            if (c == ']') {
                todo.push(c);
            } else if (isalpha(c)) {
                if (todo.empty()) {
                    res = c + res;
                } else {
                    todo.push(c);
                }
            } else if (c == '[') {
                while (todo.top() != ']') {
                    build += todo.top();
                    todo.pop();
                }
                todo.pop();
            } else if (isdigit(c)) {
                curNum = s[i] + curNum;
                if (i == end || !isdigit(s[i - 1])) {
                    int times = stoi(curNum);
                    curNum = "";
                    while (times > 0) {
                        unit += build;
                        times--;
                    }
                    if (!todo.empty()) {
                        int unitSize = unit.size();
                        for (int j = unitSize - 1; j >= 0; j--) {
                            todo.push(unit[j]);
                        }
                    } else {
                        res = unit + res;
                    }
                    build = "";
                    unit = "";
                }
            }
        }
        return prefix + res + suffix;
    }
};

int main() {
    string s = "2[abc]xyc3[z]";
    cout << Solution().decodeString(s) << endl;
}