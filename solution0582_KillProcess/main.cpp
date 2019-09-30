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

// DFS
class Solution {
public:
	vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill) {
		assert(pid.size() == ppid.size());
		unordered_map<int, vector<int>> graph;
		for (int i = 0; i < ppid.size(); i++) {
			int cur_ppid = ppid[i];
			int cur_pid = pid[i];
			graph[cur_ppid].emplace_back(cur_pid);
		}
		vector<int> res;
		stack<int> todo;
		todo.push(kill);
		while (!todo.empty()) {
			int cur = todo.top();
			todo.pop();
			res.emplace_back(cur);
			vector<int> children = graph[cur];
			for (int i = 0; i < children.size(); i++) {
				todo.push(children[i]);
			}
		}
		return res;
	}
};

int main() {
}