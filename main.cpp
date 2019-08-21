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
    int arrangeCoins(int n) {
        int i = 1;
        int count = 0;
        while (n >= i) {
            n = n - i;
            i++;
            count++;
        }
        return count;
    }
};

int main() {
    int n = 8;
    cout << Solution().arrangeCoins(n) << endl;
}