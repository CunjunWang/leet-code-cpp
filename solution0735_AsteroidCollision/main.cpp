//
// Created by 王存俊 on 2019-09-15.
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

class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        int size = asteroids.size();
        if (size <= 1)
            return asteroids;
        stack<int> todo;
        for (int i = size - 1; i >= 0; i--) {
            todo.push(asteroids[i]);
        }
        vector<int> res;

        while (!todo.empty()) {
            int top = todo.top();
            todo.pop();
            if (todo.empty()) {
                res.emplace_back(top);
                break;
            }
            int next = todo.top();
            if (top * next > 0) {
                res.emplace_back(top);
            } else {
                if (top < 0 && next > 0) {
                    res.emplace_back(top);
                    continue;
                }
                if (abs(top) > abs(next)) {
                    todo.pop();
                    todo.push(top);
                } else if (abs(top) == abs(next)) {
                    todo.pop();
                }
                if (!res.empty()) {
                    int prev = res.back();
                    res.pop_back();
                    todo.push(prev);
                }
            }
        }
        return res;
    }
};

int main() {
//    vector<int> ast = {5, 10, -5};
//    vector<int> res = Solution().asteroidCollision(ast);
//    for (int i = 0; i < res.size(); i++) {
//        cout << res[i] << " ";
//    }
//    cout << endl;
//
//    ast = {8, -8};
//    res = Solution().asteroidCollision(ast);
//    for (int i = 0; i < res.size(); i++) {
//        cout << res[i] << " ";
//    }
//    cout << endl;

//    vector<int> ast = {10, 2, -5};
//    vector<int> res = Solution().asteroidCollision(ast);
//    for (int i = 0; i < res.size(); i++) {
//        cout << res[i] << " ";
//    }
//    cout << endl;
//
//    ast = {-2, -1, 1, 2};
//    res = Solution().asteroidCollision(ast);
//    for (int i = 0; i < res.size(); i++) {
//        cout << res[i] << " ";
//    }
//    cout << endl;

    vector<int> ast = {1, 1, -1, -2};
    vector<int> res = Solution().asteroidCollision(ast);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}