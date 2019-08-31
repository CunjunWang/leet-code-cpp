//
// Created by 王存俊 on 2019-08-31.
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
public:
    string customSortString(string S, string T) {
        vector<int> count(26, 0);

        for (int i = 0; i < T.size(); i++) {
            char c = T[i];
            count[c - 'a']++;
        }

        string res = "";
        for (int i = 0; i < S.size(); i++) {
            char c = S[i];
            while (count[c - 'a'] > 0) {
                res += c;
                count[c - 'a']--;
            }
        }

        for (int i = 0; i < 26; i++) {
            while (count[i] > 0) {
                res += string(1, i + 'a');
                count[i]--;
            }
        }

        return res;
    }
};

int main() {
    string S = "cba", T = "abcd";
    cout << Solution().customSortString(S, T) << endl;
}