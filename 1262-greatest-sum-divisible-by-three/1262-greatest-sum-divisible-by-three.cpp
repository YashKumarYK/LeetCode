class Solution {
public:
    
    int solve( vector<int> &nums, int i, int n, int rem, vector<vector<int>> &dp){
        if( i>=n ){
            if( rem==0)
                return 0;
            return INT_MIN;
        }
        if( dp[i][rem] != -1) return dp[i][rem];
        return dp[i][rem] = max( nums[i]+ solve( nums,i+1, n, (nums[i]+rem)%3, dp ),
                        solve(nums, i+1, n, rem, dp));
    }
    int maxSumDivThree(vector<int>& nums) {
        int n =nums.size();
        vector<vector<int>> dp(n+1, vector<int> (3, -1));
        return solve( nums,0, nums.size(), 0, dp);
    }
};