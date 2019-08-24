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
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        if (S.size() <= 1) return res;
        int start = 0, end = 0;
        for (int i = 1; i < S.size(); i++) {
            if (S[i] == S[i - 1]) {
                end = i;
                if (end == S.size() - 1) {
                    int length = end - start + 1;
                    if (length >= 3) {
                        vector<int> range = {start, start + length - 1};
                        res.push_back(range);
                    }
                }
            } else {
                int length = end - start + 1;
                if (length >= 3) {
                    vector<int> range = {start, start + length - 1};
                    res.push_back(range);
                }
                start = i;
            }
        }
        return res;
    }
};

int main() {
    string S = "aaaaa";
    auto result = Solution().largeGroupPositions(S);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}