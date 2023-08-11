class Solution {
public:
    // int solve(vector<int> coins, int amount, int n){
    //     if(amount ==0) return 1;
    //     if(amount<0 || n==0) return 0;
        
    //     int notPick = solve(coins, amount, n-1);
    //     int pick = 0;
    //     if(amount- coins[n-1]>=0){
    //         pick = solve(coins, amount-coins[n-1], n);
    //     }
    //     return pick+ notPick;
    // }
    int change(int amount, vector<int>& coins) {
        // return solve(coins, amount, coins.size());
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1,0));
        for(int i=0;i<n+1; i++){
            dp[i][0]=1;
        }
        for(int i=1; i<=n; i++){
            for(int j = 1; j<=amount;j++)
            {
                int notpick = dp[i-1][j];
                int pick = 0;
                if(j-coins[i-1]>=0) pick= dp[i][j-coins[i-1]];

                dp[i][j] = notpick+pick;
            }
        }
        return dp[n][amount];
    }
};