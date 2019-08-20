//
// Created by 王存俊 on 2019-08-20.
//

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> count;
        for (int i = 0; i < magazine.size(); i++) {
            char c =  magazine[i];
            if (count[c] == 0) {
                count[c] = 1;
            } else {
                count[c]++;
            }
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            char c = ransomNote[i];
            if (count[c] == 0) return false;
            count[c]--;
        }
        return true;
    }
};