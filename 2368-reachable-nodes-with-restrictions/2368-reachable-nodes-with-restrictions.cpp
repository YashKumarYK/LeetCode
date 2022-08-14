class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        vector<int> vis(n, 0);
        for( auto i: restricted){
            vis[i]=-1;
        }
        
        vector<int> adj[n];
        for( auto i: edges){
            int u = i[0];
            int v = i[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int> q;
        q.push(0);
        vis[0]=1;
        int count =0;
        while( !q.empty()){
            int node = q.front();
            count++;
            q.pop();
            for( auto i: adj[node]){
                if( vis[i]!= 1 && vis[i]!=-1){
                    q.push(i);
                    vis[i]=1;
                }
            }
        }
        return count;
    }
};