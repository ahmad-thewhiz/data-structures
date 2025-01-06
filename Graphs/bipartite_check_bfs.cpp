class Solution {
private:
    bool bfsCheck(int v, vector<vector<int>>& adj) {
        vector<int> visited(v, 0); // 0 means unvisited, 1 and -1 are two colors
        queue<int> q;

        // Iterate over all nodes (to handle disconnected graphs)
        for (int start = 0; start < v; ++start) {
            if (visited[start] == 0) { // Unvisited node
                visited[start] = 1; // Assign first color
                q.push(start);

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (auto it : adj[node]) {
                        if (visited[it] == 0) { // If not visited
                            visited[it] = -visited[node]; // Assign opposite color
                            q.push(it);
                        } else if (visited[it] == visited[node]) {
                            return false; // Same color as neighbor, not bipartite
                        }
                    }
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int vertices = graph.size();
        return bfsCheck(vertices, graph);
    }
};
