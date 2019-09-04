//
// Created by 王存俊 on 2019-09-04.
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

// Recursive way
class Solution {
private:
    vector<vector<int>> res;

    void doRecursion(vector<vector<int>> &A, vector<vector<int>> &B) {
        if (A.empty() || B.empty())
            return;
        if (A[0][0] > B[0][0]) {
            doRecursion(B, A);
            return;
        }
        if (B[0][0] <= A[0][1]) {
            if(A[0][1] <= B[0][1]) {
                vector<int> intersection = {B[0][0], A[0][1]};
                res.emplace_back(intersection);
                A.erase(A.begin());
                doRecursion(B, A);
            } else {
                vector<int> intersection = B[0];
                res.emplace_back(intersection);
                B.erase(B.begin());
                doRecursion(A, B);
            }
        } else {
            A.erase(A.begin());
            doRecursion(B, A);
        }
    }

public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B) {
        doRecursion(A, B);
        return res;
    }
};

int main() {
    vector<vector<int>> A = {{5, 10}}, B = {{5, 6}};
//            A = {{0,  2},
//                 {5,  10},
//                 {13, 23},
//                 {24, 25}},
//            B = {{1,  5},
//                 {8,  12},
//                 {15, 24},
//                 {25, 26}};
    vector<vector<int>> res = Solution().intervalIntersection(A, B);
    printMatrix(res);
}