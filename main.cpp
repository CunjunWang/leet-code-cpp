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
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> map;
        unordered_map<string, char> revMap;

        istringstream iss(str);
        string word;
        vector<string> split;
        while (iss >> word) {
            split.push_back(word);
        }

        if (pattern.size() != split.size()) {
            return false;
        }

        for (int i = 0; i < pattern.size(); i++) {
            char cur = pattern[i];
            if (map[cur] == "") {
                map[cur] = split[i];
            } else {
                if (map[cur] != split[i]) {
                    return false;
                }
            }
            if (revMap[split[i]] == 0) {
                revMap[split[i]] = cur;
            } else {
                if (revMap[split[i]] != cur) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    string pattern = "abba";
    string str = "dog cat cat fish";
    cout << Solution().wordPattern(pattern, str) << endl;
}