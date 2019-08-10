//
// Created by 王存俊 on 2019-08-10.
//

// TODO:
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>> &paths) {

        vector<int> res(N);
        vector<vector<int>> G(N);
        for (vector<int> &p : paths) {
            G[p[0] - 1].push_back(p[1] - 1);
            G[p[1] - 1].push_back(p[0] - 1);
        }
        for (int i = 0; i < N; ++i) {
            int colors[5] = {};
            for (int j : G[i])
                colors[res[j]] = 1;
            for (int c = 4; c > 0; --c)
                if (!colors[c])
                    res[i] = c;
        }
        return res;

//        map<int, vector<int>> table;
//        vector<int> answer;
//        for (int i = 0; i < paths.size(); i++) {
//            int node = paths[i][0];
//            table[node].push_back(paths[i][1]);
//        }
//        vector<bool> used(4, false);
//        for (int i = 0; i < N; i++) {
//            for (int j = 0; j < 4; j++) {
//                if (!used[j]) {
//                    answer.push_back(j + 1);
//                    used[j] = true;
//                }
//            }
//        }
    }
};