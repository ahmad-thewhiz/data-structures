#include <bits/stdc++.h>

// Algorithm: Find Bridges in a Graph using DFS
/*
1. Input Representation:
   - The graph is represented as an edge list where each edge connects two vertices.
   - `v` is the number of vertices, and `e` is the number of edges.

2. Build Adjacency List:
   - Convert the edge list into an adjacency list for efficient graph traversal.

3. Initialize Arrays and Variables:
   - `disc`: Tracks discovery time of each vertex during DFS.
   - `low`: Tracks the smallest discovery time reachable from each vertex.
   - `vis`: A boolean map to mark visited nodes.
   - `timer`: A counter to assign discovery times incrementally.

4. DFS Traversal:
   - Start DFS from each unvisited node:
     - Assign `disc` and `low` for the current node.
     - Traverse each neighbor:
       - If the neighbor is unvisited, recursively DFS on it and update `low` of the current node based on the child.
       - If the neighbor is already visited (back edge), update `low` of the current node.
     - Check if a bridge exists: If `low[neighbor] > disc[node]`, the edge is a bridge.

5. Output:
   - Return a list of all edges that are bridges.
*/

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, 
         vector<vector<int>> &res, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis) {
    vis[node] = true;
    disc[node] = low[node] = timer++;

    for (auto nbr : adj[node]) {
        if (nbr == parent) {
            continue; // Skip the edge leading to the parent
        }

        if (!vis[nbr]) {
            // Recursive DFS for unvisited neighbors
            dfs(nbr, node, timer, disc, low, res, adj, vis);

            // Update low[node] based on the child
            low[node] = min(low[node], low[nbr]);

            // Check for bridge
            if (low[nbr] > disc[node]) {
                res.push_back({node, nbr});
            }
        } else { 
            // Back edge found, update low[node]
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Build adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    unordered_map<int, bool> vis;
    vector<vector<int>> res;

    // Perform DFS for each unvisited node
    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfs(i, -1, timer, disc, low, res, adj, vis);
        }
    }

    return res;
}
