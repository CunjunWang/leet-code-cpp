//
// Created by 王存俊 on 2019-09-13.
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

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> maxdp(n, -1);
        vector<int> mindp(n, -1);
        maxdp[0] = nums[0];
        mindp[0] = nums[0];
        int maxProduct = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) {
                maxdp[i] = max(maxdp[i - 1] * nums[i], nums[i]);
                mindp[i] = min(mindp[i - 1] * nums[i], nums[i]);
            } else {
                maxdp[i] = max(mindp[i - 1] * nums[i], nums[i]);
                mindp[i] = min(maxdp[i - 1] * nums[i], nums[i]);
            }
            maxProduct = max(maxProduct, maxdp[i]);
        }
        return maxProduct;
    }
};

int main() {
    vector<int> nums = {2, 3, -2, 4, -5};
    int res = Solution().maxProduct(nums);
    cout << res << endl;
}