//
// Created by 王存俊 on 2019-08-21.
//

class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1;
        int count = 0;
        while (n >= i) {
            n = n - i;
            i++;
            count++;
        }
        return count;
    }
};