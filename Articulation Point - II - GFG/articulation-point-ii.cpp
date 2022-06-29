// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    void dfs( int node, int parent, vector<int>adj[], vector<int> &vis,vector<int> &disc,
            vector<int>& low, int &timer, vector<int> & ans){
                vis[node] = 1;
                disc[node]= low[node]=timer++;
                int child =0;
                
                for( auto nbr: adj[node]){
                    if( nbr == parent) continue;
                    
                    if( !vis[nbr]){
                        
                        dfs( nbr, node, adj, vis, disc, low, timer, ans);
                        //returning and updating the low of node
                        
                        low[node] = min( low[node], low[nbr]);
                        
                        //checking for the articulation point
                        if( low[nbr]>= disc[node] && parent !=-1){
                            ans[node]=1;
                        }
                        child++;
                    }
                    else{
                        //backedge case
                        low[node] = min( low[node], disc[nbr]);
                    }
                    
                }
                if( parent ==-1 && child>1){
                    ans[node]=1;
                }
                
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> vis(V, 0);
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        
        
        int timer =0;
        vector<int> ans(V, 0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, -1 ,adj, vis, disc, low,timer, ans);
            }
        }
        vector<int> v;
        for(int i=0; i<V; i++){
            if( ans[i]==1){
                v.push_back(i);
            }
        }
        if( v.size()==0) return {-1};
        
        return v;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends