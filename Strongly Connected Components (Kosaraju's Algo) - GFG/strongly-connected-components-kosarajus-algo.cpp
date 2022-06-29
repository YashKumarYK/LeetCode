// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    void topo( vector<int> adj[], int node, vector<int> &vis, stack<int> &s){
        vis[ node]=1;
        for(auto i: adj[node]){
            if(!vis[i])
                topo( adj, i, vis, s);
        }
        
        s.push(node);
    }
    
    void dfs( vector<int> trans[], int node, vector<int> &vis2){
        vis2[node]=1;
        for(auto i: trans[node]){
            if(!vis2[i])
                dfs( trans, i, vis2);
        }
    }
    
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        //topological sort
        stack<int> s;
        for( int i= 0; i< V; i++){
            if( !vis[i]){
                topo( adj, i, vis, s);
            }
        }
        
        //transpose
        
        vector<int> trans[V];
        for( int i=0; i<V; i++){
            for( auto node: adj[i]){
                trans[node].push_back(i);
            }
        }
        int count =0;
        
        vector<int> vis2(V, 0);
        while(!s.empty()){
            int i = s.top();
            s.pop();
            if( !vis2[i]){
                count++;
                dfs( trans, i, vis2);
            }
        }
        return count;
        
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends