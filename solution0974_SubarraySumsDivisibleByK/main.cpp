//
// Created by 王存俊 on 2019-09-16.
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

// Prefix sum solution
class Solution {
public:
    int subarraysDivByK(vector<int> &A, int K) {
        int size = A.size();
        if (size == 0 || K == 0)
            return 0;
        vector<int> record(K, 0);
        record[0] = 1;

        int sum = 0;
        int count = 0;
        for (int a : A) {
            sum = (sum + a) % K;
            if (sum < 0)
                sum += K;
            count += record[sum];
            record[sum]++;
        }

        return count;
    }
};

int main() {
    vector<int> A = {7, 4, -10};
    int K = 5;
    cout << Solution().subarraysDivByK(A, K) << endl;
}