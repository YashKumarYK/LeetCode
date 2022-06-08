class Solution {
public:
    int solve( vector<vector<int>>& grid, int r, int c, int x, int y, vector<vector<int>> &dp){
        if( x==r-1 && y==c-1) return grid[x][y];
        if( x== r-1) return grid[x][y] + solve(grid,r,c,x,y+1, dp);
        if( y== c-1) return grid[x][y] + solve(grid, r, c, x+1, y, dp);
        
        if(dp[x][y] !=-1) return dp[x][y];
        //for right
        int right = grid[x][y] +solve(grid, r, c,x, y+1, dp);
        int down = grid[x][y] + solve(grid,r,c,x+1,y, dp);
        
        return dp[x][y] = min(right, down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> dp(r+1, vector<int> (c+1, -1));
        return  solve(grid, r, c, 0, 0, dp);
    }
};