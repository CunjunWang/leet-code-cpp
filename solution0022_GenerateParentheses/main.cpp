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
#include <list>
#include <set>
#include "TreeNode.h"
#include "ListNode.h"

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n, n, "", res);
        return res;
    }

private:
    void generate(int left, int right, const string &cur, vector<string> &res) {

        if (left == 0 && right == 0) {
            res.push_back(cur);
            return;
        }

        if (left)
            generate(left - 1, right, cur + '(', res);

        if (right && left < right)
            generate(left, right - 1, cur + ')', res);
    }
};

int main() {
    int n = 3;
    vector<string> res = Solution().generateParenthesis(n);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}