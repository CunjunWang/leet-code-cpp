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

// TODO: TLE
// build a graph to DFS for connected component
class Solution {
public:
    int removeStones(vector<vector<int>> &stones) {
        int size = stones.size();
        if (size <= 1)
            return 0;

        vector<vector<int>> g(size, vector<int>(size, 0));
        vector<bool> visited(size, false);

        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                vector<int> ith = stones[i];
                vector<int> jth = stones[j];

                if (ith[0] == jth[0] || ith[1] == jth[1]) {
                    g[i][j] = g[j][i] = 1;
                }
            }
        }

        int connectedComponent = 0;

        for (int i = 0; i < size; i++) {
            if (!visited[i]) {
                visited[i] = true;
                connectedComponent++;

                stack<int> todo;
                todo.push(i);

                // start dfs
                while (!todo.empty()) {
                    int cur = todo.top();
                    todo.pop();
                    for (int j = i + 1; j < size; j++) {
                        if (j != cur && !visited[j] && g[cur][j] == 1) {
                            visited[j] = true;
                            todo.push(j);
                        }
                    }
                }
            }
        }

        return size - connectedComponent;
    }
};

int main() {
    vector<vector<int>> stones = {{0, 0},
                                  {0, 1},
                                  {1, 0},
                                  {1, 2},
                                  {2, 1},
                                  {2, 2}};
    cout << Solution().removeStones(stones) << endl;
}

// union find, TLE
//class Solution {
//private:
//    vector<int> unionFindMap;
//
//    int doFind(int x) {
//        if (unionFindMap[x] == -1) return x;
//        return doFind(unionFindMap[x]);
//    }
//
//    void doUnion(int x, int y) {
//        int parentX = doFind(x);
//        int parentY = doFind(y);
//        if (parentX != parentY) {
//            unionFindMap[parentX] = parentY;
//        }
//    }
//
//public:
//    int removeStones(vector<vector<int>> &stones) {
//        int size = stones.size();
//        if (size <= 1)
//            return 0;
//
//        unionFindMap = vector<int>(size, -1);
//
//        for (int i = 0; i < size; i++) {
//            for (int j = i + 1; j < size; j++) {
//                vector<int> s1 = stones[i];
//                vector<int> s2 = stones[j];
//                if (s1[0] == s2[0] || s1[1] == s2[1]) {
//                    doUnion(i, j);
//                }
//            }
//        }
//
//        int res = size;
//
//        for (int i = 0; i < unionFindMap.size(); i++) {
//            if (unionFindMap[i] == -1)
//                res--;
//        }
//
//        return res;
//    }
//};