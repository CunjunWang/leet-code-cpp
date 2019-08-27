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
    char nextGreatestLetter(vector<char> &letters, char target) {
        for (char c : letters) {
            if (c > target) {
                return c;
            }
        }
        return letters[0];
    }
};

int main() {
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'k';
    cout << Solution().nextGreatestLetter(letters, target) << endl;
}