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
    int trailingZeroes(int n) {
        int result = 0;
        for (long long i = 5; n / i > 0; i *= 5) {
            result += (n / i);
        }
        return result;
    }
};

int main() {

}