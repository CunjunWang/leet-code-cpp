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
    bool isOneBitCharacter(vector<int> &bits) {
        int countOne = 0;
        for (int i = 0; i < bits.size() - 1; i++) {
            if (bits[i] == 1) {
                countOne++;
            } else {
                countOne = 0;
            }
        }
        int last = bits[bits.size() - 1];
        if (last == 1) {
            return false;
        } else {
            return countOne % 2 == 0;
        }
    }
};

int main() {
    vector<int> bits = {1, 1, 1, 0};
    cout << Solution().isOneBitCharacter(bits) << endl;
}