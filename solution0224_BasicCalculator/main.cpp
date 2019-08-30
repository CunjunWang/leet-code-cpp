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
#include <unordered_set>
#include "TreeNode.h"
#include "ListNode.h"

using namespace std;

class Solution {
private:
    // trim from start (in place)
    static inline void ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
            return !std::isspace(ch);
        }));
    }

    // trim from end (in place)
    static inline void rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
            return !std::isspace(ch);
        }).base(), s.end());
    }

    // trim from both ends (in place)
    static inline void trim(std::string &s) {
        ltrim(s);
        rtrim(s);
    }

public:
    int calculate(string s) {
        list<string> todo;
        string cur = "";

        trim(s);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (isdigit(s[i])) {
                    cur += s[i];
                    if (i == s.size() - 1) {
                        todo.emplace_back(cur);
                    }
                } else {
                    if (cur.size() != 0) {
                        todo.emplace_back(cur);
                        cur = "";
                    }
                    if (s[i] == '(' || s[i] == '+' || s[i] == '-') {
                        todo.emplace_back(string(1, s[i]));
                    } else if (s[i] == ')') {
                        while (todo.back() != "(") {
                            string prev = todo.back();
                            todo.pop_back();
                            long long prevNum = stoi(prev);
                            string op = todo.back();
                            if (op == "(") {
                                todo.pop_back();
                                todo.emplace_back(to_string(prevNum));
                                break;
                            }
                            todo.pop_back();
                            string prevPrev = todo.back();
                            todo.pop_back();
                            long long prevPrevNum = stoi(prevPrev);
                            string prePrePreOp = todo.back();
                            if (prePrePreOp == "-") {
                                todo.pop_back();
                                if (todo.back() != "" && todo.back() != "(") {
                                    todo.emplace_back("+");
                                }
                                prevPrevNum = -prevPrevNum;
                            }
                            long long result;
                            if (op == "+") {
                                result = prevNum + prevPrevNum;
                            } else {
                                result = prevPrevNum - prevNum;
                            }
                            if (todo.back() == "(") {
                                todo.pop_back();
                                todo.emplace_back(to_string(result));
                                break;
                            }
                            todo.emplace_back(to_string(result));
                        }
                    }
                }
            }
        }

        if (todo.size() == 1) {
            return stoi(todo.back());
        }

        while (!todo.empty()) {
            long long thisNum = stoi(todo.front());
            todo.pop_front();
            string op = todo.front();
            todo.pop_front();
            long long nextNum = stoi(todo.front());
            todo.pop_front();
            long long result;
            if (op == "+") {
                result = thisNum + nextNum;
            } else {
                result = thisNum - nextNum;
            }
            if (todo.empty()) {
                return result;
            } else {
                todo.emplace_front(to_string(result));
            }
        }

        return 0;
    }
};

int main() {
    string s = " 2-1 + 2 ";
    // "(1+(4+5+2)-3)+(6+8)";
    cout << Solution().calculate(s) << endl;
}