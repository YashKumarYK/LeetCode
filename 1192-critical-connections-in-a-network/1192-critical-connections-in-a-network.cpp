class Solution {
public:
    
    void dfs( int node, vector<int> &disc,vector<int> &vis,vector<int> &low,vector<int> adj[],
              int parent, vector<vector<int>> &ans, int &timer){
        vis[node]= 1;
        
        disc[node]= low[node]= timer++;
        
        for( auto nbr : adj[node]){
            if(nbr==parent) continue;
            
            if( !vis[nbr]){
                dfs( nbr, disc, vis, low, adj,node, ans, timer);
                
                //while returning update the nbr
                low[node]= min( low[nbr], low[node]);
                
                //checking if a bridge exists between them or not
                
                if( low[nbr] > disc[node]){
                    ans.push_back({node, nbr});
                }
            }
            else{
                //backedge case
                
                low[node]= min( low[node],disc[nbr]);
            }
        }
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // make an adjacency list
        vector<int> adj[n];
        for(auto i: connections){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> disc(n, -1);
        vector<int> vis(n,0);
        vector<int> low(n,-1);
        
        vector<vector<int>> ans;
        int timer=0;
        
        for(int i=0; i<n; i++){
            if( !vis[i]){
                dfs(i, disc, vis, low, adj, -1, ans, timer);
            }
        }
        return ans;
    }
};