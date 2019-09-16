//
// Created by 王存俊 on 2019-09-16.
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
#include "DoublyLinkedListNode.h"
#include "TreeNode.h"
#include "Helpers.h"

using namespace std;

// build graph and b
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        vector<vector<string>> res;
        int size = accounts.size();
        if (size == 0)
            return res;

        unordered_map<string, string> emailToName;
        unordered_map<string, vector<string>> graph;

        for (int i = 0; i < size; i++) {
            vector<string> emails = accounts[i];
            string name = "";
            for (string &email : emails) {
                if (name.empty()) {
                    name = email;
                    continue;
                }
                graph[emails[1]].emplace_back(email);
                graph[email].emplace_back(emails[1]);
                emailToName[email] = name;
            }
        }

        set<string> visited;
        for (auto &it : graph) {
            string account = it.first;

            if (!visited.count(account)) {
                visited.insert(account);

                vector<string> curRes;
                queue<string> todo;

                curRes.emplace_back(account);
                todo.push(account);

                while (!todo.empty()) {
                    string cur = todo.front();
                    todo.pop();

                    vector<string> relatives = graph[cur];
                    for (string &relative : relatives) {
                        if (!visited.count(relative)) {
                            visited.insert(relative);
                            curRes.emplace_back(relative);
                            todo.push(relative);
                        }
                    }
                }
                sort(curRes.begin(), curRes.end());
                curRes.emplace(curRes.begin(), emailToName[account]);
                res.emplace_back(curRes);
            }
        }

        return res;
    }
};

int main() {
    vector<vector<string>> accounts = {{"John", "johnsmith@mail.com", "john00@mail.com"},
                                       {"John", "johnnybravo@mail.com"},
                                       {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
                                       {"Mary", "mary@mail.com"}};
    vector<vector<string>> res = Solution().accountsMerge(accounts);
    printMatrix(res);
}