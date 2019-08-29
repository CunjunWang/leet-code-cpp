//
// Created by 王存俊 on 2019-08-29.
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
    int shortestWordDistance(vector<string> &words, string word1, string word2) {
        unordered_map<string, vector<int>> record;
        int size = words.size();
        for (int i = 0; i < size; i++) {
            record[words[i]].push_back(i);
        }

        int res = size + 1;
        if (word1 == word2) {
            vector<int> indices = record[word1];
            int indSize = indices.size();
            assert(indSize > 1);
            for (int i = 1; i < indSize; i++) {
                res = min(res, abs(indices[i] - indices[i - 1]));
            }
        } else {
            vector<int> loc1 = record[word1];
            vector<int> loc2 = record[word2];
            int size1 = loc1.size();
            int size2 = loc2.size();
            int i = 0, j = 0;
            while (i < size1 && j < size2) {
                res = min(res, abs(loc1[i] - loc2[j]));
                if (loc1[i] < loc2[j]) {
                    i++;
                } else {
                    j++;
                }
            }
        }
        return res;
    }
};

int main() {
    vector<string> words = {"practice", "makes", "perfect", "coding", "makes"};
    string word1 = "makes", word2 = "perfect";
    cout << Solution().shortestWordDistance(words, word1, word2) << endl;
}