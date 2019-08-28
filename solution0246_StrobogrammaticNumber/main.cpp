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
#include "TreeNode.h"
#include "ListNode.h"

using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
        int size = num.size();
        if (size == 0)
            return true;
        for (int i = 0; i < size / 2; i++) {
            if (num[i] == '0') {
                if (num[size - 1 - i] != '0')
                    return false;
            } else if (num[i] == '1') {
                if (num[size - 1 - i] != '1')
                    return false;
            } else if (num[i] == '8') {
                if (num[size - 1 - i] != '8')
                    return false;
            } else if (num[i] == '6') {
                if (num[size - 1 - i] != '9')
                    return false;
            } else if (num[i] == '9') {
                if (num[size - 1 - i] != '6')
                    return false;
            } else {
                return false;
            }
        }
        if (size % 2 == 1 && ((num[size / 2] != '1') && (num[size / 2] != '8') && (num[size / 2] != '0'))) {
            return false;
        }
        return true;
    }
};

int main() {
    string num = "69";
    cout << Solution().isStrobogrammatic(num) << endl;
}