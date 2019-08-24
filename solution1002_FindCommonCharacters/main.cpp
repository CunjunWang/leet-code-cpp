//
// Created by 王存俊 on 2019-08-24.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include <sstream>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string> &A) {
        vector<string> res;
        if (A.empty())
            return res;
        vector<int> count(26, INT_MAX);
        for (string s : A) {
            vector<int> count1(26, 0);
            for (auto c : s) {
                count1[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                count[i] = min(count[i], count1[i]);
            }
        }
        for (int i = 0; i < 26; i++) {
            int num = count[i];
            while(num > 0) {
                res.push_back(string(1, i + 'a'));
                num--;
            }
        }
        return res;
    }
};

int main() {

}