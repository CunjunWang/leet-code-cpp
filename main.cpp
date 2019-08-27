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
#include "TreeNode.h"
#include "ListNode.h"

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount == 0 || coins.empty())
            return 0;

        vector<int> memo(amount + 1, amount + 1);
        memo[0] = 0;

        for (int j = 0; j < coins.size(); j++) {
            for (int i = coins[j]; i < amount + 1; i++) {
                memo[i] = min(memo[i], 1 + memo[i - coins[j]]);
            }
        }

        return memo[amount] == amount + 1 ? -1 : memo[amount];
    }
};

int main() {
    vector<int> coins = {2};
    int amount = 3;
    cout << Solution().coinChange(coins, amount) << endl;
}