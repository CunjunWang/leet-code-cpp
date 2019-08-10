#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        string result;
        int size = S.size();

        string part;
        int leftCount = 0, rightCount = 0;
        for (int i = 0; i < size; i++) {
            char cur = S[i];
            part += cur;
            if (cur == '(') {
                leftCount++;
            } else {
                rightCount++;
            }
            if (leftCount == rightCount) {
                result += part.substr(1, part.size() - 2);
                part = "";
                leftCount = rightCount = 0;
            }
        }
        return result;
    }

};

int main() {
    string S = "(()())(())(()(()))";
    cout << Solution().removeOuterParentheses(S) << endl;
}