// problem link: https://leetcode.com/problems/number-of-islands/

class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        vis[row][col] = 1;  // Mark the starting cell as visited
        queue<pair<int, int>> q;
        q.push({row, col});

        int n = grid.size();
        int m = grid[0].size();

        vector<int> delRow = {-1, 1, 0, 0};
        vector<int> delCol = {0, 0, -1, 1};

        while (!q.empty()) {
            int curRow = q.front().first;
            int curCol = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = curRow + delRow[i];
                int ncol = curCol + delCol[i];

                // Check for valid bounds, unvisited cell, and cell containing '1'
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                    && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;  
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int count = 0;  
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                // If cell is unvisited and contains '1', start BFS
                if (!vis[row][col] && grid[row][col] == '1') {
                    count++;
                    bfs(row, col, vis, grid);
                }
            }
        }

        return count;  
    }
};
