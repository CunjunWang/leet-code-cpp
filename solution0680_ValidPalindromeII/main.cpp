//
// Created by 王存俊 on 2019-08-28.
//

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

// MLE
//class Solution {
//public:
//    bool validPalindrome(string s) {
//        int size = s.size();
//        if (size <= 1)
//            return true;
//
//        if (isPalindrome(s))
//            return true;
//
//        for (int i = 0; i < s.size(); i++) {
//            string newString;
//            if (i == 0)
//                newString = s.substr(1, size - 1);
//            else if (i == size - 1)
//                newString = s.substr(0, size - 1);
//            else {
//                string pre = s.substr(0, i);
//                string post = s.substr(i + 1, size - i - 1);
//                newString = pre + post;
//            }
//            if (isPalindrome(newString))
//                return true;
//        }
//
//        return false;
//    }
//
//    bool isPalindrome(string &s) {
//        int size = s.size();
//        if (size <= 1)
//            return true;
//
//        int l = 0, r = size - 1;
//        while (l < r) {
//            if (s[l++] != s[r--])
//                return false;
//        }
//
//        return true;
//    }
//};