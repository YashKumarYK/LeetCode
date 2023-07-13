class Solution {
public:
    
    bool dfs( int node, vector<int> &vis, vector<int> &disvis, vector<int> adj[]){
        vis[node]=1;
        disvis[node]=1;
        
        for( auto it: adj[node]){
            if( !vis[it]){
                if(dfs(it, vis, disvis, adj)) return true;
            }
            else if( vis[it] == disvis[it]) return true;
        }
        
        disvis[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for( auto i: prerequisites){
            int u= i[1];
            int v = i[0];
            adj[u].push_back(v);
        }

        vector<int> vis(numCourses, 0), disvis(numCourses,0);
        
        for( int i =0; i< numCourses; i++){
            if( !vis[i]){
                if( dfs(i, vis, disvis, adj)== true){
                    return false;
                }
            }
        }
        return true;
    }
};