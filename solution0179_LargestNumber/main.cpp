//
// Created by 王存俊 on 2019-08-26.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <sstream>
#include <cassert>
#include <set>
#include "TreeNode.h"
#include "ListNode.h"

using namespace std;

class Solution {
private:
    static int compare(const string &s1, const string &s2) {
        return s1 + s2 > s2 + s1;
    }

public:
    string largestNumber(vector<int> &nums) {
        if (nums.empty())
            return "0";
        vector<string> strings;
        for (int i : nums) {
            strings.push_back(to_string(i));
        }
        sort(strings.begin(), strings.end(), compare);
        if (strings[0] == "0")
            return "0";
        string res = "";
        for (string s : strings)
            res += s;
        return res;
    }
};

int main() {
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << Solution().largestNumber(nums) << endl;
}