#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

class Solution {
private:
    bool isValidRow(vector<char> &row) {
        vector<char> numbers;
        for (int i = 0; i < row.size(); i++) {
            if (row[i] != '.') {
                if (find(numbers.begin(), numbers.end(), row[i]) != numbers.end()) {
                    return false;
                } else {
                    numbers.push_back(row[i]);
                };
            }
        }
        return true;
    }

    bool isValidSquare(vector<vector<char>> &board, int i, int j) {
        vector<char> numbers;
        for (int s = i - 1; s <= i + 1; s++) {
            for (int t = j - 1; t <= j + 1; t++) {
                if (board[s][t] != '.') {
                    if (find(numbers.begin(), numbers.end(), board[s][t]) != numbers.end()) {
                        return false;
                    } else {
                        numbers.push_back(board[s][t]);
                    }
                }
            }
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>> &board) {
        // check row
        for (int i = 0; i < board.size(); i++) {
            if (!isValidRow(board[i]))
                return false;
        }
        for (int j = 0; j < board[0].size(); j++) {
            vector<char> column;
            for (int i = 0; i < board.size(); i++) {
                if (board[i][j] != '.') {
                    if (find(column.begin(), column.end(), board[i][j]) != column.end()) {
                        return false;
                    } else {
                        column.push_back(board[i][j]);
                    };
                }
            }
        }
        for (int i = 1; i < board.size(); i = i + 3) {
            for (int j = 1; j < board.size(); j = j + 3) {
                if (!isValidSquare(board, i, j)) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    vector<vector<char>> board = {
            {'.', '.', '4', '.', '.', '.', '6', '3', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'5', '.', '.', '.', '.', '.', '.', '9', '.'},
            {'.', '.', '.', '5', '6', '.', '.', '.', '.'},
            {'4', '.', '3', '.', '.', '.', '.', '.', '1'},
            {'.', '.', '.', '7', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '5', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };
    cout << Solution().isValidSudoku(board) << endl;
}