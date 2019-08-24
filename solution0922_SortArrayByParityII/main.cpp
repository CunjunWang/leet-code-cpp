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
    vector<int> sortArrayByParityII(vector<int> &A) {
        vector<int> res(A.size());
        int evenHead = 0, oddHead = 1;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] % 2 == 0) {
                res[evenHead] = A[i];
                evenHead += 2;
            } else {
                res[oddHead] = A[i];
                oddHead += 2;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {4, 2, 5, 7};
    vector<int> result = Solution().sortArrayByParityII(nums);
    for (int i : result) {
        cout << i << " ";
    }
}