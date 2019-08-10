#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> result(num_people, 0);
        int loop = 0;
        for (int i = 0; i < num_people; i++) {
            int candy = min(candies, loop * num_people + (i + 1));
            result[i] += candy;
            if (i == num_people - 1) {
                i = -1;
                loop++;
            }
            candies -= candy;
            if (candies == 0) {
                break;
            }
        }
        return result;
    }
};

int main() {
    int candies = 10, num_people = 3;
    vector<int> result = Solution().distributeCandies(candies, num_people);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}