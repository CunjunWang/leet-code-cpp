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