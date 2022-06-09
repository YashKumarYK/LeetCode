class Solution {
public:
    int solve(int target, int s,vector<vector<int>> &dp){
        if( target==0) return 0;
        if( s<=0) return INT_MAX;
        if( dp[s][target] !=-1) return dp[s][target];
        int p = s*s;
        if( p<=target){
            return dp[s][target]=min(1+solve(target-p,s,dp), solve(target,s-1,dp));
        }
        else{
            return dp[s][target]= solve(target, s-1,dp);
        }
    }
    
    int numSquares(int n) {
        if( n<4) return n;
        int s= sqrt(n);
        vector<vector<int>> dp(s+1, vector<int> (n+1,-1));
        return solve( n,s, dp);
    }
};