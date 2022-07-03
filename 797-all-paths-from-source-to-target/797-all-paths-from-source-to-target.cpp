class Solution {
public:
    int n;
    void dfs( vector<vector<int>>& graph, int node, vector<int>& vis, vector<int> path,vector<vector<int>>& ans){
        if( node == n-1){
            path.push_back(node);
            ans.push_back(path);
            return;
        }
        vis[node] =1;
        path.push_back( node);
        
        for( auto i: graph[node]){
            if(vis[i] !=1){
                dfs( graph, i, vis, path, ans);
            }
        }
        vis[node]=0;
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n =graph.size();
        vector<int> path;
        vector<vector<int>> ans;
        
        vector<int> vis( n, 0);            
        dfs( graph, 0, vis, path, ans);
        
        return ans;
    }
};