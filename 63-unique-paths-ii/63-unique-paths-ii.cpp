class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid, int i, int j, int r, int c,vector<vector<int>> &dp){
        if( i==r-1 && j==c-1) return 1;
        if( i>=r || j>=c || obstacleGrid[i][j] ==1) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        return dp[i][j]= solve(obstacleGrid, i+1, j, r, c, dp)+ solve(obstacleGrid, i, j+1, r,c,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        if(obstacleGrid[r-1][c-1] ==1) return 0;
        vector<vector<int>> dp(r+1, vector<int> (c+1, -1));
        return solve( obstacleGrid, 0, 0,r,c, dp);
    }
};