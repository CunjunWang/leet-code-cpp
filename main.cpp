#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

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

int main() {
    vector<vector<int>> dominoes = {
            {1, 2},
            {2, 1},
            {3, 4},
            {5, 6}
    };
    cout << Solution().numEquivDominoPairs(dominoes) << endl;
}