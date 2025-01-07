// Problem Link: https://leetcode.com/problems/shortest-bridge/

class Solution {
public:
    // all the four directions (S,E,N,W)
    int dirX[4]={0,1,0,-1};
    int dirY[4]={1,0,-1,0};

private:
    void markIsland(vector<vector<int>>& grid, int n, int i, int j, queue<pair<int, int>>&q) {
        // base condition when cell is not in the bounds or cell's value is 0
        if(i<0 || j<0 || i>=n || j>=n || grid[i][j]!=1) {
            return ;
        }

        grid[i][j]=2;
        q.push({i,j});

        // traverse in all four directions for the cell which had 1
        for(int d=0;d<4;d++)
            markIsland(grid, n, i+dirX[d], j+dirY[d], q);
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int, int>> bfsQueue;

        // step 1 to locate first island and mark it as 2
        bool firstIslandMarked=false;
        for(int i=0;i<n;i++) {
            if(firstIslandMarked)
                break;

            // here we are just finding the first occurence of 1 and calling bfs function to mark all its nodes as 2
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    markIsland(grid, n, i, j, bfsQueue);
                    firstIslandMarked=true;
                    break;
                }
            }
        }

        // step 2 is to perform bfs from the first island to find the shortest path to the second
        int dist=0;
        while(!bfsQueue.empty()) {
            int size=bfsQueue.size();

            // processing all the cells in the current layer of bfs
            for(int k=0;k<size;k++) {
                auto [x,y]=bfsQueue.front();
                bfsQueue.pop();

                // explore the 4 neighbors of the node of island 1
                for(int d=0;d<4;d++) {
                    int newX=x+dirX[d];
                    int newY=y+dirY[d];

                    // check bounds
                    if(newX>=0 && newY>=0 && newX<n && newY<n) {
                        
                        // reached 2nd island
                        if(grid[newX][newY]==1) {
                            return dist;
                        }

                        // still in water
                        if(grid[newX][newY]==0) {
                            grid[newX][newY]=2;
                            bfsQueue.push({newX, newY});
                        }
                    }
                }
            }
            dist++;
        }

        return -1; 
    }
};
