//
// Created by 王存俊 on 2019-08-30.
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

class Vector2D {
private:
    stack<int> s;

public:
    Vector2D(vector<vector<int>> &v) {
        s = stack<int>();
        int size = v.size();
        for (int i = size - 1; i >= 0; i--) {
            vector<int> nums = v[i];
            int numsSize = nums.size();
            for (int j = numsSize - 1; j >= 0; j--) {
                s.push(nums[j]);
            }
        }
    }

    int next() {
        int next = s.top();
        s.pop();
        return next;
    }

    bool hasNext() {
        return !s.empty();
    }
};

// Vector2D iterator = new Vector2D([[1,2],[3],[4]]);
//
// iterator.next(); // return 1
// iterator.next(); // return 2
// iterator.next(); // return 3
// iterator.hasNext(); // return true
// iterator.hasNext(); // return true
// iterator.next(); // return 4
// iterator.hasNext(); // return false

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
}