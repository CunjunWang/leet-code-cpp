//
// Created by 王存俊 on 2019-08-19.
//

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        // trivial solution:
        // 时间: O(n)
        // 空间: O(n)
//        vector<int> nonZero;
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i] != 0) {
//                nonZero.push_back(nums[i]);
//            }
//        }
//        for (int i = 0; i < nonZero.size(); i++) {
//            nums[i] = nonZero[i];
//        }
//        for (int i = nonZero.size(); i < nums.size(); i++) {
//            nums[i] = 0;
//        }

        // 时间: O(n)
        // 空间: O(1)
        // [0...k) 保存当前遍历过的所有非0元素
//        int k = 0;
//        for (int i = 0; i < nums.size(); i++)
//            if (nums[i] != 0)
//                nums[k++] = nums[i];
//        for (; k < nums.size(); k++)
//            nums[k] = 0;

        // 时间: O(n)
        // 空间: O(1)
        // 边遍历边交换
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != 0)
                if (i != k)
                    swap(nums[k++], nums[i]);
                else
                    k++;
    }
};

