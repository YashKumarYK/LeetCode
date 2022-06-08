class Solution {
public:
    int solve( vector<int> &nums, int n, int index, vector<int> &dp){
        
        if( index>=n-1){
            return 0;
        }
        if( nums[index]==0) return n;
        
        if(dp[index]!=-1) return dp[index];
        
        int mini = n+1;
        for(int i=index+1; i<= min(n-1, index+nums[index]);i++){
            mini= min(mini, 1+ solve(nums, n, i,dp));
        }
        
        return dp[index] =mini;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        if( n ==1) return 0;
        vector<int> dp(n, -1);
        return solve( nums, n,0, dp);
    }
};