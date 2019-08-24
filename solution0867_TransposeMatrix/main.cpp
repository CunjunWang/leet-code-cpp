//
// Created by 王存俊 on 2019-08-24.
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
    vector<vector<int>> transpose(vector<vector<int>> &A) {
        vector<vector<int>> res;
        int m = A.size();
        if (m == 0) return res;
        int n = A[0].size();
        if (n == 0) return res;
        for (int j = 0; j < n; j++) {
            vector<int> newRow(m);
            for (int i = 0; i < m; i++) {
                newRow[i] = A[i][j];
            }
            res.push_back(newRow);
        }
        return res;
    }
};

int main() {
    vector<vector<int>> A = {{1, 2, 3},
                             {4, 5, 6},
                             {7, 8, 9}};
    vector<vector<int>> transposeResult = Solution().transpose(A);
    for (int i = 0; i < transposeResult.size(); i++) {
        for (int j = 0; i < transposeResult[i].size(); j++) {
            cout << transposeResult[i][j] << " ";
        }
        cout << endl;
    }
}