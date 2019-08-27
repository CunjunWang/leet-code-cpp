//
// Created by 王存俊 on 2019-08-26.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <sstream>
#include <cassert>
#include <list>
#include <set>
#include "TreeNode.h"
#include "ListNode.h"

using namespace std;

// TODO:
class Solution {
public:
    int binaryGap(int N) {
        string binary = bitset<32>(N).to_string();
        int maxCount = 0;
        int j = 0;
        int start;
        for (int i = 0; i < binary.size(); i++) {
            if (binary[i] == '1') {
                start = i;
            } else {
                maxCount = max(cur, maxCount);
                cur = 0;
            }
        }
        return maxCount;
    }
};

int main() {
    int n = 22;
    cout << Solution().binaryGap(n) << endl;
}