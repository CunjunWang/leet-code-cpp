//
// Created by 王存俊 on 2019-08-10.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>> &board) {
        int x, y;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    x = i;
                    y = j;
                }
            }
        }
        int count = 0;
        int startX = x - 1;
        while (startX > 0) {
            if (board[startX][y] == '.') {
                startX--;
            } else if (board[startX][y] == 'p') {
                count++;
                break;
            } else {
                break;
            }
        }
        startX = x + 1;
        while (startX < 8) {
            if (board[startX][y] == '.') {
                startX++;
            } else if (board[startX][y] == 'p') {
                count++;
                break;
            } else {
                break;
            }
        }
        int startY = y - 1;
        while (startY > 0) {
            if (board[x][startY] == '.') {
                startY--;
            } else if (board[x][startY] == 'p') {
                count++;
                break;
            } else {
                break;
            }
        }
        startY = y + 1;
        while (startY < 8) {
            if (board[x][startY] == '.') {
                startY++;
            } else if (board[x][startY] == 'p') {
                count++;
                break;
            } else {
                break;
            }
        }
        return count;
    }
};

int main() {
    vector<vector<char>> board = {
            {'.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', 'p', '.', '.', '.', '.'},
            {'.', '.', '.', 'R', '.', '.', '.', 'p'},
            {'.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', 'p', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.'}
    };
    cout << Solution().numRookCaptures(board) << endl;

}