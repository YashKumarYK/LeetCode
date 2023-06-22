class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2,0));
        for(int i= n-1; i>=0; i--){
            for(int j= 0; j<=1; j++){
                int bought = dp[i+1][1];
                int nobought = dp[i+1][0];
                if(j){
                    dp[i][j] =max(-prices[i] + nobought, bought);
                }else{
                    dp[i][j] =max(prices[i]-fee + bought, nobought);
                }
            }
        }
        return dp[0][1];
    }
};