#include<bits/stdc++.h>

using namespace std;

class DAG {
    public:
    unordered_map<int, list<pair<int,int>>>adj;
    
    void addEdge(int u, int v, int weight) {
        pair<int, int>p=make_pair(v, weight);
        adj[u].push_back(p);
    }
    
    void printAdj() {
        for(auto it:adj) {
            cout<<it.first<<"->";
            for(auto j:it.second) {
                cout<<"("<<j.first<<","<<j.second<<"), ";
            }
            cout<<endl;
        }      
    }
    
    void dfs(int node, vector<int>&visited, stack<int>&st) {
        visited[node]=1;
        for(auto it:adj[node]) {
            if(!visited[it.first]) {
                dfs(it.first, visited, st);
            }
        }
        st.push(node);
    }
    
    void getShortestPath(int src, vector<int>&dist, stack<int>&st) {
        dist[src]=0;
        
        while(!st.empty()) {
            int top=st.top();
            st.pop();
            
            if(dist[top]!=INT_MAX) {
                for(auto it:adj[top]) {
                    if(dist[top]+it.second<dist[it.first])
                        dist[it.first]=dist[top]+it.second;
                }
            }
        }
    }
};



int main() {
    
    DAG g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);
    
    g.printAdj();
    
    int n=6;
    vector<int>visited(n,0);
    stack<int>st;
    
    // topological sort
    for(int i=0;i<n;i++) {
        if(!visited[i]) {
            g.dfs(i, visited, st);
        }
    }
    
    // finding the shortest distance from the source
    int src=1;
    vector<int>distance(n, INT_MAX);
    
    g.getShortestPath(src, distance, st);
    
    cout<<"answer is: "<<endl;
    
    for(int i=0;i<distance.size();i++) 
        cout<<distance[i]<<" ";
    
    
    
    return 0;
}
