class Solution {
public:
    int findways(int m , int n, int i, int j, vector<vector<int>> &dp){
        if(i==m-1 && j==n-1){ // at the end -> 1 ways
             return 1; 
        }
        if(i>m || j> n) return 0; // outof bound - no ways

        if(dp[i][j]!= -1) return dp[i][j];

        int rightways  = findways(m, n, i, j+1, dp);
        int downways =  findways(m, n, i+1, j, dp);

        return dp[i][j] = rightways + downways;

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));

        return findways(m , n, 0 ,0 ,dp);
    }
};