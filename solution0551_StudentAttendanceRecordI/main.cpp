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
    bool checkRecord(string s) {
        if (s.size() == 0)
            return false;
        int absentCount = 0;
        int lateCount = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A') {
                absentCount++;
                if (absentCount > 1)
                    return false;
            }
            if (i > 1 && s[i] == 'L' && s[i - 1] == 'L' && s[i - 2] == 'L')
                return false;
        }
        return true;
    }
};

int main() {
    cout << Solution().checkRecord("PPALLP") << endl;
    cout << Solution().checkRecord("PPALLL") << endl;
}