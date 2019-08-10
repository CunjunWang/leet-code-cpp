//
// Created by 王存俊 on 2019-08-09.
//

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes) {
        int size = dominoes.size();
        if (size == 0) return 0;
        int innerSize = dominoes[0].size();
        if (innerSize == 0) return 0;

        int count = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < size; i++) {
            vector<int> ith = dominoes[i];
            int encode = min(ith[0], ith[1]) * 10 + max(ith[0], ith[1]);
            int value = map[encode];
            count += value;
            if (value != 0) {
                map[encode] = value + 1;
            } else {
                map[encode] = 1;
            }
        }
        return count;
    }
};