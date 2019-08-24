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
    int numPairsDivisibleBy60(vector<int> &time) {
        vector<int> mod(60, 0);
        for (int t : time) {
            mod[t % 60]++;
        }
        int res = 0;
        for (int i = 1; i < 30; i++) {
            res += mod[i] * mod[60 - i];
        }
        res += mod[0] * (mod[0] - 1) / 2;
        res += mod[30] * (mod[30] - 1) / 2;
        return res;
    }
};

int main() {
    vector<int> time = {15, 63, 451, 213, 37, 209, 343, 319};
    cout << Solution().numPairsDivisibleBy60(time) << endl;
}