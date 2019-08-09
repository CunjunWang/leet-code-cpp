//
// Created by 王存俊 on 2019-08-09.
//

#include <vector>

class Solution {
public:
    if (n == 0 || n == 1) {
        return n;
    }
    if (n == 2) {
        return 1;
    }
    vector<int> memo(n + 1);
    memo[0] = 0;
    memo[1] = memo[2] = 1;
    for (int i = 3; i <= n; i++) {
        memo[i] = memo[i - 3] + memo[i - 2] + memo[i - 1];
    }
    return memo[n];
};
