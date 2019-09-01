//
// Created by 王存俊 on 2019-09-01.
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
    set<string> record;
    int minimumRemoved;

    void generateResult(const string &str, int curIndex, int leftCount, int rightCount,
                        string curExp, int removedCount) {
        // If we have reached the end of string
        if (curIndex == str.size()) {
            // If the current expression is valid.
            if (leftCount == rightCount) {
                // If the current count of removed parentheses is <= the current minimum count
                if (removedCount <= minimumRemoved) {
                    // If the current count beats the overall minimum we have till now
                    if (removedCount < minimumRemoved) {
                        record.clear();
                        minimumRemoved = removedCount;
                    }
                    record.insert(curExp);
                }
            }
        } else {

            char currentCharacter = str[curIndex];

            // If the current character is neither an opening bracket nor a closing one,
            // simply recurse further by adding it to the expression StringBuilder
            if (currentCharacter != '(' && currentCharacter != ')') {
                curExp += currentCharacter;
                generateResult(str, curIndex + 1, leftCount, rightCount, curExp, removedCount);
                int size = curExp.size();
                curExp = curExp.substr(0, size - 1);
            } else {
                if (removedCount < minimumRemoved) {
                    // Recursion where we delete the current character and move forward
                    generateResult(str, curIndex + 1, leftCount, rightCount, curExp, removedCount + 1);
                }

                curExp += currentCharacter;
                // If it's an opening parenthesis, consider it and recurse
                if (currentCharacter == '(') {
                    generateResult(str, curIndex + 1, leftCount + 1, rightCount, curExp, removedCount);
                } else if (rightCount < leftCount) {
                    // For a closing parenthesis, only recurse if right < left
                    generateResult(str, curIndex + 1, leftCount, rightCount + 1, curExp, removedCount);
                }

                // backtracking
                // Undoing the append operation for other recursions.
                int size = curExp.size();
                curExp = curExp.substr(0, size - 1);
            }
        }

    }

public:
    vector<string> removeInvalidParentheses(string s) {
        record.clear();
        minimumRemoved = INT_MAX;
        // string, curIndex, leftCount, rightCount, curExp, removedCount
        generateResult(s, 0, 0, 0, "", 0);
        vector<string> res(record.begin(), record.end());
        return res;
    }
};

int main() {
    string s = "()())()";
    vector<string> res = Solution().removeInvalidParentheses(s);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}