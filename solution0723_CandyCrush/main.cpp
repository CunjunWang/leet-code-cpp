//
// Created by 王存俊 on 2019/9/24.
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
	int M, N;

public:
	vector<vector<int>> candyCrush(vector<vector<int>> &board) {
		M = board.size();
		if (M == 0) return board;
		N = board[0].size();
		if (N == 0) return board;

		while (true) {
			vector<int> toDelete;
			// traverse from top-left to bottom-right
			for (int i = 0; i < M; i++) {
				for (int j = 0; j < N; j++) {
					int num = board[i][j];
					if (!num)
						continue;
					int downCount = 0, rightCount = 0, startX = i, startY = j;
					// search downward
					while (startX < M && board[startX][j] == num) {
						downCount++;
						startX++;
					}
					if (downCount >= 3) {
						for (int k = 0; k < downCount; k++) {
							toDelete.emplace_back((i + k) * M + j);
						}
					}
					// search rightward
					while (startY < N && board[i][startY] == num) {
						rightCount++;
						startY++;
					}
					if (rightCount >= 3) {
						for (int k = 0; k < rightCount; k++) {
							toDelete.emplace_back(i * M + (j + k));
						}
					}
				}
			}
			if (toDelete.empty())
				break;

			for (int i : toDelete) {
				int x = i / M, y = i % M;
				board[x][y] = 0;
			}

			for (int j = 0; j < N; ++j) {
				int t = M - 1;
				for (int i = M - 1; i >= 0; --i) {
					if (board[i][j])
						swap(board[t--][j], board[i][j]);
				}
			}
		}
		return board;
	}
};

int main() {
	vector<vector<int>> board =
			{{1, 3, 5, 5, 2},
			 {3, 4, 3, 3, 1},
			 {3, 2, 4, 5, 2},
			 {2, 4, 4, 5, 5},
			 {1, 4, 4, 1, 1}};

//			{{110, 5,   112, 113, 114},
//								 {210, 211, 5,   213, 214},
//								 {310, 311, 3,   313, 314},
//								 {410, 411, 412, 5,   414},
//								 {5,   1,   512, 3,   3},
//								 {610, 4,   1,   613, 614},
//								 {710, 1,   2,   713, 714},
//								 {810, 1,   2,   1,   1},
//								 {1,   1,   2,   2,   2},
//								 {4,   1,   4,   4,   1014}};
	vector<vector<int>> res = Solution().candyCrush(board);
	printMatrix(res);
}