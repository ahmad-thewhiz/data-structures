// kosaraju's algo is used to find strongly connected components
// scc means regarless of which node you start, you can traverse all the nodes in that group

// algo
// step 1: find topological sort
// step 2: transpose the graph
// step 3: use dfs to count/print scc - pop each topo sort ele and using dfs, mark all it's neighbours as visited and count the number of main dfs calls

// time complexity: O(n+e)

#include<unordered_map>
#include<list>
#include<stack>

using namespace std;

void dfs(int node, unordered_map<int, bool>&vis, stack<int>&topo, unordered_map<int, list<int>>&adj) {
	vis[node]=true;

	for(auto it:adj[node]) {
		if(!vis[it])
			dfs(it, vis, topo, adj);
	}

	topo.push(node);
}


void dfs_transpose(int node, unordered_map<int, bool>&vis, unordered_map<int, list<int>>&transpose) {
	vis[node]=true;

	for(auto it:transpose[node]) 
		if(!vis[it])
			dfs_transpose(it, vis, transpose);
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	int m=edges.size();

	unordered_map<int, list<int>>adj;
	for(int i=0;i<m;i++) 
		adj[edges[i][0]].push_back(edges[i][1]);

	// step 1: topo sort
	stack<int>topo;
	unordered_map<int, bool>vis;

	for(int i=0;i<v;i++) 
		if(!vis[i])
			dfs(i, vis, topo, adj);

	// step 2: transpose graph
	unordered_map<int, list<int>>transpose;
	for(int i=0;i<v;i++) {
		for(auto it:adj[i]) {
			transpose[it].push_back(i);
		}
	}

	// step 3: dfs calls using topo ordering
	for(int i=0;i<v;i++)
		vis[i]=false;

	int count=0;
	
	while(!topo.empty()) {
		int top=topo.top();
		topo.pop();

		if(!vis[top]) {
			count++;
			dfs_transpose(top, vis, transpose);
		}
	}

	return count;

}
