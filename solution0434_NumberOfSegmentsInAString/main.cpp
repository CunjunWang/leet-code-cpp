//
// Created by 王存俊 on 2019-08-21.
//

class Solution {
public:
    int countSegments(string s) {
        if (s.size() == 0) return 0;
        if (s.size() == 1) {
            return s[0] == ' ' ? 0 : 1;
        }
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ') {
                count++;
            }
        }
        return count;
    }
};
