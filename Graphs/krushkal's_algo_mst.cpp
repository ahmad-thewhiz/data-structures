#include <bits/stdc++.h>

// Kruskal's Algorithm

// Custom comparator
bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];
}

// Initialization
void makeSet(vector<int>& parent, vector<int>& rank, int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Recursively find parent and assign node to its extreme parent (path compression)
int findParent(vector<int>& parent, int node) {
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent, parent[node]);
}

// Union of two sets by rank
void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[v] < rank[u]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

/* 
Algorithm: Kruskal's Minimum Spanning Tree (MST)

1. Input Representation:
   - The graph is represented as a list of edges, where each edge is a vector of size 3: `[u, v, wt]`
     - `u` and `v` are the vertices connected by the edge.
     - `wt` is the weight of the edge.
   - `n` is the total number of vertices in the graph.

2. Sort Edges:
   - Sort the edges in non-decreasing order of their weights.

3. Initialize Data Structures:
   - Use `parent` and `rank` arrays for Disjoint Set Union (DSU) operations:
     - `parent[i]`: Tracks the parent of node `i`.
     - `rank[i]`: Tracks the depth of the tree for efficient union operations.

4. Iterate Through Edges:
   - For each edge in the sorted list:
     - Find the parent of the two vertices of the edge.
     - If the parents are different (i.e., they belong to different sets):
       - Add the weight of the edge to the MST weight.
       - Union the two sets.

5. Return the MST Weight:
   - The total weight of the MST is the sum of the weights of the edges included in the MST.

6. Output:
   - Return the minimum weight of the spanning tree.
*/

int minimumSpanningTree(vector<vector<int>>& edges, int n) {
    // Step 2: Sort edges by weight
    sort(edges.begin(), edges.end(), cmp);

    // Step 3: Initialize parent and rank arrays
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    int minWeight = 0;

    // Step 4: Process edges
    for (int i = 0; i < edges.size(); i++) {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];

        // If the edge does not form a cycle, include it in the MST
        if (u != v) {
            minWeight += wt;
            unionSet(u, v, parent, rank);
        }
    }

    // Step 5: Return the total weight of the MST
    return minWeight;
}
