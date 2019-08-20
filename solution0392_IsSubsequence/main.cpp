//
// Created by 王存俊 on 2019-08-20.
//

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() > t.size()) return false;
        int k = 0;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == s[k]) {
                k++;
            }
        }
        return k == s.size();
    }
};