//
// Created by 王存俊 on 2019-08-24.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include <sstream>
#include <set>
#include "TreeNode.h"

using namespace std;

class Solution {
private:
    set<string> res;

    void generateResult(string &s, int index) {

        if (index == s.size()) {
            res.insert(s);
            return;
        }

        cout << "index = " << index << ", string is " << s << ", this char is " << s[index] << endl;

        char c = s[index];
        c = islower(c) ? toupper(c) : tolower(c);
        cout << "new c is " << c << endl;
        generateResult(s, index + 1);

        // 回溯, 如果是数字的话不改变
        if (isalpha(c)) {
            s[index] = c;
            cout << "c " << c << " is number now, back track, s is " << s << endl;
            generateResult(s, index + 1);
        }
    }

public:
    vector<string> letterCasePermutation(string S) {
        generateResult(S, 0);
        vector<string> result;
        for (auto iter = res.begin(); iter != res.end(); iter++) {
            result.push_back(*iter);
        }
        return result;
    }
};

int main() {
    string S = "a1b2";
    vector<string> res = Solution().letterCasePermutation(S);
    for (string s : res) {
        cout << s << " ";
    }
}