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

class Solution {
public:
    bool isMatch(string s, string p) {
        /*
            boolean dp[i][j]; i = index in s, j = index in p, s[0...i] matches p[0...j] or not
            dp[0][0] = true

            if s[i] == p[j] || p[j] == '.', dp[i][j] = dp[i-1][j-1]
            if p[j] = '*': 分情况讨论
                if p[j-1] != s[i]
                    dp[i][j] = dp[i][j-2] // "baab" and "bc*aab", c*忽略
                if s[i] == p[j-1] || p[j-1] == '.'
                    dp[i][j] = dp[i-1][j]
        */
        int sizeS = s.size(), sizeP = p.size();
        vector<vector<bool>> dp(sizeS + 1, vector<bool>(sizeP + 1, false));
        dp[0][0] = true;
        for (int i = 1; i < sizeP + 1; i++) {
            if (p[i - 1] == '*') {
                dp[0][i] = dp[0][i - 2];
            }
        }

        for (int i = 1; i < sizeS + 1; i++) {
            for (int j = 1; j < sizeP + 1; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[sizeS][sizeP];
    }
};

int main() {
}