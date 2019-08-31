#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <sstream>
#include <cassert>
#include <list>
#include <set>
#include <unordered_set>
#include "TreeNode.h"
#include "ListNode.h"

using namespace std;

class Solution {
private:
    bool isPalindrome(const string &s, int l, int r) {
        while (l <= r) {
            if (s[l] != s[r])
                return false;
            l++, r--;
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        int size = s.size();
        if (size <= 1)
            return true;
        int l = 0, r = size - 1;
        while (l <= r) {
            if (s[l] != s[r]) {
                return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
            }
            l++, r--;
        }
        return true;
    }
};

int main() {
    string s = "abcdecba";
    cout << Solution().validPalindrome(s) << endl;
}