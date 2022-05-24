// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//DFS METHOD
// 	void topological( int node, stack<int> &s, vector<int> adj[], vector<int> &vis){
// 	    vis[node] = 1;
	    
// 	    for( auto i: adj[node]){
// 	        if( !vis[i]){
// 	            topological(i, s, adj, vis);
// 	        }
// 	    }
	    
// 	    s.push(node);
// 	}
// 	//Function to return list containing vertices in Topological order. 
// 	vector<int> topoSort(int V, vector<int> adj[]) 
// 	{
// 	    vector<int> vis(V,0);
	    
// 	    stack<int> s;
	    
// 	    for(int i=0; i<V; i++){
// 	        if( !vis[i] ){
// 	            topological( i, s, adj, vis);
// 	        }
// 	    }
	    
// 	    vector<int> ans;
// 	    while(!s.empty()){
// 	        ans.push_back(s.top());
// 	        s.pop();
// 	    }
// 	    return ans;
// 	}
	
	//
	vector<int> topoSort(int V, vector<int> adj[]){
	    queue<int> q;
	    vector<int> indegree(V);
	    for(int i=0; i<V; i++){
	        for( auto it: adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    for(int i=0; i<V; i++){
	        if( indegree[i] ==0){
	            q.push(i);
	        }
	    }
	    
	    vector<int> topo;
	    while( !q.empty()){
	        int front = q.front();
	        q.pop();
	        topo.push_back( front);
	        
	        for( auto it : adj[front]){
	            indegree[it] --;
	            if( indegree[it] == 0){
	                q.push(it);
	            }
	        }
	    }
	    return topo;
	} 
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends