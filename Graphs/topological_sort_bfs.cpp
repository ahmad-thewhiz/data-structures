#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topoSort(int n, vector<int> adj[]) { 
        vector<int> inDegree(n, 0);
        
        for (int i = 0; i < n; i++) {
            for (auto it : adj[i])
                inDegree[it]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0)
                q.push(i); 
        }
        
        vector<int> topo; 
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            topo.push_back(front);
            
            for (auto it : adj[front]) {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }
        return topo;
    }
};

int main() {
    vector<int> adj[6];
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[3].push_back(1);
    adj[2].push_back(3);

    Solution obj;
    vector<int> v = obj.topoSort(6, adj);

    for (auto it : v)
        cout << it << " ";

    return 0;
}
