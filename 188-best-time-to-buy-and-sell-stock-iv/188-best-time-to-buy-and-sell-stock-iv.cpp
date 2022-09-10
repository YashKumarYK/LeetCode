class Solution {
public:
    
    int solve( vector<int> &prices, int index, bool buy, int k, vector<vector<vector<int>>> &dp){
        if( k==0) return 0;
        if( index ==prices.size()) return 0;
        
        if( dp[index][buy][k] != -1) return dp[index][buy][k];
        int profit =0;
        if( buy ==1){
            profit = max( - prices[index] + solve( prices, index+1, 0, k, dp), solve( prices, index+1, 1, k, dp));
        }
        
        else{
            profit = max( prices[index] + solve( prices, index+1, 1, k-1, dp) , solve( prices, index+1, 0, k, dp));
        }
        return dp[index][buy][k] = profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp( prices.size()+1, vector<vector<int>> (2, vector<int> (k+1,-1)));
        return solve( prices, 0, 1, k, dp);
    }
};