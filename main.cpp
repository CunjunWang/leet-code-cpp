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
    int peakIndexInMountainArray(vector<int> &A) {
        int peak = *max_element(A.begin(), A.end());
        int index = find(A.begin(), A.end(), peak) - A.begin();
        return index;
    }
};

int main() {

}