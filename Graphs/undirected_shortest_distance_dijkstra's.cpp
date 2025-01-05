#include <bits/stdc++.h> 

using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> dist(vertices, INT_MAX);

    set<pair<int, int>> st;

    dist[source] = 0;
    st.insert(make_pair(0, source));

    while (!st.empty()) {
        // Fetch the record with the smallest distance
        auto top = *(st.begin());
        st.erase(st.begin());

        int nodeDist = top.first;
        int topNode = top.second;

        // Traverse neighbors
        for (auto it : adj[topNode]) {
            int neighbor = it.first;
            int weight = it.second;

            if (nodeDist + weight < dist[neighbor]) {
                // Remove the existing record for the neighbor if it exists
                auto record = st.find(make_pair(dist[neighbor], neighbor));
                if (record != st.end())
                    st.erase(record);

                // Update the distance
                dist[neighbor] = nodeDist + weight;

                // Insert the updated distance into the set
                st.insert(make_pair(dist[neighbor], neighbor));
            }
        }
    }

    return dist;
}
