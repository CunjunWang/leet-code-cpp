//
// Created by 王存俊 on 2019-08-31.
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
#include "TreeNode.h"
#include "ListNode.h"

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>> &costs) {
        int size = costs.size();
        if (size == 0)
            return 0;

        for (int i = 1; i < size; i++) {
            costs[i][0] += min(costs[i - 1][1], costs[i - 1][2]);
            costs[i][1] += min(costs[i - 1][0], costs[i - 1][2]);
            costs[i][2] += min(costs[i - 1][0], costs[i - 1][1]);
        }

        return *min_element(costs[size - 1].begin(), costs[size - 1].end());
    }
};

int main() {
    vector<vector<int>> costs = {{17, 2,  17},
                                 {16, 16, 5},
                                 {14, 3,  19}};
    cout << Solution().minCost(costs) << endl;
}