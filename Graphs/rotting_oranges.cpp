// Problem Link: https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int dirX[4] = {0, 1, 0, -1};
    int dirY[4] = {1, 0, -1, 0};

private:
    void markRotten(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited, queue<pair<int, int>> &q, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 1 || visited[i][j] == 1)
            return;

        // Mark the orange as rotten and visited
        grid[i][j] = 2;
        visited[i][j] = 1;

        // Push the coordinates into the queue
        q.push({i, j});
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        // step 1: push all initially rotten oranges into the queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }

        int iterations = 0;

        // step 2a: BFS to process all rotten oranges
        while (!q.empty()) {
            int size = q.size();
            bool anyRotten = false;

            for (int k = 0; k < size; k++) {
                auto [x, y] = q.front();
                q.pop();

                // step 2b: visit all 4 adjacent cells
                for (int d = 0; d < 4; d++) {
                    int newX = x + dirX[d];
                    int newY = y + dirY[d];

                    if (newX >= 0 && newY >= 0 && newX < m && newY < n && grid[newX][newY] == 1 && visited[newX][newY] == 0) {
                        markRotten(newX, newY, grid, visited, q, m, n);
                        anyRotten = true;
                    }
                }
            }

            if (anyRotten) 
                iterations++;
        }

        // step 3: check if there are still fresh oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return iterations;
    }
};
