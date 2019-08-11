//
// Created by 王存俊 on 2019-08-11.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int> &A, int K) {
        sort(A.begin(), A.end());
        int negativeCount = 0;
        for (int i : A) {
            if (i < 0) {
                negativeCount++;
            }
        }
        int sum = 0;
        // 非正数数量比K大，全都取相反数
        if (negativeCount >= K) {
            for (int i = 0; i < K; i++) {
                A[i] = -A[i];
            }
        } else {
            for (int i = 0; i < negativeCount; i++) {
                A[i] = -A[i];
            }
            K = K - negativeCount;
            if (K % 2 == 1) {
                int min = *min_element(A.begin(), A.end());
                sum -= 2 * min;
            }
        }
        for (int i : A) {
            sum += i;
        }
        return sum;
    }
};

int main() {
    vector<int> A = {4, 2, 3};
    int K = 1;
    cout << "Sum = " << Solution().largestSumAfterKNegations(A, K) << endl;

    A = {3, -1, 0, 2};
    K = 3;
    cout << "Sum = " << Solution().largestSumAfterKNegations(A, K) << endl;

    A = {2, -3, -1, 5, -4};
    K = 2;
    cout << "Sum = " << Solution().largestSumAfterKNegations(A, K) << endl;

    A = {-8, 3, -5, -3, -5, -2};
    K = 6;
    cout << "Sum = " << Solution().largestSumAfterKNegations(A, K) << endl;
}