//
// Created by 王存俊 on 2019-08-24.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include <sstream>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    int countCharacters(vector<string> &words, string chars) {
        if (words.empty() || chars.empty())
            return 0;
        unordered_map<char, int> record;
        for (int i = 0; i < chars.size(); i++) {
            record[chars[i]]++;
        }
        int size = chars.size();
        int res = 0;
        for (string word : words) {
            if (word.size() <= size) {
                unordered_map<char, int> record2;
                for (char &c : word) {
                    record2[c]++;
                }
                auto iter = record2.begin();
                for (; iter != record2.end(); iter++) {
                    if (iter->second > record[iter->first]) {
                        break;
                    }
                }
                if (iter == record2.end()) {
                    res += word.size();
                }
            }
        }

        return res;
    }
};

int main() {
    vector<string> words = {"cat", "bt", "hat", "tree"};
    string chars = "atach";
    cout << Solution().countCharacters(words, chars) << endl;
}