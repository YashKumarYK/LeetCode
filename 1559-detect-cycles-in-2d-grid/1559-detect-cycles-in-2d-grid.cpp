class Solution {
public:
    
    int nx[4] = {0,0,-1,1};
    int ny[4] = {-1,1,0,0};
    
    bool dfs(int i,int j, vector<vector<int>> &vis, vector<vector<char>> &grid, int x, int y, int r,int c, char element){
        if( i<0||j<0||i>=r||j>=c || grid[i][j]!=element) return false;
        
        if( vis[i][j]==1) return true;
        
        vis[i][j]=1;
        
        if( (i+1!=x ||j!=y) && dfs(i+1, j, vis, grid, i, j, r, c, element)) return true;
        if( (i-1!=x ||j!=y) && dfs(i-1, j, vis, grid, i, j, r, c, element)) return true;
        if( (i!=x ||j-1!=y) && dfs(i, j-1, vis, grid, i, j, r, c, element)) return true;
        if( (i!=x ||j+1!=y) && dfs(i, j+1, vis, grid, i, j, r, c, element)) return true;
        
        return false;

    }
    bool containsCycle(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        vector<vector<int>> vis( r, vector<int> (c,0));
        for(int i=0;i<r; i++){
            for(int j=0; j<c; j++){
                if( !vis[i][j]){
                    char element = grid[i][j];
                    if( dfs(i, j, vis, grid, -1, -1, r, c, element)==true) return true;
                }
            }
        }
        return false;
    }
};