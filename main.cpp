#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    int hIndex(vector<int> &citations) {
        sort(citations.begin(), citations.end());
        int size = citations.size();
        for (int i = 0; i < size; i++) {
            int remain = size - i;
            if (citations[i] >= remain) {
                return remain;
            }
        }
        return 0;
    }
};


int main() {
    vector<int> citations = {3, 0, 6, 1, 5};
    cout << Solution().hIndex(citations) << endl;
}