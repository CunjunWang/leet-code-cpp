//
// Created by 王存俊 on 2019/9/29.
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

class Solution {
private:
	int R, C;

	int putBomb(vector<vector<char>> &grid, int x, int y) {
		int count = 0;
		// up
		int x0 = x;
		while (--x0 >= 0) {
			if (grid[x0][y] == 'W')
				break;
			else if (grid[x0][y] == 'E')
				count++;
		}
		// down;
		x0 = x;
		while (++x0 < R) {
			if (grid[x0][y] == 'W')
				break;
			else if (grid[x0][y] == 'E')
				count++;
		}
		// left;
		int y0 = y;
		while (--y0 >= 0) {
			if (grid[x][y0] == 'W')
				break;
			else if (grid[x][y0] == 'E')
				count++;
		}
		// right;
		y0 = y;
		while (++y0 < C) {
			if (grid[x][y0] == 'W')
				break;
			else if (grid[x][y0] == 'E')
				count++;
		}
		return count;
	}

public:
	int maxKilledEnemies(vector<vector<char>> &grid) {
		R = grid.size();
		if (R == 0)
			return 0;
		C = grid[0].size();
		if (C == 0)
			return 0;

		int res = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (grid[i][j] == '0') {
					res = max(res, putBomb(grid, i, j));
				}
			}
		}
		return res;
	}
};

int main() {
	vector<vector<char>> grid = {{'0', 'E', '0', '0'},
								 {'E', '0', 'W', 'E'},
								 {'0', 'E', '0', '0'}};
	cout << Solution().maxKilledEnemies(grid) << endl;
}