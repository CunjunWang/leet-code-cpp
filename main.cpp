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

class Solution {
public:
    int totalFruit(vector<int> &tree) {
        int size = tree.size();
        if (size <= 1)
            return size;

        unordered_map<int, int> count;
        int i, j;
        for (i = 0, j = 0; j < size; ++j) {
            count[tree[j]]++;
            if (count.size() > 2) {
                if (--count[tree[i]] == 0)
                    count.erase(tree[i]);
                i++;
            }
        }
        return j - i;
    }
};

int main() {
    vector<int> tree = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << Solution().totalFruit(tree) << endl;
}