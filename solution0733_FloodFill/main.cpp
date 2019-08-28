//
// Created by 王存俊 on 2019-08-28.
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
    int m, n;

    int d[4][2] = {{-1, 0},
                   {0,  1},
                   {1,  0},
                   {0,  -1}};

    bool inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        m = image.size();
        if (m == 0) return image;
        n = image[0].size();
        if (n == 0) return image;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        assert(inArea(sr, sc));

        queue<pair<int, int>> todo;
        todo.push(make_pair(sr, sc));
        int curColor = image[sr][sc];
        image[sr][sc] = newColor;
        visited[sr][sc] = true;

        while (!todo.empty()) {
            pair<int, int> cur = todo.front();
            todo.pop();

            for (int i = 0; i < 4; i++) {
                int newX = cur.first + d[i][0];
                int newY = cur.second + d[i][1];
                if (inArea(newX, newY) && !visited[newX][newY] && image[newX][newY] == curColor) {
                    visited[newX][newY] = true;
                    image[newX][newY] = newColor;
                    todo.push(make_pair(newX, newY));
                }
            }
        }

        return image;
    }
};

int main() {
    vector<vector<int>> image = {{1, 1, 1},
                                 {1, 1, 0},
                                 {1, 0, 1}};
    int sr = 1, sc = 1, newColor = 2;
    vector<vector<int>> res = Solution().floodFill(image, sr, sc, newColor);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}