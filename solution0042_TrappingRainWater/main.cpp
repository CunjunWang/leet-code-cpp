//
// Created by 王存俊 on 2019-08-27.
//

#include <iostream>
#include <vector>
#include <unordered_map>
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

class Solution {
public:
    int trap(vector<int> &height) {
        int left = 0, right = height.size() - 1;
        int ans = 0, leftMax = 0, rightMax = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                leftMax = max(leftMax, height[left]);
                left++;
            } else {
                rightMax = max(rightMax, height[right]);
                right--;
            }
            if (height[left] < leftMax) {
                ans += leftMax - height[left];
            }
            if (height[right] < rightMax) {
                ans += rightMax - height[right];
            }
        }

        return ans;
    }
};

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << Solution().trap(height) << endl;
}


// my failed solution - two pointers
//class Solution {
//public:
//    int trap(vector<int> &height) {
//        int size = height.size();
//        if (size <= 1)
//            return 0;
//
//        // dummy element;
//        height.push_back(height[size - 1]);
//        size = height.size();
//
//        int res = 0;
//        int secondMaximum;
//        int maximum = -1;
//        for (int i = 0, j = 1; j < size - 1; j++) {
//            secondMaximum = height[i];
//            // j reach a local maximum
//            if (height[j] > height[j - 1] && height[j] >= height[j + 1]) {
//                maximum = height[j];
//                while (height[i] > height[j] && height[i + 1] > height[j]) {
//                    i++;
//                }
//                secondMaximum = height[i];
//                int validHeight = min(secondMaximum, maximum);
//                int width = j - i - 1;
//                int area = validHeight * width;
//                if (area != 0) {
//                    for (int k = i + 1; k < j; k++) {
//                        area -= height[k];
//                    }
//                    res += area;
//                }
//                i = j;
//            }
//        }
//        return res;
//    }
//};