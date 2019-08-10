//
// Created by 王存俊 on 2019-08-10.
//

class Solution {
public:
    int findJudge(int N, vector<vector<int>> &trust) {
        if (N == 1) {
            return trust.size() == 0 ? 1 : -1;
        }
        unordered_map<int, int> trustMap;
        for (int i = 1; i <= N; i++) {
            trustMap[i] = 0;
        }
        int mostTrusted = 0;
        int trustByMax = 0;
        vector<int> trustOther;
        for (auto thisTrust : trust) {
            int trustNumber = trustMap[thisTrust[1]];
            trustMap[thisTrust[1]] = ++trustNumber;
            trustOther.push_back(thisTrust[0]);
            if (trustMap[thisTrust[1]] >= trustByMax) {
                trustByMax = trustMap[thisTrust[1]];
                mostTrusted = thisTrust[1];
            }
        }
        if (find(trustOther.begin(), trustOther.end(), mostTrusted) != trustOther.end()) {
            // mostTrusted also trustes other people;
            return -1;
        } else {
            return trustMap[mostTrusted] == N - 1 ? mostTrusted : -1;
        }
    }
};