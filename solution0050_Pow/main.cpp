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

class Solution {

public:
    // TLE
//    double myPow(double x, int n) {
//        if (n == 0)
//            return x == 0 ? 0 : 1;
//
//        int steps = n > 0 ? 1 : -1;
//
//        int start = n;
//
//        double res = 1.0;
//        while (start != 0) {
//            res *= x;
//            start -= steps;
//        }
//
//        return n > 0 ? res : 1 / res;
//    }

    double myPow(double x, int n) {
        if (n == 0)
            return 1;

        double t = pow(x, n / 2);
        if (n % 2) {
            return n < 0 ? 1 / x * t * t : x * t * t;
        } else {
            return t * t;
        }
    }
};


int main() {
    double x = 2.000;
    int n = -2147483648;
    cout << Solution().myPow(x, n) << endl;
}