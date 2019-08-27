//
// Created by 王存俊 on 2019-08-27.
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
    vector<vector<int>> highFive(vector<vector<int>> &items) {
        map<int, priority_queue<int>> record;
        for (int i = 0; i < items.size(); i++) {
            vector<int> pairScore = items[i];
            int id = pairScore[0];
            int score = pairScore[1];
            record[id].push(score);
        }

        vector<vector<int>> res;

        for (auto it : record) {
            vector<int> pairAvg;
            pairAvg.push_back(it.first);
            priority_queue<int> scores = it.second;
            int size = scores.size();
            int loop = min(size, 5);
            int sum = 0;
            for (int i = 0; i < loop; i++) {
                sum += scores.top();
                scores.pop();
            }
            int avg = sum / loop;
            pairAvg.push_back(avg);

            res.push_back(pairAvg);
        }

        return res;
    }
};

int main() {
    vector<vector<int>> items = {{1, 91},
                                 {1, 92},
                                 {2, 93},
                                 {2, 97},
                                 {1, 60},
                                 {2, 77},
                                 {1, 65},
                                 {1, 87},
                                 {1, 100},
                                 {2, 100},
                                 {2, 76}};
    vector<vector<int>> res = Solution().highFive(items);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}