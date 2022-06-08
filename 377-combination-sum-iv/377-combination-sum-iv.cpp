class Solution {
public:
//     //memoization
//     int solve(vector<int>& nums, int target, vector<int> &dp){
//         if( target==0){
//             return 1;
//         }
//         if (dp[target]!= -1) return dp[target];
        
//         dp[target] =0;
        
//         return dp[target];
//     }
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1);
        // return solve( nums, target, dp);
        dp[0] =1;
        for( int i=0; i<target+1; i++){
            for( int j =0; j<nums.size(); j++){
                if( i>=nums[j]){
                    dp[i] += dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};