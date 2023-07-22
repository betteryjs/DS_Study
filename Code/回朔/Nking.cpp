//
// Created by yjs on 2022/4/28.
//
// https://leetcode-cn.com/problems/n-queens/
#include <bits/stdc++.h>

using namespace std;

class Solution {

private:
    vector<vector<string >> res;

public:
    vector<vector<string>> solveNQueens(int n) {

        vector<string> chessboard(n, string(n, '.'));
        backtracking(n, 0, chessboard);
        return res;


    }

    void backtracking(int n, int row, vector<string> &chessboard) {
        if (row == n) {
            res.push_back(chessboard);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (isValid(row, col, n, chessboard)) {
                // 验证合法就可以放
                chessboard[row][col] = 'Q';
                backtracking(n, row + 1, chessboard);
                chessboard[row][col] = '.';


            }

        }


    }

    bool isValid(int row, int col, int n, const vector<string> &chessboard) {
        // 从0 0 开始放置 所以不考虑 右下 和左下是否有Q

        // 检查列
        for (int i = 0; i < row; ++i) {
            if (chessboard[i][col] == 'Q') {
                return false;
            }
        }

        //  检查右上方是否有冲突
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        // 检查左上方是否有冲突
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }

        }

        return true;


    }


};

int main() {

    int N = 4;
    Solution go;
    vector<vector<string >> res = go.solveNQueens(N);
    for (const vector<string> &c: res) {

        for (const string &b: c) {
            cout << b << "\t" << endl;
        }
        cout << endl;
    }


    return 0;


}