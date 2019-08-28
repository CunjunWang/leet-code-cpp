//
// Created by 王存俊 on 2019-08-28.
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
// TODO:
class Solution {
public:
    int shortestDistance(vector<string> &words, string word1, string word2) {
        int word1Index = find(words.begin(), words.end(), word1) - words.begin();
        int word2Index = find(words.begin(), words.end(), word2) - words.begin();
        return 0;
    }
};

int main() {
}