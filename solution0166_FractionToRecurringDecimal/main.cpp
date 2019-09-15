//
// Created by 王存俊 on 2019-09-15.
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
#include <unordered_set>
#include "DoublyLinkedListNode.h"
#include "TreeNode.h"
#include "Helpers.h"

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator) {
            return "0";
        }
        string res;
        if (numerator > 0 ^ denominator > 0) {
            res += '-';
        }
        long n = labs(numerator), d = labs(denominator), remains = n % d;
        res += to_string(n / d);
        if (!remains) {
            return res;
        }
        res += '.';
        unordered_map<long, int> rs;
        while (remains) {
            if (rs.find(remains) != rs.end()) {
                res.insert(rs[remains], "(");
                res += ')';
                break;
            }
            rs[remains] = res.size();
            remains *= 10;
            res += to_string(remains / d);
            remains %= d;
        }
        return res;
    }
};

int main() {
    cout << Solution().fractionToDecimal(13, 45) << endl;
}