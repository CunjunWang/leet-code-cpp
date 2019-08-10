#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    bool isBoomerang(vector<vector<int>> &points) {
        for (int i = 0; i < points.size(); i++) {
            if ((points[i % 3][0] - points[(i + 1) % 3][0] == 0) &&
                (points[i % 3][1] - points[(i + 1) % 3][1] == 0))
                return false;
        }
        return (points[1][1] - points[0][1]) * (points[2][0] - points[1][0]) !=
               (points[1][0] - points[0][0]) * (points[2][1] - points[1][1]);
    }
};

int main() {

}