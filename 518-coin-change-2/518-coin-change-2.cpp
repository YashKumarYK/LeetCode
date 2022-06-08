class Solution {
public:
//     int solve( int n, int amount, vector<int> coins, vector<vector<int>> &dp){
//         if( n==0) return 0;
//         if( amount ==0) return 1;
        
//         if( dp[n][amount]!= -1) return dp[n][amount]; 
//         if( coins[n-1]<= amount){
//             return dp[n][amount]=solve( n, amount- coins[n-1],coins, dp) + solve(n-1, amount, coins, dp);
//         }
//         else{
//             return dp[n][amount]= solve(n-1, amount, coins, dp);
//         }
//     }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
//         vector<vector<int>> dp(n+1, vector<int> (amount+1, -1));
//         return solve( n, amount, coins, dp);
        
        //top down approach
        int dp[n+1][amount+1];
        for( int j=0; j<amount+1; ++j){
            dp[0][j]=0;
        }
        
        for(int i=0; i<n+1; ++i){
            dp[i][0]=1;
        }
        
        for(int i=1; i<n+1; ++i){
            for(int j =1; j<amount+1; ++j){
                if( coins[i-1]<=j){
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j]; 
                }
                else 
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][amount];
    }
};