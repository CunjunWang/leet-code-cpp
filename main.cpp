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

    int sumRange(int i, int j) {
        int sum = 0;
        for (; i <= j; i++) {
            sum += data[i];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

int main() {

}