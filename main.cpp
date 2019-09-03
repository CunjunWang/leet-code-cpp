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

class TrieNode {
public:
    int index; // 当前单词在words中的index. 如果不是单词则为-1
    unordered_map<char, TrieNode *> next;
    vector<int> list; // 记录符合如下条件的index: 1. words[index]以当前node为后缀 2. words[index]剩余部分为palindrome

    TrieNode() {
        index = -1;
    }
};

class Solution {
private:
    // 所有单词倒序添加进trie
    // 如果是单词, 记录该单词在word list中的index, 否则是-1
    void addWord(TrieNode *node, string word, int index) {
        for (int i = word.size() - 1; i >= 0; i--) {
            char c = word[i];
            if (!node->next.count(c)) {
                node->next[c] = new TrieNode();
            }
            if (isPalindrome(word, 0, i)) {
                node->list.emplace_back(index);
            }
            node = node->next[c];
        }
        node->list.emplace_back(index);
        node->index = index;
    }

    // 在trie中搜索
    void searchWord(TrieNode *node, int index, vector<string> &words,
                    vector<vector<int>> &res) {
        string thisWord = words[index];
        for (int i = 0; i < thisWord.size(); i++) {
            char c = thisWord[i];
            if (node->index >= 0 && node->index != index &&
                isPalindrome(thisWord, i, thisWord.size() - 1)) {
                vector<int> candidate = {index, node->index};
                res.emplace_back(candidate);
            }
            node = node->next[c];
            if (!node) {
                return;
            }
        }

        for (int i : node->list) {
            if (index != i) {
                vector<int> candidate = {index, i};
                res.emplace_back(candidate);
            }
        }
    }

    // 判断str从start到end是不是palindrome
    bool isPalindrome(string &str, int start, int end) {
        while (start <= end) {
            if (str[start] != str[end])
                return false;
            else
                start++, end--;
        }
        return true;
    }

public:
    vector<vector<int>> palindromePairs(vector<string> &words) {
        vector<vector<int>> res;
        int size = words.size();
        if (size <= 1)
            return res;

        TrieNode *root = new TrieNode();
        // 把每个单词以倒序加进trie
        for (int i = 0; i < size; i++) {
            addWord(root, words[i], i);
        }
        // 对每个单词去trie中搜索
        for (int i = 0; i < size; i++) {
            searchWord(root, i, words, res);
        }

        return res;
    }
};

int main() {
    vector<string> words = {"a", "abc", "aba", ""};
    // {"a", ""};
    // {"abcd", "dcba", "lls", "s", "sssll"};
    vector<vector<int>> res = Solution().palindromePairs(words);
    printMatrix(res);
}