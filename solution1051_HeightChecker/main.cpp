//
// Created by 王存俊 on 2019-08-10.
//

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int size = heights.size();
        if (size <= 1) return 0;
        vector<int> copy(size);
        for (int i = 0; i < size; i++) {
            copy[i] = heights[i];
        }
        sort(heights.begin(), heights.end());
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (heights[i] != copy[i]) {
                count++;
            }
        }
        return count;
    }
};
