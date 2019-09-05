//
// Created by 王存俊 on 2019-09-05.
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
private:
    unordered_map<string, vector<string>> record; // map of <file content, list of file path>

    string extractPath(string &path) {
        int i = 0;
        while (path[i] != ' ') {
            i++;
        }
        string dir = path.substr(0, i);
        return dir + "/";
    }

    void buildMap(string &fileList, string &dir) {
        string curName = "";
        string fileName;
        string fileContent;
        vector<string> curNames;
        for (int i = 0; i < fileList.size(); i++) {
            if (fileList[i] != ' ') {
                curName += fileList[i];
            } else {
                curNames.emplace_back(curName);
                curName = "";
            }
        }
        curNames.emplace_back(curName);

        for (string &cur : curNames) {
            fileName = extractFileInfo(cur).first;
            fileContent = extractFileInfo(cur).second;
            record[fileContent].emplace_back(dir + fileName);
        }
    }

    pair<string, string> extractFileInfo(string &nameAndContent) {
        int index = nameAndContent.find_first_of('(');
        string name = nameAndContent.substr(0, index);
        int lenOfContent = nameAndContent.size() - 2 - index;
        string content = nameAndContent.substr(index + 1, lenOfContent);
        return make_pair(name, content);
    }

public:
    vector<vector<string>> findDuplicate(vector<string> &paths) {
        vector<vector<string>> res;
        int size = paths.size();
        if (size == 0)
            return res;
        for (int i = 0; i < size; i++) {
            string curPath = paths[i];
            string dir = extractPath(curPath);
            int startIndex = curPath.find_first_of(' ') + 1;
            string fileList = curPath.substr(startIndex);

            buildMap(fileList, dir);
        }

        for (auto it = record.begin(); it != record.end(); it++) {
            vector<string> cur = it->second;
            if (cur.size() > 1) {
                res.emplace_back(cur);
            }
        }

        return res;
    }
};

int main() {
    vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)",
                            "root 4.txt(efgh)"};
    printMatrix(Solution().findDuplicate(paths));
}