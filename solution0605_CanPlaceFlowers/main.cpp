//
// Created by 王存俊 on 2019-08-29.
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
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int size = flowerbed.size();
        if (size == 0)
            return n == 0;
        if (n == 0)
            return true;
        if (n > size / 2 + 1)
            return false;
        int start = flowerbed[0] == 0 ? 0 : 2;
        for (int i = start; i < size; i++) {
            if (i == 0 && n > 0) {
                if (i + 1 >= size) {
                    flowerbed[i] = 1;
                    return true;
                } else {
                    if (flowerbed[i + 1] == 0) {
                        flowerbed[i] = 1;
                        n--;
                    }
                }
            } else if (i == size - 1) {
                if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && n > 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            } else {
                if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0 && n > 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        return n == 0;
    }
};

int main() {
    vector<int> flowerbed = {0};
    int n = 1;
    cout << Solution().canPlaceFlowers(flowerbed, n) << endl;
    for (int i = 0; i < flowerbed.size(); i++) {
        cout << flowerbed[i] << " ";
    }
}