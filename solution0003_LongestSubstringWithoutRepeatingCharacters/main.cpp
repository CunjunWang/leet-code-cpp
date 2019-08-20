//
// Created by 王存俊 on 2019-08-20.
//

// TODO:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        vector<char> chars;
        int res = 0;
        for (int j = 0; j < s.size(); j++) {
            if (find(chars.begin(), chars.end(), s[j]) == chars.end()) {
                chars.push_back(s[j]);
            } else {
                int size = chars.size();
                res = max(res, size);
                chars.clear();
                chars.push_back(s[j]);
            }
        }
        int size = chars.size();
        return max(res, size);
    }
};

int main() {
    string s = "dvdf";
    cout << Solution().lengthOfLongestSubstring(s) << endl;
}