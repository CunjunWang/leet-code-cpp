//
// Created by 王存俊 on 2019-08-20.
//

class Solution {
public:
    bool isVowel(char &i) {
        return i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u' ||
               i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U';
    }

    string reverseVowels(string s) {
        if (s.size() <= 1) return s;
        vector<int> vowelIndex;
        vector<int> vowelList;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                vowelIndex.push_back(i);
                vowelList.push_back(s[i]);
            }
        }

        int size = vowelIndex.size();
        if (size == 0) {
            return s;
        }

        for (int i = 0; i < size; i++) {
            s[vowelIndex[i]] = vowelList[size - 1 - i];
        }

        return s;
    }
};

int main() {
    string s = "leetcode";
    cout << Solution().reverseVowels(s) << endl;
}