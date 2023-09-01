class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0) return {n};
        vector<int> dp(n+1, 0);
        
        dp[0] =0, dp[1] = 1;
        //points to notice -> if(i%2==0) then dp[i] =  dt[i/2]; else dp[ i]= dp[i-1]+1;
        for(int i=2; i<=n; i++){
            if(i&1) dp[i] = dp[i-1]+1;
            else dp[i] = dp[i/2];
        }
        return dp;
    }
};