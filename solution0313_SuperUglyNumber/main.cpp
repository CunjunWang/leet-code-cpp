//
// Created by 王存俊 on 2019-08-18.
//

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        if (n <= 0) return 0;
        if (n == 1) return 1;

        int primeSize = primes.size();
        vector<int> memo(n, 1);
        vector<int> primeIndex(primeSize, 0);

        for (int i = 1; i < n; i++) {
            memo[i] = INT_MAX;
            for (int j = 0; j < primeSize; j++) {
                if (primes[j] * memo[primeIndex[j]] == memo[i - 1]) {
                    primeIndex[j]++;
                }
                memo[i] = min(memo[i], primes[j] * memo[primeIndex[j]]);
            }
        }

        return memo[n - 1];
    }
};