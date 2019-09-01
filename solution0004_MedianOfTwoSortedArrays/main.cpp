//
// Created by 王存俊 on 2019-09-01.
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

// trivial solution, O(max(m, n)), m = nums1.size(), n = nums2.size()
class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        vector<int> merged;
        int size1 = nums1.size(), size2 = nums2.size();
        int i = 0, j = 0;
        while (i < size1 && j < size2) {
            if (nums1[i] <= nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }

        if (j == size2 && i < size1) {
            while (i < size1) {
                merged.push_back(nums1[i]);
                i++;
            }
        } else if (i == size1 && j < size2) {
            while (j < size2) {
                merged.push_back(nums2[j]);
                j++;
            }
        }

//        for (i = 0; i < merged.size(); i++) {
//            cout << merged[i] << " ";
//        }
//        cout << endl;

        int finalSize = merged.size();
        int mid = finalSize / 2;
        if (finalSize % 2 == 1) {
            return merged[mid];
        } else {
            return (double) (merged[mid - 1] + merged[mid]) / 2;
        }
    }
};

int main() {
    vector<int> nums1 = {3};
    vector<int> nums2 = {-2, -1};
    cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
}