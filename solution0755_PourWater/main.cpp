//
// Created by 王存俊 on 2019-09-15.
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
#include <unordered_set>
#include "DoublyLinkedListNode.h"
#include "TreeNode.h"
#include "Helpers.h"

using namespace std;

// TODO:
class Solution {
public:
    vector<int> pourWater(vector<int> &heights, int V, int K) {
        if (V == 0)
            return heights;
        int size = heights.size();

        while (V > 0) {
            bool find = false;
            int heightK = heights[K];
            // left
            for (int i = K - 1; i >= 0; i--) {
                int heightI = heights[i];
                if (heightI > heightK)
                    break;

                if (heightI < heightK) {
                    if (i - 1 >= 0 && heights[i - 1] < heightI) {
                        continue;
                    }
                    heights[i]++;
                    V--;
                    find = true;
                    break;
                }
            }
            if (find)
                continue;

            // right
            for (int i = K + 1; i < size; i++) {
                int heightI = heights[i];
                if (heightI > heightK)
                    break;

                if (heightI < heightK) {
                    if (i + 1 < size && heights[i + 1] < heightI) {
                        continue;
                    }
                    heights[i]++;
                    V--;
                    find = true;
                    break;
                }
            }
            if (find)
                continue;

            V--;
            heights[K]++;
        }

        return heights;
    }
};

int main() {
//    vector<int> heights = {2, 1, 1, 2, 1, 2, 2};
//    int V = 4, K = 3;
//    heights = Solution().pourWater(heights, V, K);
//    printVector(heights);

//    vector<int> heights = {1, 2, 3, 4};
//    int V = 2, K = 2;
//    heights = Solution().pourWater(heights, V, K);
//    printVector(heights);

    vector<int> heights = {1, 2, 3, 4, 3, 2, 1, 2, 3, 4, 3, 2, 1};
    int V = 10, K = 2;
    heights = Solution().pourWater(heights, V, K);
    printVector(heights);
}