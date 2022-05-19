class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int &count) {
        int n = grid.size(), m = grid[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
            return;        
        grid[i][j]=0;
        count++;
        dfs(grid,i,j+1,count);
        dfs(grid,i,j-1,count);
        dfs(grid,i+1,j,count); 
        dfs(grid,i-1,j,count);    
    }
public:   
    int maxAreaOfIsland(vector<vector<int>>& grid) {        
        int n = grid.size(), m = grid[0].size(), ans = 0, count = 0; 
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 1) { dfs(grid, i, j, count); ans = max(ans, count), count = 0; }
        return ans;        
    }

};