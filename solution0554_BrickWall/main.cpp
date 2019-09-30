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
public:
	int leastBricks(vector<vector<int>> &wall) {
		int rows = wall.size();
		unordered_map<int, int> record;
		int maxCount = 0;
		for (int i = 0; i < rows; i++) {
			vector<int> row = wall[i];
			int sum = 0;
			for (int j = 0; j < row.size() - 1; j++) {
				sum += row[j];
				record[sum]++;
				maxCount = max(maxCount, record[sum]);
			}
		}
		return rows - maxCount;
	}
};

int main() {
}