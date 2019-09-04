//
// Created by 王存俊 on 2019-09-04.
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

class Solution {
public:
    string minWindow(string s, string t) {
        // required char with frequencies int t
        unordered_map<char, int> requiredChars;
        // the char we seen in window with frequencies int s
        unordered_map<char, int> windowChars;
        // initialize required char map, with char and frequency
        for (int i = 0; i < t.size(); i++) {
            char c = t[i];
            requiredChars[c]++;
        }
        string minWindow = "";
        int minWindowLengthSeenSoFar = INT_MAX;
        int requiredLength = requiredChars.size();
        int currentSatisfiedLength = 0;
        // use sliding windows
        int l = 0, r = 0;
        while (r < s.size()) {
            // put the right char and frequency in windowMap
            char rightChar = s[r];
            windowChars[rightChar]++;
            // if right char is a required char
            if (requiredChars.count(rightChar)) {
                // see that if the current seen frequency equals the required frequency,
                // that is, if we seen one 'a', but required 2, it still does not count
                int requiredCurrentSeenCount = windowChars[rightChar];
                int requiredCount = requiredChars[rightChar];
                // it they meets, we can count this char satisfied;
                if (requiredCurrentSeenCount == requiredCount) {
                    currentSatisfiedLength++;
                }
            }
            // determine if this window satisfied
            // if yes, we will start move inward left pointer
            while (currentSatisfiedLength == requiredLength && l <= r) {
                int currentWindowLength = r - l + 1;
                // if current window length is smaller, update result
                if (currentWindowLength <= minWindowLengthSeenSoFar) {
                    minWindowLengthSeenSoFar = currentWindowLength;
                    string currentMinWindow = s.substr(l, currentWindowLength);
                    minWindow = currentMinWindow;
                }
                char leftChar = s[l];
                // This character will get contracted out. It won't be in the window anymore
                // once left moves forward.
                windowChars[leftChar]--;

                // if the removed char is required, and not satisfied any longer, update the numbers
                if (requiredChars.count(leftChar) && (windowChars[leftChar] < requiredChars[leftChar])) {
                    currentSatisfiedLength--;
                }
                l++;
            }
            r++;
        }
        return minWindow;
    }
};

int main() {
    string S = "aa", T = "aa";
    cout << Solution().minWindow(S, T) << endl;
}