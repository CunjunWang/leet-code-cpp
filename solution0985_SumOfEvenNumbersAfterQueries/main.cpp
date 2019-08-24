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
    vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries) {
        vector<int> res;
        int sum = 0;
        for (int i : A)
            if (i % 2 == 0)
                sum += i;

        for (int i = 0; i < queries.size(); i++) {
            vector<int> query = queries[i];
            int val = query[0];
            int index = query[1];
            if (A[index] % 2 == 1 || A[index] % 2 == -1) {
                A[index] += val;
            } else {
                sum -= A[index];
                A[index] += val;
            }
            if (A[index] % 2 == 0) {
                sum += A[index];
            }
            res.push_back(sum);
        }

        return res;
    }
};

int main() {

    cout << -3 % 2 << endl;

    vector<int> A = {-10, 2, -4, 5, -3, 3};
    vector<vector<int>> queries = {{-4, 2},
                                   {9,  0},
                                   {-8, 1},
                                   {5,  4},
                                   {1,  4},
                                   {9,  0}};
    vector<int> result = Solution().sumEvenAfterQueries(A, queries);
    for (int i : result) {
        cout << i << " ";
    }
}