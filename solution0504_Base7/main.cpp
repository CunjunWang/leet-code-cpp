//
// Created by 王存俊 on 2019-08-21.
//

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
    string convertToBase7(int num) {
        bool neg = num < 0;
        if (neg) num = - num;
        stack<int> stack;
        while (num >= 7) {
            stack.push(num % 7);
            num /= 7;
        }
        stack.push(num);

        string res = neg ? "-" : "";
        while(!stack.empty()) {
            res += to_string(stack.top());
            stack.pop();
        }
        return res;
    }
};

int main() {
    int n = -7;
    cout << Solution().convertToBase7(n) << endl;
}
