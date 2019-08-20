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
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        for (long long i = 0; i <= num / 2; i++) {
            if (i * i == num)
                return true;
        }
        return false;
    }
};

int main() {
    for (int i = 0; i <= 100; i++) {
        cout << "number i: " << i << " is a perfect square: " << Solution().isPerfectSquare(i) << endl;
    }
}