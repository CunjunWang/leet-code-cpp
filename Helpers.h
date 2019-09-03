//
// Created by 王存俊 on 2019-09-02.
//

#ifndef LEET_CODE_CPP_HELPERS_H
#define LEET_CODE_CPP_HELPERS_H

#include <vector>

using namespace std;

template<typename T>
void printMatrix(vector<vector<T>> input) {
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }
}

#endif //LEET_CODE_CPP_HELPERS_H
