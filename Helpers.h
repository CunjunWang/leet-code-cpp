//
// Created by 王存俊 on 2019-09-02.
//

#ifndef LEET_CODE_CPP_HELPERS_H
#define LEET_CODE_CPP_HELPERS_H

#include <vector>
#include "ListNode.h"

using namespace std;

void printVector(vector<int> input) {
    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << " ";
    }
    cout << endl;
}

template<typename T>
void printMatrix(vector<vector<T>> input) {
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }
}

void printLinkedList(ListNode *head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

#endif //LEET_CODE_CPP_HELPERS_H
