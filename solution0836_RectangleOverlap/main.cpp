//
// Created by 王存俊 on 2019-08-27.
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

class Solution {
public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2) {
        int left1 = rec1[0], bottom1 = rec1[1], right1 = rec1[2], top1 = rec1[3],
                left2 = rec2[0], bottom2 = rec2[1], right2 = rec2[2], top2 = rec2[3];

        return !(right1 <= left2 || left1 >= right2 || bottom2 >= top1 || bottom1 >= top2);
    }
};

int main() {

}