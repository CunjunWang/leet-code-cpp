//
// Created by 王存俊 on 2019-08-09.
//

class Solution {
public:
    int numEquivDominoPairs(vector <vector<int>> &dominoes) {
        int size = dominoes.size();
        if (size == 0) return 0;
        int innerSize = dominoes[0].size();
        if (innerSize == 0) return 0;

        unordered_map map =
        for (int i = 0; i < size; i++) {
            vector<int> ith = dominoes[i];
            int min = min(ith[0], ith[1]);
            int max = max(ith[0], ith[1]);
            int encode = min * 10 + max;
        }

        return count;
    }
};