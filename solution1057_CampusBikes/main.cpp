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
private:
    struct Distance {
        int dis;
        int workerIndex;
        int bikeIndex;

        bool operator<(const Distance &another) const {
            if (another.dis != dis) return dis > another.dis;
            if (workerIndex != another.workerIndex) return workerIndex > another.workerIndex;
            return bikeIndex > another.bikeIndex;
        }
    };

    int manhattanDistance(vector<int> pos0, vector<int> pos1) {
        int x0 = pos0[0], y0 = pos0[1], x1 = pos1[0], y1 = pos1[1];
        return abs(x0 - x1) + abs(y0 - y1);
    }

public:
    vector<int> assignBikes(vector<vector<int>> &workers, vector<vector<int>> &bikes) {
        int workerSize = workers.size(), bikeSize = bikes.size();
        vector<int> res(workerSize, -1);
        priority_queue<Distance> queue;
        for (int i = 0; i < workerSize; i++) {
            vector<int> workerPos = workers[i];
            for (int j = 0; j < bikeSize; j++) {
                vector<int> bikePos = bikes[j];
                int distance = manhattanDistance(workerPos, bikePos);
                queue.push({distance, i, j});
            }
        }
        vector<bool> visitedBike(bikeSize, false);
        while (!queue.empty()) {
            auto dis = queue.top();
            queue.pop();
            if (res[dis.workerIndex] == -1 && !visitedBike[dis.bikeIndex]) {
                visitedBike[dis.bikeIndex] = true;
                res[dis.workerIndex] = dis.bikeIndex;
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> workers = {{0, 0},
                                   {2, 1}};
    vector<vector<int>> bikes = {{1, 2},
                                 {3, 3}};
    vector<int> res = Solution().assignBikes(workers, bikes);
    printVector(res);
}