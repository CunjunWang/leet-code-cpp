//
// Created by 王存俊 on 2019-08-28.
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
    vector<vector<string>> groupStrings(vector<string> &strings) {
        unordered_map<string, vector<string>> record;

        for (int i = 0; i < strings.size(); i++) {
            string thisFromList = strings[i];
            string copy = string(thisFromList);
            char first = copy[0];
            for (int j = 0; j < copy.size(); j++) {
                int diff = copy[j] - first;
                copy[j] = diff >= 0 ? diff : diff + 26;
            }
            record[copy].push_back(thisFromList);
        }

        vector<vector<string>> res;

        for (auto &it : record) {
            res.push_back(it.second);
        }

        return res;
    }
};

int main() {
    vector<string> strs = {"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
    vector<vector<string>> res = Solution().groupStrings(strs);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}