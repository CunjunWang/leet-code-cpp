#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == target)
                    return true;
            }
        }
        return false;
    }
};


int main() {

}