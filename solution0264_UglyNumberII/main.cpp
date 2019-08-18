//
// Created by 王存俊 on 2019-08-18.
//

class Solution {
private:
    int minOfThree(int a, int b, int c) {
        int temp = min(a, b);
        return min(temp, c);
    }

public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        vector<int> memo(n);
        memo[0] = 1;

        int n2 = 0, n3 = 0, n5 = 0;

        for (int i = 1; i < n; i++) {
            memo[i] = minOfThree(memo[n2] * 2, memo[n3] * 3, memo[n5] * 5);
            if (memo[i] == memo[n2] * 2) n2++;
            if (memo[i] == memo[n3] * 3) n3++;
            if (memo[i] == memo[n5] * 5) n5++;
        }

        return memo[n - 1];
    }
};