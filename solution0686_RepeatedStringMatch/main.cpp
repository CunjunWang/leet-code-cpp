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

// TODO:
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int time = 0;
        while (A.size() < B.size()) {
            A += A;
            time++;
        }
        if (A.find(B) != string::npos) {
            return time;
        }
        A += A;
        time++;
        if (A.find(B) != string::npos) {
            return time;
        }
        return -1;
    }
};

int main() {
    string A = "abcd", B = "cdabcdab";
    cout << Solution().repeatedStringMatch(A, B) << endl;
}