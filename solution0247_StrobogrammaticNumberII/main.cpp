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
private:
    void generateResult(int n, int left, int right, string cur, vector<string> &result) {
        if (left > right) {
            if (cur.size() == 1) {
                result.push_back(cur);
            } else if (cur.size() > 1 && cur[0] != '0') {
                result.push_back(cur);
            }
            return;
        }
        cur[left] = cur[right] = '0';
        generateResult(n, left + 1, right - 1, cur, result);
        cur[left] = cur[right] = '1';
        generateResult(n, left + 1, right - 1, cur, result);
        cur[left] = cur[right] = '8';
        generateResult(n, left + 1, right - 1, cur, result);
        if (left != right) {
            cur[left] = '6', cur[right] = '9';
            generateResult(n, left + 1, right - 1, cur, result);
            cur[left] = '9', cur[right] = '6';
            generateResult(n, left + 1, right - 1, cur, result);
        }
    }

public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> result;
        if (n <= 0) return result;
        generateResult(n, 0, n - 1, string(n, '0'), result);
        return result;
    }
};

int main() {
    int n = 2;
    vector<string> res = Solution().findStrobogrammatic(n);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}