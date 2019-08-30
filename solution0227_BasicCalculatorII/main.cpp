//
// Created by 王存俊 on 2019-08-30.
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

// TODO: 优化
class Solution {
public:
    int calculate(string s) {
        int size = s.size();
        stack<string> todo;
        queue<string> origins;

        string cur = "";
        bool allDigits = true;
        for (int i = 0; i < size; i++) {
            if (s[i] != ' ') {
                if (!isdigit(s[i])) {
                    allDigits = false;
                    origins.push(cur);
                    cur = "";
                    origins.push(string(1, s[i]));
                } else {
                    cur += s[i];
                }
            }
        }
        origins.push(cur);

        if (allDigits) {
            return stoi(origins.front());
        }

        while (!origins.empty()) {
            string frontString = origins.front();
            origins.pop();
            if (frontString == "+" || frontString == "-") {
                todo.push(frontString);
            } else if (frontString == "*") {
                long long prev = stoi(todo.top());
                todo.pop();
                long long next = stoi(origins.front());
                origins.pop();
                long long result = prev * next;
                todo.push(to_string(result));
            } else if (frontString == "/") {
                long long prev = stoi(todo.top());
                todo.pop();
                long long next = stoi(origins.front());
                origins.pop();
                long long result = prev / next;
                todo.push(to_string(result));
            } else {
                todo.push(frontString);
            }
        }

        stack<string> newTodo;
        while (!todo.empty()) {
            newTodo.push(todo.top());
            todo.pop();
        }

        long long result = 0;
        while (newTodo.size() > 1) {
            string thisNum = newTodo.top();
            newTodo.pop();
            string thisOperator = newTodo.top();
            newTodo.pop();
            string nextNum = newTodo.top();
            newTodo.pop();
            long long thisResult = 0;
            if (thisOperator == "+") {
                thisResult = stoi(thisNum) + stoi(nextNum);
            } else {
                thisResult = stoi(thisNum) - stoi(nextNum);
            }
            newTodo.push(to_string(thisResult));
        }

        result = stoi(newTodo.top());

        return result;
    }
};

int main() {
    cout << Solution().calculate("1-1+1") << endl;
}