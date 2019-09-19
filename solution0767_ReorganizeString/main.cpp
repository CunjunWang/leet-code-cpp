//
// Created by 王存俊 on 2019-09-18.
//

// TODO:
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
#include "Helpers.h"

using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        int size = S.size();
        if (size == 0)
            return S;
        unordered_map<char, int> count;
        for (int i = 0; i < size; i++) {
            char c = S[i];
            count[c]++;
        }
        int maxVal = 0;
        int sum = 0;
        char maxKey = '0';
        for (auto it : count) {
            sum += it.second;
            if (it.second >= maxVal) {
                maxVal = it.second;
                maxKey = it.first;
            }
        }
        sum -= maxVal;
        if (sum <= maxVal - 2)
            return "";

        vector<char> charVector;
        for (auto it : count) {
            if (it.first != maxKey) {
                charVector.emplace_back(it.first);
            }
        }
        size = charVector.size();

        string res;

        if (sum > maxVal) {
            res += charVector[0];
            count[charVector[0]]--;
            int counter = 1;
            while (res.size() < S.size()) {
                res += maxKey;
                res += ;
            }
        } else {
            res += maxKey;
            count[maxKey]--;
        }

        for (int i = 1; i < S.size(); i++) {
            res = res + maxKey;
            res = res + charVector[i % size];
        }
        return res;
    };
};

int main() {
    string S = "aaabbcc";
    cout << Solution().reorganizeString(S) << endl;
}