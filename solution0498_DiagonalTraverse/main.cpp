//
// Created by 王存俊 on 2019-09-16.
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
#include "DoublyLinkedListNode.h"
#include "TreeNode.h"
#include "Helpers.h"

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
        const int N = matrix.size();
        if (N == 0) return {};
        const int M = matrix[0].size();
        if (M == 0) return {};

        vector<int> res;
        for (int s = 0; s <= N + M - 2; ++s) {
            for (int x = 0; x <= s; ++x) {
                int i = x;
                int j = s - i;
                if (s % 2 == 0)
                    swap(i, j);
                if (i >= N || j >= M)
                    continue;
                res.push_back(matrix[i][j]);
            }
        }
        return res;
    }
};

int main() {
}