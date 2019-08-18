//
// Created by 王存俊 on 2019-08-18.
//

class Solution {
public:
    int hIndex(vector<int> &citations) {
        sort(citations.begin(), citations.end());
        int size = citations.size();
        for (int i = 0; i < size; i++) {
            int remain = size - i;
            if (citations[i] >= remain) {
                return remain;
            }
        }
        return 0;
    }
};