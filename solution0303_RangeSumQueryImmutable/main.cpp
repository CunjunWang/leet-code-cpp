//
// Created by 王存俊 on 2019-08-19.
//

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