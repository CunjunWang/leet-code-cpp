//
// Created by 王存俊 on 2019-08-29.
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
    vector<int> shortestToChar(string S, char C) {
        vector<int> targets;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == C)
                targets.push_back(i);
        }
        int cur = 0;
        vector<int> res;
        if (targets.empty())
            return res;
        for (int i = 0; i < S.size(); i++) {
            if (cur + 1 < targets.size()) {
                if (abs(i - targets[cur + 1]) <= abs(i - targets[cur])) {
                    res.push_back(abs(i - targets[++cur]));
                } else {
                    res.push_back(abs(i - targets[cur]));
                }
            } else {
                res.push_back(abs(i - targets[cur]));
            }
        }
        return res;
    }
};

int main() {
    string S = "loveleetcode";
    char C = 'e';
    vector<int> res = Solution().shortestToChar(S, C);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}