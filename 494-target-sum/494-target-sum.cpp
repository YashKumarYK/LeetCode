class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for( auto i: nums){
            sum +=i;
        }
         
        if( sum < target || (sum - target)%2) return 0;
        int s = (sum - target)/2;
        
        //subset sum problem
        int dp[n+1][s+1];
        for( int i=0; i<n+1; i++){
            for(int j=0; j<s+1; j++){
                if( i==0) dp[i][j] =0;
                if( j==0) dp[i][j] =1;
            }
        }
        
        for(int i=1; i<n+1; i++){
            for( int j=0; j<s+1; j++){
                if( nums[i-1]>j){
                    dp[i][j] = dp[i-1][j];
                }
                else if( nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][s];
    }
};