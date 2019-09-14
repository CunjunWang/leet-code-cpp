//
// Created by 王存俊 on 2019-09-14.
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
    bool isOperand(string &token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

public:
    int evalRPN(vector<string> &tokens) {
        stack<string> todo;
        for (int i = 0; i < tokens.size(); i++) {
            string token = tokens[i];
            if (isOperand(token)) {
                int second = stoi(todo.top());
                todo.pop();
                int first = stoi(todo.top());
                todo.pop();
                int result = 0;
                if (token == "+") {
                    result = first + second;
                } else if (token == "-") {
                    result = first - second;
                } else if (token == "*") {
                    result = first * second;
                } else {
                    result = first / second;
                }
                string str = to_string(result);
                todo.push(str);
            } else {
                todo.push(token);
            }
        }
        return stoi(todo.top());
    }
};

int main() {
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    int res = Solution().evalRPN(tokens);
    cout << res << endl;

    tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    res = Solution().evalRPN(tokens);
    cout << res << endl;
}