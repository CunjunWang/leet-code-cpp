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

// DP
class Solution {
public:
	int minHeightShelves(vector<vector<int>> &books, int shelf_width) {
		int size = books.size();
		if (size == 0)
			return 0;
		// dp[i]表示前i本书能到达的最小高度
		vector<int> dp(size + 1, 1001 * 1001);
		dp[0] = 0;

		for (int i = 1; i <= size; i++) {
			vector<int> book = books[i - 1];
			int width = book[0];
			int height = book[1];
			// 自己单独一层
			dp[i] = dp[i-1] + height;
			// 和之前的某些书放一层
			// 前i-1本书中, 假如前j本书达到了高度h, 第j+1本书到第i+1本书放在一层
			for (int j = i - 1; j > 0; j--) {
				vector<int> prevBook = books[j-1];
				int prevWidth = prevBook[0];
				int prevHeight = prevBook[1];
				width += prevWidth;
				height = max(height, prevHeight);
				if (width > shelf_width)
					break;
				dp[i] = min(dp[i], dp[j - 1] + height);
			}
		}
		return dp[size];
	}
};

int main() {

}