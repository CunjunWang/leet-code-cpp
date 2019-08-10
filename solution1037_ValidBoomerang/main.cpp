//
// Created by 王存俊 on 2019-08-10.
//

// A boomerang is a set of 3 points that are all distinct and not in a straight line.
// Given a list of three points in the plane, return whether these points are a boomerang.
//
// Example 1:
// Input: [[1,1],[2,3],[3,2]]
// Output: true
//
// Example 2:
// Input: [[1,1],[2,2],[3,3]]
// Output: false
//
// Note:
// points.length == 3
// points[i].length == 2
// 0 <= points[i][j] <= 100

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