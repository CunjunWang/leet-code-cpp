//
// Created by 王存俊 on 2019-08-26.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <sstream>
#include <cassert>
#include <set>
#include "TreeNode.h"
#include "ListNode.h"

using namespace std;

class Solution {
private:
    bool similarWord(const string &word1, const string &word2) {
        assert(word1 != word2);
        if (word1.empty() || word1.size() != word2.size())
            return false;
        int difference = 0;
        for (int i = 0; i < word1.size(); i++) {
            if (word1[i] != word2[i]) {
                difference++;
                if (difference >= 2) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        if (wordList.size() == 0)
            return 0;
        // 找到endWord在list内的索引
        int end = find(wordList.begin(), wordList.end(), endWord) - wordList.begin();
        if (end == wordList.size()) // 超出索引, list内没有endWord
            return 0;
        // 找到beginWord在list内的索引
        int begin = find(wordList.begin(), wordList.end(), beginWord) - wordList.begin();
        if (begin == wordList.size()) // 超出索引, list内没有endWord
            wordList.push_back(beginWord); // list内加入beginWord

        int n = wordList.size();
        // 构造一张图用来bfs, 用邻接表表示
        vector<vector<bool>> g(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // 判断两个单词是否相似
                g[i][j] = g[j][i] = similarWord(wordList[i], wordList[j]);
            }
        }

        // bfs starts
        queue<int> q; // index
        vector<int> steps(n, 0); // 步长
        vector<bool> visited(n, false);
        // 从beginWord的索引开始bfs
        q.push(begin);
        steps[begin] = 1;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < n; i++) {
                if (g[cur][i] && !visited[i]) {
                    if (i == end) {
                        return steps[cur] + 1;
                    }
                    visited[i] = true;
                    steps[i] = steps[cur] + 1;
                    q.push(i);
                }
            }
        }
        return 0;
    }
};

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log"};
    cout << Solution().ladderLength(beginWord, endWord, wordList) << endl;
}