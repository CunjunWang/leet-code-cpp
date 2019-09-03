//
// Created by 王存俊 on 2019-09-02.
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
#include "Helpers.h"

using namespace std;



// brute force solution, TLE
//class Solution {
//private:
//    bool isPalindrome(string &s) {
//        if (s.size() <= 1)
//            return true;
//        int l = 0, r = s.size() - 1;
//        while (l <= r) {
//            if (s[l] != s[r]) {
//                return false;
//            }
//            l++, r--;
//        }
//        return true;
//    }
//
//public:
//    vector<vector<int>> palindromePairs(vector<string> &words) {
//        vector<vector<int>> res;
//        for (int i = 0; i < words.size(); i++) {
//            for (int j = i + 1; j < words.size(); j++) {
//                vector<int> pairs;
//                string s1 = words[i] + words[j];
//                string s2 = words[j] + words[i];
//                if (isPalindrome(s1)) {
//                    pairs = {i, j};
//                    res.emplace_back(pairs);
//                }
//                if (isPalindrome(s2)) {
//                    pairs = {j, i};
//                    res.emplace_back(pairs);
//                }
//            }
//        }
//        return res;
//    }
//};

int main() {
    vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};
    vector<vector<int>> res = Solution().palindromePairs(words);
    printMatrix(res);
}