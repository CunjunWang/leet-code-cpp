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
    string longestPalindrome(string s) {
        // dp[i][j]: s(i...j) is palindrome
        int size = s.size();
        if (size <= 1)
            return s;

        vector<vector<bool>> dp(size, vector<bool>(size, false));
        int maxLen = 1, start = -1, end = -1;
        string palindrome;

        // if length == 1
        for (int i = 0; i < size; i++) {
            dp[i][i] = true;
            palindrome = s.substr(i, 1);
        }

        // if length == 2
        for (int i = 0; i < size - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                palindrome = s.substr(i, 2);
            }
        }

        if (size == 2)
            return palindrome;

        // if length > 2
        int j = 0;
        for (int k = 2; k < size; k++) {
            for (int i = 0; i < size; i++) {
                j = k + i;
                if (j < size && s[i] == s[j] && dp[i + 1][j - 1]) {
                    int len = j - i + 1;
                    if (len >= maxLen) {
                        maxLen = len;
                        palindrome = s.substr(i, len);
                    }
                    dp[i][j] = true;
                }
            }
        }
        return palindrome;
    }
};

int main() {
    string s = "ababababa";
    cout << Solution().longestPalindrome(s) << endl;
}