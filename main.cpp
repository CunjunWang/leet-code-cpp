#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int> &A) {
        int sum = 0;
        for (int i : A) {
            sum += i;
        }
        if (sum % 3 != 0)
            return false;
        int avg = sum / 3;
        int curSum = 0;
        int times = 0;
        for (int i = 0; i < A.size(); i++) {
            curSum += A[i];
            if (curSum == avg) {
                times++;
                curSum = 0;
            }
        }
        return times == 3;
    }
};

int main() {
    vector<int> A = {0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1};
    cout << Solution().canThreePartsEqualSum(A) << endl;

    A = {0, 2, 1, -6, 6, 7, 9, -1, 2, 0, 1};
    cout << Solution().canThreePartsEqualSum(A) << endl;
}