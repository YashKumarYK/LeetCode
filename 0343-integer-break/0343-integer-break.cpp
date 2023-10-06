class Solution {
public:
    
    int solve( int i , int sum, int n, vector<vector<int>> &dp){
        if(sum == n) return 1;
        if(sum>n || i==n) return -1;

        if(dp[i][sum]!= -1) return dp[i][sum];
        
        int pick = i* solve(i, sum+i, n, dp);
        int nopick = solve(i+1, sum, n, dp);
        return dp[i][sum] = max(pick, nopick);
    }
    int integerBreak(int n) {
        vector<vector<int>> dp( n+1,vector<int> (n+1,-1));
        return solve(1,0, n, dp);
    }
};