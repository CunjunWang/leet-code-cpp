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

class Codec {
private:
	string sizeToString(int size) {
		string sizeStr = to_string(size);
		int sizeStrSize = sizeStr.size();
		while (sizeStrSize < 4) {
			sizeStr = '0' + sizeStr;
			sizeStrSize = sizeStr.size();
		}
		return sizeStr;
	}

public:
	// Encodes a list of strings to a single string.
	string encode(vector<string> &strs) {
		string res = "";
		for (string &s: strs) {
			int size = s.size();
			string sizeStr = sizeToString(size);
			res += (sizeStr + s);
		}
		return res;
	}

	// Decodes a single string to a list of strings.
	vector<string> decode(string s) {
		vector<string> res;
		for (int i = 0; i < s.size();) {
			string sizeStr = s.substr(i, 4);
			i = i + 4;
			int size = stoi(sizeStr);
			string data = s.substr(i, size);
			i = i + size;
			res.emplace_back(data);
		}
		return res;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

int main() {
	TreeNode *root = new TreeNode(1);
	TreeNode *node1 = new TreeNode(5);
	TreeNode *node2 = new TreeNode(3);
	root->left = node1;
	root->right = node2;
	cout << Solution().sumNumbers(root) << endl;
}