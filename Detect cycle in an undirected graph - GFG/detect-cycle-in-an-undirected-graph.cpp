// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    bool isCyclicBFS( int src, vector<int> adj[],unordered_map<int, bool> &visited){
        unordered_map< int, int> parent;
        parent[src] = -1;
        queue<int> q;
        q.push(src);
        visited[src]=1;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for( auto neighbour : adj[front]){
                if( visited[neighbour]==1 && parent[front] != neighbour){
                    return true;
                }
                else if( !visited[neighbour]){
                    q.push(neighbour);
                    parent[neighbour] = front;
                    visited[neighbour] = 1;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        unordered_map<int, bool> visited;
        
        for( int i=0; i<V; i++){
            
            if (!visited[i]){
                bool ans = isCyclicBFS( i, adj, visited);
                if( ans == true){
                    return true;
                }
            }
            
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends