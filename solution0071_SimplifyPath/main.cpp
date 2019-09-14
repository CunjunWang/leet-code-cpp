//
// Created by 王存俊 on 2019-09-14.
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
#include "Helpers.h"

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> record;
        string temp;
        stringstream ss(path);
        while (getline(ss, temp, '/')) {
            if (temp == "" || temp == ".")
                continue;
            else if (temp == "..") {
                if (!record.empty())
                    record.pop_back();
            } else {
                record.emplace_back(temp);
            }
        }
        string result;
        for (int i = 0; i < record.size(); i++) {
            result = result + "/" + record[i];;
        }
        if (result == "")
            result = "/";
        return result;
    }
};

int main() {
    string path = "/home/";
    cout << Solution().simplifyPath(path) << endl;
}