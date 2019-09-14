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
    static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }

public:
    int longestStrChain(vector<string> &words) {
        int size = words.size();
        sort(words.begin(), words.end(), compare);

        unordered_map<string, int> dp;
        int res = 0;

        for (string &word : words) {
            int maximum = 0;
            for (int i = 0; i < word.size(); i++) {
                string sub = word.substr(0, i) + word.substr(i + 1);
                maximum = max(maximum, dp[sub] + 1);
            }
            dp[word] = maximum;
            res = max(res, maximum);
        }

        return res;
    }
};

int main() {
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    int res = Solution().longestStrChain(words);
    cout << res << endl;
}