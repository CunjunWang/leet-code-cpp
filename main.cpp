#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int> &stones) {
        int size = stones.size();
        if (size == 0) return 0;
        if (size == 1) return stones[0];

        vector<int> newStones;
        // max = 8, secondMax = 7, maxI = 4, secondMaxI = 1;
        int max = 0, secondMax = 0, maxI = 0, secondMaxI = 0;
        for (int i = 0; i < size; i++) {
            if (stones[i] >= max) {
                secondMax = max;
                secondMaxI = maxI;
                max = stones[i];
                maxI = i;
            } else if (stones[i] >= secondMax) {
                secondMax = stones[i];
                secondMaxI = i;
            }
        }
        for (int i = 0; i < size; i++) {
            if (i == secondMaxI) {
                continue;
            } else if (i == maxI) {
                newStones.push_back(max - secondMax);
            } else {
                newStones.push_back(stones[i]);
            }
        }
        return lastStoneWeight(newStones);
    }
};

int main() {
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    int result = Solution().lastStoneWeight(stones);
    cout << result << endl;
}