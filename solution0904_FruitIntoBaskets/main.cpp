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

// Sliding Window Solution:
// [i,j] is the sliding window, and it's the current longest window.
// Suppose we found current longest window [i, j], then this length will be kept,
// because, as j++, if the sliding window contains more than 2, then also we will do i++,
// so that is to say, the current longest length will be kept the same,
// in another word, when [i,j] reached a maximum, it will not become smaller
// on the other side, when j++, if the current window contains less than two,
// then i will not increase (because the if statement), in this way, the longest
// length of sliding window will get updated
class Solution {
public:
    int totalFruit(vector<int> &tree) {
        int size = tree.size();
        if (size <= 1)
            return size;

        unordered_map<int, int> count;
        int i, j;
        for (i = 0, j = 0; j < size; ++j) {
            count[tree[j]]++;
            if (count.size() > 2) {
                if (--count[tree[i]] == 0)
                    count.erase(tree[i]);
                i++;
            }
        }
        return j - i;
    }
};

// TLE
//class Solution {
//public:
//    int totalFruit(vector<int> &tree) {
//        int size = tree.size();
//        if (size <= 1)
//            return size;
//
//        int res = 0;
//        for (int i = 0; i < size; i++) {
//            if (i > 0 && tree[i] == tree[i - 1])
//                continue;
//            vector<int> seen;
//            seen.emplace_back(tree[i]);
//            int j;
//            for (j = i + 1; j < size; j++) {
//                if (tree[j] == tree[i]) {
//                    continue;
//                } else {
//                    if (find(seen.begin(), seen.end(), tree[j]) == seen.end()) {
//                        seen.emplace_back(tree[j]);
//                    }
//                    if (seen.size() > 2) {
//                        res = max(res, j - i);
//                        break;
//                    }
//                }
//            }
//            if (j == size) {
//                res = max(res, j - i);
//            }
//        }
//
//        return res;
//    }
//};

int main() {
    vector<int> tree = {1, 2, 3, 2, 2};
    cout << Solution().totalFruit(tree) << endl;
}