//
// Created by 王存俊 on 2019-08-24.
//

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1)
            return 0;
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            res += max(0, prices[i] - prices[i - 1]);
        }
        return res;
    }
};