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

int main() {

}