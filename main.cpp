#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
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
    }
};

int main() {
    cout << Solution().tribonacci(3) << endl;
}