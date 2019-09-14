//
// Created by 王存俊 on 2019-09-13.
//

// TODO:

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
#include <unordered_set>
#include "TreeNode.h"
#include "ListNode.h"
#include "Helpers.h"

using namespace std;

class Solution {
public:
    int maxA(int N) {
        if (N <= 3) {
            return N;
        }
        int res = 0;
        for (int i = 1; i <= N - 2; i++) {
            int n = i * (N - 1 - i);
            if (n < res) {
                break;
            }
            n = max(N, n);
            res = max(res, n);
        }
        return res;
    }
};

int main() {
    int N = 7;
    cout << Solution().maxA(N) << endl;
}