//
// Created by 王存俊 on 2019-08-21.
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
    int fib(int N) {
        if (N == 0) return 0;
        if (N == 1) return 1;
        vector<int> memo(N + 1);
        memo[0] = 0;
        memo[1] = 1;
        for (int i = 2; i < N + 1; i++) {
            memo[i] = memo[i - 1] + memo[i - 2];
        }
        return memo[N];
    }
};

int main() {
    int n = 3;
    cout << Solution().fib(n) << endl;
}