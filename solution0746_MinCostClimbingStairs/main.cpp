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
    int minCostClimbingStairs(vector<int> &cost) {
        int size = cost.size();
        // memo[i] means the minimum cost to reach stair i;
        vector<int> memo(size);
        memo[0] = cost[0];
        memo[1] = cost[1];
        for (int i = 2; i < size; i++) {
            memo[i] = cost[i] + min(memo[i - 1], memo[i - 2]);
        }
        return min(memo[size - 1], memo[size - 2]);
    }
};

int main() {

}