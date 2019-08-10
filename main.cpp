#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
private:
    void splitString(const string &srcStr, vector<string> &vec, const string &separator) {
        string::size_type posSubstringStart; // 子串开始位置
        string::size_type posSeparator;      //  分隔符位置
        posSeparator = srcStr.find(separator);
        posSubstringStart = 0;
        while (string::npos != posSeparator) {
            vec.push_back(srcStr.substr(posSubstringStart, posSeparator - posSubstringStart));
            posSubstringStart = posSeparator + separator.size();
            posSeparator = srcStr.find(separator, posSubstringStart);
        }
        if (posSubstringStart != srcStr.length())  // 截取最后一段数据
            vec.push_back(srcStr.substr(posSubstringStart));
    }

public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> result;
        vector<string> split;
        splitString(text, split, " ");
        for (int i = 0; i < split.size() - 1; i++) {
            if (split[i] == first && split[i + 1] == second && i + 2 < split.size()) {
                result.push_back(split[i+2]);
            }
        }
        return result;
    }
};

int main() {
//    string s = "123 456 789 a b cde fghijk ";
//    vector<string> result;
//    Solution().splitString(s, result, " ");
//    for (int i = 0; i < result.size(); i++) {
//        cout << result[i] << endl;
//    }
}