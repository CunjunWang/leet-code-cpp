//
// Created by 王存俊 on 2019-08-20.
//

class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        for (long long i = 5; n / i > 0; i *= 5) {
            result += (n / i);
        }
        return result;
    }
};