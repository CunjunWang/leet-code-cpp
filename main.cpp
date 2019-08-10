#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
        unordered_map<int, int> map1, map2;
        vector<int> notIncluded;
        vector<int> result;
        for (int i = 0; i < arr2.size(); i++) {
            map2[arr2[i]] = 1;
        }
        for (int i = 0; i < arr1.size(); i++) {
            if (map2[arr1[i]] == 1) {
                map1[arr1[i]] = map1[arr1[i]] + 1;
            } else {
                notIncluded.push_back(arr1[i]);
            }
        }
        sort(notIncluded.begin(), notIncluded.end());
        for (int i = 0; i < arr2.size(); i++) {
            int value = map1[arr2[i]];
            while (value > 0) {
                result.push_back(arr2[i]);
                value--;
            }
        }
        for (int i = 0; i < notIncluded.size(); i++) {
            result.push_back(notIncluded[i]);
        }
        return result;
    }
};

int main() {

}