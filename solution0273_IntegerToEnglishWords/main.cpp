//
// Created by 王存俊 on 2019-09-01.
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

using namespace std;

class Solution {
private:
    vector<string> words = {"", "Thousand", "Million", "Billion"};
    vector<string> numberWords = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> allLessThan100 = {
            "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
            "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
            "Nineteen",
            "Twenty", "Twenty One", "Twenty Two", "Twenty Three", "Twenty Four", "Twenty Five", "Twenty Six",
            "Twenty Seven", "Twenty Eight", "Twenty Nine",
            "Thirty", "Thirty One", "Thirty Two", "Thirty Three", "Thirty Four", "Thirty Five", "Thirty Six",
            "Thirty Seven", "Thirty Eight", "Thirty Nine",
            "Forty", "Forty One", "Forty Two", "Forty Three", "Forty Four", "Forty Five", "Forty Six", "Forty Seven",
            "Forty Eight", "Forty Nine",
            "Fifty", "Fifty One", "Fifty Two", "Fifty Three", "Fifty Four", "Fifty Five", "Fifty Six", "Fifty Seven",
            "Fifty Eight", "Fifty Nine",
            "Sixty", "Sixty One", "Sixty Two", "Sixty Three", "Sixty Four", "Sixty Five", "Sixty Six", "Sixty Seven",
            "Sixty Eight", "Sixty Nine",
            "Seventy", "Seventy One", "Seventy Two", "Seventy Three", "Seventy Four", "Seventy Five", "Seventy Six",
            "Seventy Seven", "Seventy Eight", "Seventy Nine",
            "Eighty", "Eighty One", "Eighty Two", "Eighty Three", "Eighty Four", "Eighty Five", "Eighty Six",
            "Eighty Seven", "Eighty Eight", "Eighty Nine",
            "Ninety", "Ninety One", "Ninety Two", "Ninety Three", "Ninety Four", "Ninety Five", "Ninety Six",
            "Ninety Seven", "Ninety Eight", "Ninety Nine",
    };

    vector<string> splitIntByThreeDigits(const string &str) {
        vector<string> res;
        doSplit(str, res);
        return res;
    }

    void doSplit(string str, vector<string> &res) {
        int size = str.size();
        if (size <= 3) {
            res.emplace_back(str);
            return;
        }
        string sub = str.substr(size - 3, 3);
        string pre = str.substr(0, size - 3);
        res.emplace_back(sub);
        doSplit(pre, res);
    }

    string parseNumber(string &number, int index) {
        int size = number.size();
        int num = stoi(number);
        string numberItself;

        string backTwo = allLessThan100[num % 100];
        if (num >= 100) {
            int firstDigit = stoi(number.substr(0, 1));
            string first = numberWords[firstDigit] + " Hundred";
            if (backTwo != "Zero") {
                numberItself = first + " " + backTwo;
            } else {
                numberItself = first;
            }
        } else {
            numberItself = backTwo;
        }

        if (num == 0) {
            return "";
        }

        if (index == 0) {
            return numberItself;
        } else {
            return numberItself + " " + words[index];
        }
    }

public:
    string numberToWords(int num) {
        if (num < 10)
            return numberWords[num];

        string numString = to_string(num);
        vector<string> ints = splitIntByThreeDigits(numString);
        stack<string> parsedParts;
        for (int i = 0; i < ints.size(); i++) {
            string parsedResult = parseNumber(ints[i], i);
            parsedParts.push(parsedResult);
        }
        string res = "";
        while (!parsedParts.empty()) {
            string cur = parsedParts.top();
            parsedParts.pop();
            if (!cur.empty()) {
                res += cur;
                if (!parsedParts.empty()) {
                    res += " ";
                }
            }
        }

        int count = 0;
        for (int i = res.size() - 1; i >= 0; i--) {
            if (res[i] == ' ') {
                count++;
            } else {
                break;
            }
        }

        return res.substr(0, res.size() - count);
    }
};

int main() {
    int num = 123;
    cout << Solution().numberToWords(num) << endl;
}