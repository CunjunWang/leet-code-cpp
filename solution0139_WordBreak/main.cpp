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
    unordered_map<string, bool> memo;

    bool doBreak(const string &s, unordered_set<string> &dict) {
        // in the memo, return
        if (memo.count(s)) {
            return memo[s];
        }
        // s is already a word, memoize and return
        if (dict.count(s)) {
            memo[s] = true;
            return memo[s];
        }

        int size = s.size();
        for (int j = 1; j < size; j++) {
            const string left = s.substr(0, j);
            const string right = s.substr(j);
            bool result1 = false;
            if (dict.count(right) && doBreak(left, dict)) {
                memo[s] = true;
                return memo[s];
            }
        }

        memo[s] = false;
        return memo[s];
    }

public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return doBreak(s, dict);
    }
};

int main() {
    string s = "goalspecial";
    vector<string> wordDict = {"go", "goal", "goals", "special"};
    cout << Solution().wordBreak(s, wordDict) << endl;
}