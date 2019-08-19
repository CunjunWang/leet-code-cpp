//
// Created by 王存俊 on 2019-08-19.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include <sstream>
#include "TreeNode.h"

using namespace std;

class NumArray {

private:
    vector<int> data;

public:
    NumArray(vector<int> &nums) {
        data = nums;
    }

    void update(int i, int val) {
        int size = data.size();
        if (i < 0 || i >= size) return;
        data[i] = val;
    }

    int sumRange(int i, int j) {
        int size = data.size();
        int sum = 0;
        if (i < 0 || i >= size || j < 0 || j >= size || i > j) {
            return 0;
        }
        for (; i <= j; i++) {
            sum += data[i];
        }
        return sum;
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

// Given nums = [1, 3, 5]
//
// sumRange(0, 2) -> 9
// update(1, 2)
// sumRange(0, 2) -> 8