//
// Created by 王存俊 on 2019-08-18.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == target)
                    return true;
            }
        }
        return false;
    }
};

bool searchMatrix(vector<vector<int>> &matrix, int target) {
    // treat the matrix as an array, just taking care of indices
    // [0..n*m]
    // (row, col) -> row*n + col
    // i -> [i/n][i%n]
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }
    int m = matrix.size(), n = matrix[0].size();
    int start = 0, end = m * n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        int e = matrix[mid / n][mid % n];
        if (target < e) {
            end = mid - 1;
        } else if (target > e) {
            start = mid + 1;
        } else {
            return true;
        }
    }
    return false;
}