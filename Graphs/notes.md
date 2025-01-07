### Prim's Algorithm
Purpose: Finds the Minimum Spanning Tree (MST) of a connected graph.
Approach: Greedy; starts with a single node and adds the smallest edge that connects to an unvisited node.
When to Use: When the graph is dense (many edges), as it works efficiently with adjacency matrices.
Use Case: Network design (e.g., laying cables, road networks).

### Kruskal's Algorithm
Purpose: Finds the MST of a graph.
Approach: Greedy; sorts edges by weight and adds them to the MST if they don't form a cycle (using Disjoint Set Union).
When to Use: When the graph is sparse (few edges), as it works efficiently with edge lists.
Use Case: Designing communication networks, clustering in machine learning.

### Dijkstra's Algorithm
Purpose: Finds the shortest path from a source node to all other nodes in a graph.
Approach: Greedy; explores the shortest known distance to each unvisited node iteratively.
When to Use: When solving single-source shortest path problems for graphs with non-negative weights.
Use Case: GPS navigation systems, network routing (e.g., OSPF protocol).
