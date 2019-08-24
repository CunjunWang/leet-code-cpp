//
// Created by 王存俊 on 2019-08-24.
//

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B) {
        int sumA = 0, sumB = 0;
        for (int a : A) sumA += a;
        for (int b : B) sumB += b;
        int diff = (sumA - sumB) / 2;

        vector<int> res;
        for (int a : A) {
            for (int b : B) {
                if (a == b + diff) {
                    res.push_back(a);
                    res.push_back(b);
                    return res;
                }
            }
        }
        return res;
    }
};
