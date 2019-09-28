//
// Created by 王存俊 on 2019/9/27.
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

class Solution {
public:
	vector<int> majorityElement(vector<int> &nums) {
		int size = nums.size();
		vector<int> res;
		if (size == 0)
			return res;
		unordered_map<int, int> record;
		for (int i = 0; i < size; i++) {
			int num = nums[i];
			if (record[num] >= 0) {
				record[num]++;
			}
			if (record[num] > size / 3) {
				res.emplace_back(num);
				record[num] = -1;
			}
		}
		return res;
	}
};

int main() {
}