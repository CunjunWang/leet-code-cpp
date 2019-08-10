#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int> &A) {
        vector<bool> result(A.size());
        int number = 0;
        for (int i = 0; i < A.size(); i++) {
            number = (2 * number + A[i]) % 5;
            result[i] = number % 5 == 0;
        }
        return result;
    }
};

int main() {
    vector<int> A = {0, 1, 1};
    vector<bool> result = Solution().prefixesDivBy5(A);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}