//
// Created by 王存俊 on 2019-08-10.
//

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> result(num_people, 0);
        int loop = 1;
        int i = 0
        while (candies >= 0) {
            for (; i < num_people; i++) {
                result = result + loop * (i + 1);
                if (i = num_people - 1) {
                    i = i % num_people;
                    loop++;
                }
                candies -= loop * (i + 1);
            }
        }
        result[i+1] += candies;
        return result;
    }
};