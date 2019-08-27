//
// Created by 王存俊 on 2019-08-27.
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
#include "TreeNode.h"
#include "ListNode.h"

using namespace std;

class Solution {
public:
    int findLHS(vector<int> &nums) {
        map<int, int> freqs;
        for (int n : nums) {
            freqs[n]++;
        }

        int longest = 0;
        int lastNum = 0;
        int lastFreq = 0;
        for (pair<int, int> p : freqs) {
            int freq2 = 0;
            if (lastFreq && p.first == lastNum + 1) {
                freq2 = p.second + lastFreq;
            }
            longest = max(longest, freq2);
            lastNum = p.first;
            lastFreq = p.second;
        }
        return longest;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 1, 2, 4};
    cout << Solution().findLHS(nums) << endl;
}