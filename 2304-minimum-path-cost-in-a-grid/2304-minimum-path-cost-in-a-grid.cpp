class Solution {
public:
    
    int solve( vector<vector<int>> &grid, vector<vector<int>> &movecost, int i, int j, vector<vector<int>> &dp){
        if( i== grid.size()-1) return grid[i][j];
        
        if( dp[i][j] != -1) return dp[i][j];
        
        int sum =0;
        int mini = INT_MAX;
        for(int y= 0; y< grid[0].size(); y++){
            sum = grid[i][j] + movecost[grid[i][j]][y] + solve( grid, movecost, i+1, y, dp);
            cout<< sum;
            mini = min(sum, mini);
        }
        return dp[i][j] = mini;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& movecost) {
        int mini =INT_MAX;
        
        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size(), -1));
        
        for( int j=0; j<grid[0].size(); j++){
            mini = min(solve(grid, movecost, 0, j, dp), mini);
        }
        return mini;
    }
};