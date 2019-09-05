//
// Created by 王存俊 on 2019-09-05.
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

// construct a graph and do bfs
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        vector<string> res;
        int size = tickets.size();
        if (size == 0) return res;

        unordered_map<string, multiset<string>> graph;
        // build graph
        for (int i = 0; i < size; i++) {
            vector<string> curTicket = tickets[i];
            string depart = curTicket[0];
            string destination = curTicket[1];
            assert(depart != destination);
            graph[depart].insert(destination);
        }

        // do dfs
        stack<string> todo;
        todo.push("JFK");
        while (!todo.empty()) {
            string cur = todo.top();
            if (graph[cur].empty()) {
                res.push_back(cur);
                todo.pop();
            } else {
                todo.push(*(graph[cur].begin()));
                graph[cur].erase(graph[cur].begin());
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    vector<vector<string>> tickets = {{"EZE", "AXA"},
                                      {"TIA", "ANU"},
                                      {"ANU", "JFK"},
                                      {"JFK", "ANU"},
                                      {"ANU", "EZE"},
                                      {"TIA", "ANU"},
                                      {"AXA", "TIA"},
                                      {"TIA", "JFK"},
                                      {"ANU", "TIA"},
                                      {"JFK", "TIA"}};
//  {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    vector<string> res = Solution().findItinerary(tickets);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}