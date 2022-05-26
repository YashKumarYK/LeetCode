class Solution {
public:
    //memoization
    int solve( vector<int> nums , int n, int index, int dp[]){
        if( index >= n) return 0;
        
        if( dp[index] != -1) return dp[index];
        
        int a= solve( nums, n, index+2, dp) + nums[index];
        int b = solve( nums, n , index+1, dp);
        
        dp[index] = max(a, b);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int index =0;
        int dp[n+1];
        memset(dp,-1, sizeof(dp));
        
        return solve( nums, n, index, dp);
        
    }
};