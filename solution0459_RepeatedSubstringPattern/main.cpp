//
// Created by 王存俊 on 2019-08-21.
//

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int size = s.size();
        if (size == 0) return false;
        if (size == 1) return false;
        for (int i = 1; i <= size / 2; i++) {
            string sub = s.substr(0, i);
            int k = 0;
            while (k < size) {
                string thisSub = s.substr(k, i);
                if (thisSub == sub) {
                    k += i;
                } else {
                    break;
                }
            }
            if (k == size) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    string s = "abcabcabcabca";
    cout << Solution().repeatedSubstringPattern(s) << endl;
}

