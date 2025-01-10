/*
step-by-step algorithm:
1. initialize variables for the number of nodes, edges, and adjacency list.
2. populate the adjacency list with the given edges.
3. initialize vectors and maps to track discovery time, low values, visited nodes, and articulation points.
4. set discovery and low values to -1 initially.
5. perform a depth-first search (dfs) for each unvisited node:
   a. mark the node as visited.
   b. update discovery and low values with the current timer value.
   c. explore all neighbors of the current node.
   d. if a neighbor is unvisited, recursively call dfs.
   e. update low value of the current node based on its neighbor.
   f. check if the current node is an articulation point based on dfs properties.
   g. handle the special case for root nodes with multiple children.
6. print all articulation points.

note: 
- low value of a node is the earliest discovery time reachable from that node, either through a back edge or its subtree.
- it helps in identifying articulation points by determining if a subtree can reach an ancestor of the current node.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>

using namespace std;

// function to perform depth-first search and find articulation points
void depth_first_search(int current_node, int parent_node, vector<int>& discovery_time, vector<int>& low_time, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adjacency_list, vector<int>& articulation_points, int& timer) {
    // mark the current node as visited
    visited[current_node] = true;
    // initialize discovery and low times
    discovery_time[current_node] = low_time[current_node] = timer++;

    // track the number of children in dfs tree
    int children_count = 0;

    // iterate through all neighbors of the current node
    for (int neighbor : adjacency_list[current_node]) {
        // skip the parent node to avoid backtracking
        if (neighbor == parent_node) {
            continue;
        }

        // if the neighbor is not visited
        if (!visited[neighbor]) {
            // recursively call dfs for the neighbor
            depth_first_search(neighbor, current_node, discovery_time, low_time, visited, adjacency_list, articulation_points, timer);
            
            // update the low value of the current node based on the neighbor
            low_time[current_node] = min(low_time[current_node], low_time[neighbor]);

            // check if the current node is an articulation point
            if (low_time[neighbor] >= discovery_time[current_node] && parent_node != -1) {
                articulation_points[current_node] = true;
            }

            // increment the children count
            children_count++;
        } else {
            // update the low value of the current node based on back edge
            low_time[current_node] = min(low_time[current_node], discovery_time[neighbor]);
        }
    }

    // special case: if the current node is the root and has more than one child
    if (parent_node == -1 && children_count > 1) {
        articulation_points[current_node] = true;
    }
}

int main() {
    // number of nodes and edges
    int nodes = 5, edges_count = 5;
    vector<pair<int, int>> edges = {
        {0, 3}, {3, 4}, {0, 4}, {0, 1}, {1, 2}
    };

    // adjacency list to represent the graph
    unordered_map<int, list<int>> adjacency_list;

    // build the adjacency list from edges
    for (const auto& edge : edges) {
        int node_u = edge.first;
        int node_v = edge.second;

        adjacency_list[node_u].push_back(node_v);
        adjacency_list[node_v].push_back(node_u);
    }

    // initialize variables for dfs
    int timer = 0;
    vector<int> discovery_time(nodes, -1);
    vector<int> low_time(nodes, -1);
    unordered_map<int, bool> visited;
    vector<int> articulation_points(nodes, 0);

    // perform dfs for each unvisited node
    for (int i = 0; i < nodes; i++) {
        if (!visited[i]) {
            depth_first_search(i, -1, discovery_time, low_time, visited, adjacency_list, articulation_points, timer);
        }
    }

    // print the articulation points
    cout << "articulation points:" << endl;
    for (int i = 0; i < nodes; i++) {
        if (articulation_points[i] != 0) {
            cout << i << " ";
        }
    }

    return 0;
}
