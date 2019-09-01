//
// Created by 王存俊 on 2019-09-01.
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

using namespace std;

// trivial solution
// do insertion sort when adding num to data
class MedianFinder {
private:
    vector<int> data;
    int size;

    void insertionSort(vector<int> &arr, int num) {
        arr.emplace_back(num);
        size++;
        for (int i = 1; i < size; i++) {
            int e = arr[i];
            int j; // j 保存元素e应该插入的位置
            for (j = i; j > 0 && (arr[j - 1] > e); j--) {
                arr[j] = arr[j - 1];
            }
            arr[j] = e;
        }
    }

public:
    /** initialize your data structure here. */
    MedianFinder() {
        size = 0;
    }

    void addNum(int num) {
        insertionSort(data, num);
    }

    double findMedian() {
        int mid = (size - 1) / 2;
        if (size % 2 == 1)
            return data[mid];
        else
            return (double) (data[mid] + data[mid + 1]) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
}