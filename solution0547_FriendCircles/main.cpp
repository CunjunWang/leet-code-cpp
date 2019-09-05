//
// Created by 王存俊 on 2019-09-04.
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
#include "TreeNode.h"
#include "ListNode.h"
#include "Helpers.h"

using namespace std;

// TODO;
class Solution {
private:
    int m, n;


public:
    int findCircleNum(vector<vector<int>> &M) {
        m = M.size();
        if (m == 0) return 0;
        int friends[m];

        for (int i = 0; i < m; i++) {
            friends[i] = i;
        }

        for (int i = 0; i < m; i++) {
            vector<int> friendList = M[i];
            for (int j = i + 1; j < m; j++) {
                if (friendList[j] == 1) {
                    friends[]
                }
            }
        }

    }
};

int main() {
}