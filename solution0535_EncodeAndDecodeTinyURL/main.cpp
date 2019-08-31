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
private:
    string prefix = "http://tinyurl.com/";
    unordered_map<int, string> urlRecord;
    int i = 1;

public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        urlRecord[i] = longUrl;
        return prefix + to_string(i++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int key = stoi(shortUrl.substr(prefix.size()));
        return urlRecord[key];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main() {
    string s = "https://leetcode.com/problems/design-tinyurl";
    string tinyUrl = Solution().encode(s);
    cout << tinyUrl << endl;
    string longUrl = Solution().decode(tinyUrl);
    cout << longUrl << endl;
}