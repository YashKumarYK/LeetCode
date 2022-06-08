class Solution {
public:
    int solve(vector<vector<int>>& triangle, int r, int i,int j, vector<vector<int>> &dp){
        if(i>=r || j>= triangle[i].size()) return 0;
        
        if( dp[i][j] != -1) return dp[i][j];
        //ith element
        int first = triangle[i][j] + solve( triangle, r, i+1,j, dp);
        
        //i+1th element
        int second = triangle[i][j] + solve( triangle, r, i+1, j+1, dp);
        
        return dp[i][j] = min(first, second);
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int r = triangle.size();
        vector<vector<int>> dp(r, vector<int> (triangle[r-1].size(), -1));
        return solve( triangle, r,0, 0, dp);
    }
};