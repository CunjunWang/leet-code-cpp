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
private:
    int distanceToOrigin(int x, int y) {
        return x * x + y * y;
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        // map to store square of distance, list of points
        map<int, vector<vector<int>>> record;

        for (int i = 0; i < points.size(); i++) {
            vector<int> thisPoint = points[i];
            int x = thisPoint[0], y = thisPoint[1];
            int dis = distanceToOrigin(x, y);
            record[dis].push_back(thisPoint);
        }

        vector<vector<int>> res;
        for (auto it : record) {
            if (it.second.size() <= K) {
                for (int i = 0; i < it.second.size(); i++) {
                    res.push_back(it.second[i]);
                    K--;
                }
            } else {
                for (int i = 0; i < K; i++) {
                    res.push_back(it.second[i]);
                    K--;
                }
            }
            if (K == 0)
                break;
        }

        return res;
    }
};


int main() {
    vector<vector<int>> points = {{6,  10},
                                  {-3, 3},
                                  {-2, 5},
                                  {0,  2}};
    int K = 3;
    vector<vector<int>> res = Solution().kClosest(points, K);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}