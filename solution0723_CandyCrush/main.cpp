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
#include "Helpers.h"

using namespace std;

// TODO:
class Solution {
private:
	int M, N;
	vector<vector<int>> dir = {{1, 0},
							   {0, 1}};

	vector<int> getCandidate(int i, int j, vector<vector<int>> &board) {
		vector<int> res;
		int target = board[i][j];

		queue<int> todo;
		todo.push(i * M + j);
		while (!todo.empty()) {
			int cur = todo.front();
			res.emplace_back(cur);
			todo.pop();
			int row = cur / M;
			int col = cur % M;
			for (int d = 0; d < 2; d++) {
				int nextR = row + dir[d][0];
				int nextC = col + dir[d][1];
				if (inArea(nextR, nextC) && board[nextR][nextC] == target) {
					todo.push(nextR * M + nextC);
				}
			}
		}
		if (res.size() > 2)
			return res;
		else
			return {};
	}

	bool inArea(int x, int y) {
		return x >= 0 && x < M && y >= 0 && y < N;
	}

public:
	vector<vector<int>> candyCrush(vector<vector<int>> &board) {
		M = board.size();
		if (M == 0) return board;
		N = board[0].size();
		if (N == 0) return board;

		bool canContinue = true;

		while (canContinue) {
			canContinue = false;
			// traverse from top-left to bottom-right
			for (int i = 0; i < M; i++) {
				for (int j = 0; j < N; j++) {
					int num = board[i][j];
					if (!num || num < 0)
						continue;
					vector<int> candidates = getCandidate(i, j, board);
					int candidateSize = candidates.size();
					if (candidateSize > 2) {
						canContinue = true;
						for (int k = 0; k < candidateSize; k++) {
							int cor = candidates[k];
							int row = cor / M, col = cor % M;
							board[row][col] = -board[row][col];
						}
					}
				}
			}

			if (canContinue) {
				for (int j = 0; j < N; j++) {
					// do gravity
					vector<int> pos;
					for (int i = M - 1; i >= 0; i--) {
						if (board[i][j] > 0) {
							pos.emplace_back(board[i][j]);
						}
					}
					for (int i = 0; i < pos.size(); i++) {
						board[M - 1 - i][j] = pos[i];
					}
					for (int i = 0; i < M - pos.size(); i++) {
						board[i][j] = 0;
					}
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