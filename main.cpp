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
    int shortestDistance(vector<string> &words, string word1, string word2) {
        int size = words.size();
        int mostRecentWord1Index = -1;
        int mostRecentWord2Index = -1;
        int res = size + 1;
        for (int i = 0; i < size; i++) {
            if (words[i] == word1) {
                mostRecentWord1Index = i;
            } else if (words[i] == word2) {
                mostRecentWord2Index = i;
            }
            if (mostRecentWord1Index != -1 && mostRecentWord2Index != -1) {
                res = min(res, abs(mostRecentWord1Index - mostRecentWord2Index));
            }
        }
        return res;
    }
};

int main() {
    vector<string> words = {"practice", "makes", "perfect", "coding", "makes"};
    string word1 = "coding", word2 = "practice";
    cout << Solution().shortestDistance(words, word1, word2) << endl;
}