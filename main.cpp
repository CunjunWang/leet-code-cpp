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

int main() {

}