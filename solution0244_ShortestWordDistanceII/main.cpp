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

class WordDistance {
private:

    // A hash function used to hash a pair of any kind
    struct hash_pair {
        template<class T1, class T2>
        size_t operator()(const pair<T1, T2> &p) const {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
            return hash1 ^ hash2;
        }
    };

    vector<string> data;
    unordered_map<string, vector<int>> record;
    unordered_map<pair<string, string>, int, hash_pair> pairRecord;

public:
    WordDistance(vector<string> &words) {
        data = words;
        int size = data.size();
        for (int i = 0; i < size; i++) {
            record[data[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        if (pairRecord[make_pair(word1, word2)] != 0) {
            return pairRecord[make_pair(word1, word2)];
        } else if (pairRecord[make_pair(word2, word1)] != 0) {
            return pairRecord[make_pair(word2, word1)];
        }
        vector<int> word1Indices = record[word1];
        vector<int> word2Indices = record[word2];
        int size1 = word1Indices.size();
        int size2 = word2Indices.size();
        int l1 = 0, l2 = 0, minDiff = data.size() + 1;
        while (l1 < size1 && l2 < size2) {
            minDiff = min(minDiff, abs(word1Indices[l1] - word2Indices[l2]));
            if (word1Indices[l1] < word2Indices[l2]) {
                l1++;
            } else {
                l2++;
            }
        }
        pairRecord[make_pair(word1, word2)] = pairRecord[make_pair(word2, word1)] = minDiff;
        return minDiff;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */

int main() {
    vector<string> words = {"practice", "makes", "perfect", "coding", "makes"};
    string word1 = "coding", word2 = "practice";
    WordDistance *obj = new WordDistance(words);
    cout << obj->shortest(word1, word2) << endl;
}