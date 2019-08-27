//
// Created by 王存俊 on 2019-08-26.
//

class Solution {
public:
    int peakIndexInMountainArray(vector<int> &A) {
        int peak = *max_element(A.begin(), A.end());
        int index = find(A.begin(), A.end(), peak) - A.begin();
        return index;
    }
};