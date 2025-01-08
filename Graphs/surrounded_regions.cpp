// Problem Link: https://leetcode.com/problems/surrounded-regions/description/

class Solution {
public:
    int dirX[4] = {0, 1, 0, -1};
    int dirY[4] = {1, 0, -1, 0};

    // Perform DFS to mark edge-connected 'O' regions as 'T'
    void dfs(int i, int j, vector<vector<char>>& board, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O') 
            return;

        board[i][j] = 'T'; // Mark as temporarily safe

        // Explore all 4 directions
        for (int d = 0; d < 4; d++) {
            int new_i = i + dirX[d];
            int new_j = j + dirY[d];
            dfs(new_i, new_j, board, m, n);
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) 
            return;

        int n = board[0].size();

        // Step 1: Mark edge-connected 'O's as 'T'
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') 
                dfs(i, 0, board, m, n); // Left edge
            if (board[i][n - 1] == 'O') 
                dfs(i, n - 1, board, m, n); // Right edge
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') 
                dfs(0, j, board, m, n); // Top edge
            if (board[m - 1][j] == 'O') 
                dfs(m - 1, j, board, m, n); // Bottom edge
        }

        // Step 2: Convert surrounded 'O's to 'X' and revert 'T' back to 'O'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X'; // Surrounded region
                } else if (board[i][j] == 'T') {
                    board[i][j] = 'O'; // Restore edge-connected region
                }
            }
        }
    }
};
