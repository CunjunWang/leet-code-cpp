//
// Created by 王存俊 on 2019-09-14.
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
#include "Helpers.h"

using namespace std;

class Solution {
private:
    void generateResult(string &s, int curStart,
                        vector<string> &currentResult, vector<string> &res) {
        if (currentResult.size() >= 4) {
            if (isValidIP(currentResult)) {
                string ip = buildResult(currentResult);
                res.emplace_back(ip);
            }

            return;
        }

        int size = s.size();
        for (int i = 1; i <= 3; i++) {
            if (curStart + i >= size) {
                continue;
            }

            string left = s.substr(curStart + i);
//            if (left.size() <= 3) {
//                currentResult.pop_back();
//            }
            string part = s.substr(curStart, i);
            if (stoi(part) > 255) {
                continue;
            }
            currentResult.emplace_back(part);
            int resSize = currentResult.size();
            if (resSize == 3) {

                if (left.size() > 3) {
                    // prune;
                    currentResult.pop_back();
                    continue;
                } else {
                    if (left.empty()) {
                        continue;
                    }
                    currentResult.emplace_back(left);
                }
            }

            generateResult(s, curStart + i, currentResult, res);

            if (currentResult.size() > resSize) {
                currentResult.pop_back();
            }

            // back track search
            currentResult.pop_back();

        }
    }

    bool isValidIP(vector<string> &ip) {
        if (ip.size() != 4)
            return false;
        for (int i = 0; i < ip.size(); i++) {
            if (ip[i].size() > 3) {
                return false;
            }
            if (ip[i].empty()) {
                return false;
            }
            if (ip[i][0] == '0' && stoi(ip[i]) != 0) {
                return false;
            }
            if (stoi(ip[i]) == 0 && ip[i].size() > 1) {
                return false;
            }
            int ipInt = stoi(ip[i]);
            if (ipInt < 0 || ipInt > 255) {
                return false;
            }
        }
        return true;
    }

    string buildResult(vector<string> &ip) {
        string res;
        for (int i = 0; i < ip.size(); i++) {
            res += ip[i];
            if (i != ip.size() - 1) {
                res += '.';
            }
        }
        return res;
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> currentResult;
        generateResult(s, 0, currentResult, res);
//        set<string> dedup(res.begin(), res.end());
//        res.clear();
//        for (auto it = dedup.begin(); it != dedup.end(); it++) {
//            res.emplace_back(*it);
//        }
        return res;
    }
};

int main() {
    string input = "010010";
    vector<string> res = Solution().restoreIpAddresses(input);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}