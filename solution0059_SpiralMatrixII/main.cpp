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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));

        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int start = 1;
        int end = n * n;
        while (start <= end) {
            for (int cp = left; cp <= right; cp++) {
                res[top][cp] = start;
                start++;
            }
            top++;
            if (top > bottom) break;
            for (int rp = top; rp <= bottom; rp++) {
                res[rp][right] = start;
                start++;
            }
            right--;
            if (right < left) break;
            for (int cp = right; cp >= left; cp--) {
                res[bottom][cp] = start;
                start++;
            }
            bottom--;
            if (top > bottom) break;
            for (int rp = bottom; rp >= top; rp--) {
                res[rp][left] = start;
                start++;
            }
            left++;
            if (left > right) break;
        }

        return res;
    }
};

int main() {
    int n = 4;
    vector<vector<int>> res = Solution().generateMatrix(n);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}