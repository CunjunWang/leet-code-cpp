//
// Created by 王存俊 on 2019-08-31.
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

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        int size = S.size();
        if (size == 0)
            return res;
        vector<int> lastOccursAt(26, 0);
        for (int i = 0; i < size; i++) {
            lastOccursAt[S[i] - 'a'] = i;
        }

        int start = 0, end = 0;
        for (int i = 0; i < size; i++) {
            char c = S[i];
            int last = lastOccursAt[c - 'a'];
            end = max(end, last);
            if (i == end) {
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return res;
    }
};

int main() {
    string S = "ababcbacadefegdehijhklij";
    vector<int> res = Solution().partitionLabels(S);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}