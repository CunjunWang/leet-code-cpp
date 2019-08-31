//
// Created by 王存俊 on 2019-08-31.
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

using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int> &cells, int N) {
        unordered_map<string, int> seen;

        while (N > 0) {
            string str(cells.begin(), cells.end());
            seen[str] = N--;
            vector<int> cells2(8, 0);
            for (int i = 1; i < 7; i++) {
                if ((cells[i - 1] == 0 && cells[i + 1] == 0) ||
                    (cells[i - 1] == 1 && cells[i + 1] == 1)) {
                    cells2[i] = 1;
                } else {
                    cells2[i] = 0;
                }
            }
            cells = cells2;
            str = string(cells.begin(), cells.end());
            if (seen[str]) {
                N %= (seen[str] - N);
            }
        }

        return cells;
    }
};

int main() {
    vector<int> cells = {0, 1, 0, 1, 1, 0, 0, 1};
    int N = 7;
    vector<int> res = Solution().prisonAfterNDays(cells, N);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}