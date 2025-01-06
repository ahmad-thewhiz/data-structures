class Solution {
private:
    bool dfsCheck(int v, vector<vector<int>>& adj, vector<int>& visited, int flag) {
        visited[v] = flag;
        for (auto it : adj[v]) {
            if (visited[it] == 0) { // If not visited
                if (!dfsCheck(it, adj, visited, -flag)) // Recursive call with opposite color
                    return false; // Propagate false if any call fails
            } else if (visited[it] == visited[v]) {
                return false; // Same color as neighbor, not bipartite
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int vertices = graph.size();
        vector<int> visited(vertices, 0); // 0 means unvisited, 1 and -1 are two colors
        int flag = 1;

        // Iterate over all nodes (to handle disconnected graphs)
        for (int start = 0; start < vertices; ++start) {
            if (visited[start] == 0) {
                if (!dfsCheck(start, graph, visited, flag)) {
                    return false;
                }
            }
        }
        return true;
    }
};
