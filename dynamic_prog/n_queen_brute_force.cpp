#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, vector<string> &board, int n) {
        int duprow = row;
        int dupcol = col;

        // Check upper diagonal on the left side
        while (row >= 0 && col >= 0) {
            if (board[row][col] == '1')
                return false;
            row--;
            col--;
        }

        col = dupcol;
        row = duprow;

        // Check left side
        while (col >= 0) {
            if (board[row][col] == '1')
                return false;
            col--;
        }

        col = dupcol;
        row = duprow;

        // Check lower diagonal on the left side
        while (row < n && col >= 0) {
            if (board[row][col] == '1')
                return false;
            row++;
            col--;
        }
        return true;
    }

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = '1';
                solve(col + 1, board, ans, n);
                board[row][col] = '0'; // Backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '0'));
        solve(0, board, ans, n);
        return ans;
    }
};

int main() {
    Solution solution;
    int n = 4; // Example for 4x4 board
    vector<vector<string>> result = solution.solveNQueens(n);

    for (auto board : result) {
        for (auto row : board) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
