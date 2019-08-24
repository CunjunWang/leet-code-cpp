//
// Created by 王存俊 on 2019-08-11.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include <sstream>
#include "TreeNode.h"

using namespace std;

// TODO:
class Solution {
public:
    vector<int> addToArrayForm(vector<int> &A, int K) {
        if (K == 0) return A;
        vector<int> res;
        string KString = to_string(K);
        int Asize = A.size();
        int Ksize = KString.size();
        int offset = max(Asize, Ksize) - min(Asize, Ksize);
        int carry = 0;
        for (int i = A.size() - 1; i >= 0; i--) {
            int digit = A[i] + carry;
        }
    }
};

int main() {
    vector<int> A = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
    int K = 1;
    vector<int> res = Solution().addToArrayForm(A, K);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}