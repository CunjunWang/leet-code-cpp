//
// Created by 王存俊 on 2019-08-27.
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
public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        map<string, int> record;
        for (string &s : words) {
            record[s]++;
        }
        map<int, vector<string>> freq;
        for (auto &it : record) {
            freq[-1 * it.second].push_back(it.first);
        }
        vector<string> res;
        for (auto it : freq) {
            int size = it.second.size();
            int iter = min(size, k);
            for (int i = 0; i < iter; i++) {
                res.push_back(it.second[i]);
                k--;
            }
            if (k == 0) {
                break;
            }
        }

        return res;
    }
};


int main() {
    vector<string> words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    int K = 4;
    vector<string> res = Solution().topKFrequent(words, K);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}