//
// Created by 王存俊 on 2019-08-10.
//

// TODO:
class Solution {
public:
    string removeOuterParentheses(string S) {
        string result;
        int size = S.size();
        stack<char> stack;
        for (int i = 0; i < size; i++) {
            char cur = S[i];
            if (cur == '(') {
                stack.push(cur);
            } else {
                if (stack.size() > 1) {
                    result += stack.top();
                    result += cur;
                    stack.pop();
                } else {
                    stack.pop();
                }
            }
        }
        return result;
    }

};

int main() {
    string S = "(()())(())(()(()))";
    cout << Solution().removeOuterParentheses(S) << endl;
}