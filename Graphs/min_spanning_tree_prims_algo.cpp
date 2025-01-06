#include <bits/stdc++.h> 

using namespace std;

/*
Algorithm for Prim's MST:
1. Represent the graph using an adjacency list.
2. Initialize three arrays:
   - `key`: Stores the minimum edge weight to include a node in the MST, initialized to `INT_MAX`.
   - `parent`: Tracks the parent of each node in the MST, initialized to `-1`.
   - `mst`: Tracks whether a node is included in the MST, initialized to `false`.
3. Set `key[1] = 0` and `parent[1] = -1` to start MST from node 1.
4. For each iteration (n-1 times for n nodes):
   - Find the node `u` with the smallest `key` value that is not included in the MST.
   - Mark `u` as included in the MST.
   - Update the `key` and `parent` values for all adjacent nodes of `u` if:
     - The node is not in the MST.
     - The edge weight is smaller than the current `key` value.
5. Construct the result by iterating over the `parent` array.
*/

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Step 1: Build adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Step 2: Initialize key, mst, and parent arrays
    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    key[1] = 0; // Start from node 1
    parent[1] = -1;

    // Step 3 to 6: Repeat for n-1 iterations
    for (int i = 1; i < n; i++) {
        // Step 3: Find the minimum key node not yet included in the MST
        int mini = INT_MAX, u;
        for (int v = 1; v <= n; v++) {
            if (!mst[v] && key[v] < mini) {
                u = v;
                mini = key[v];
            }
        }

        // Step 4: Mark the chosen node as included in MST
        mst[u] = true;

        // Step 5 & 6: Update adjacent nodes
        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second; // Corrected from `it.first` to `it.second`

            if (!mst[v] && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    // Step 7: Prepare the result
    vector<pair<pair<int, int>, int>> res;
    for (int i = 2; i <= n; i++) { // Include edges from node 2 to n
        res.push_back({{parent[i], i}, key[i]});
    }

    return res;
}
