//
// Created by 王存俊 on 2019-08-10.
//

// Given words first and second, consider occurrences in some text of
// the form "first second third", where second comes immediately after first,
// and third comes immediately after second.
// For each such occurrence, add "third" to the answer, and return the answer.
//
// Example 1:
// Input: text = "alice is a good girl she is a good student", first = "a", second = "good"
// Output: ["girl","student"]
//
// Example 2:
// Input: text = "we will we will rock you", first = "we", second = "will"
// Output: ["we","rock"]
//
// Note:
// 1 <= text.length <= 1000
// text consists of space separated words, where each word consists of lowercase English letters.
// 1 <= first.length, second.length <= 10
// first and second consist of lowercase English letters.

class Solution {
private:
    void SplitString(const string &srcStr, vector <string> &vec, const string &separator) {
        string::size_type posSubstringStart; // 子串开始位置
        string::size_type posSeparator;        //  分隔符位置

        posSeparator = srcStr.find(separator);
        posSubstringStart = 0;
        while (string::npos != posSeparator) {
            vec.push_back(srcStr.substr(posSubstringStart, posSeparator - posSubstringStart));

            posSubstringStart = posSeparator + separator.size();
            posSeparator = srcStr.find(separator, posSubstringStart);
        }

        if (posSubstringStart != src.length())  // 截取最后一段数据
            vec.push_back(srcStr.substr(posSubstringStart));
    }

public:
    vector <string> findOcurrences(string text, string first, string second) {
        int size = text.size()
    }
};

