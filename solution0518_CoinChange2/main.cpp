//
// Created by 王存俊 on 2019-09-18.
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
#include "Helpers.h"

using namespace std;

class Solution {
public:
    int change(int amount, vector<int> &coins) {
        int size = coins.size();
        if (amount == 0)
            return 1;
        if (size == 0)
            return 0;

        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int i = coin; i < amount + 1; ++i) {
                dp[i] += dp[i - coin];
            }
        }

        return dp[amount];
    }
};

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 4;
    cout << Solution().change(amount, coins) << endl;
}