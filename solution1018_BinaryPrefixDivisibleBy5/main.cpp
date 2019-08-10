//
// Created by 王存俊 on 2019-08-10.
//

// TODO: consider this more

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int> &A) {
        vector<bool> result(A.size());
        int number = 0;
        for (int i = 0; i < A.size(); i++) {
            number = (2 * number + A[i]) % 5;
            result[i] = number % 5 == 0;
        }
        return result;
    }
};