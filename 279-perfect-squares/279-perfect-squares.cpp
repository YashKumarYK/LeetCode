class Solution {
public:
//     int solve(int target, int s,vector<vector<int>> &dp){
//         if( target==0) return 0;
//         if( s<=0) return INT_MAX;
//         if( dp[s][target] !=-1) return dp[s][target];
//         int p = s*s;
//         if( p<=target){
//             return dp[s][target]=min(1+solve(target-p,s,dp), solve(target,s-1,dp));
//         }
//         else{
//             return dp[s][target]= solve(target, s-1,dp);
//         }
//     }
    
    int numSquares(int n) {
        if( n<4) return n;
        int s= sqrt(n);
        // vector<vector<int>> dp(s+1, vector<int> (n+1,-1));
        // return solve( n,s, dp);
        
        int dp[s+1][n+1];
        for(int j=0; j<n+1; j++){
            dp[0][j]=INT_MAX;
        }
        for(int i=0; i<s+1; i++){
            dp[i][0]=0;
        }
        
        for(int i=1; i<s+1; i++){
            for(int j=1; j<n+1; j++){
                int p = i*i;
                if( p<=j){
                     dp[i][j]=min(1+dp[i][j-p], dp[i-1][j]);
                }
                else{
                    dp[i][j]= dp[i-1][j];
                }
            }
        }
        return dp[s][n];
    }
};