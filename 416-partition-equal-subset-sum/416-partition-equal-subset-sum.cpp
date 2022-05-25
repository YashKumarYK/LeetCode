class Solution {
public:
    // recursion with memoization
//     int solve( vector<int>nums, int n,  long long sum, vector<vector<int>> &dp){
//         if( n==0) return 0;
//         if( sum == 0) return 1;
        
//         if( dp[n][sum] != -1) return dp[n][sum]; 
        
//         if( nums[n-1] <= sum){
//             return dp[n][sum] = solve( nums, n-1, sum-nums[n-1], dp) || solve(nums, n-1, sum, dp);
//         }
//         else {
//             return dp[n][sum] =solve( nums, n-1, sum,dp);
//         }
//     }
//     bool canPartition(vector<int>& nums) {
        
//         int n = nums.size();
        
//         //checking if the sum is even or odd
//         //odd - never be divided into equal sum partition
        
//         long long  sum =0;
        
//         for( auto i: nums){
//             sum += i;
//         }
//         if( sum %2 ==1) return false;
        
//         //memoizing array
//         vector<vector<int>> dp(n+1 , vector<int> (sum+1));
//         for(int i=0; i<n+1; i++){
//             for(int j=0; j<sum+1; j++){
//                 dp[i][j] = -1;
//             }
//         }
//         if(solve( nums, n, sum/2, dp) == 1){
//             return true;
//         }
//         return false;
//     }
    
    //dynamic programming
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        
        //checking if the sum is even or odd
        //odd - never be divided into equal sum partition
        
        long long  sum =0;
        
        for( auto i: nums){
            sum += i;
        }
        if( sum %2 ==1) return false;
        
        sum = sum/2;
        vector<vector<bool>> dp(n+1 , vector<bool> (sum+1));
        for(int i=0; i<n+1; i++){
            for( int j=0; j< sum+1; j++){
                if( i==0) dp[i][j] = false;
                if( j==0) dp[i][j] = true;
            }
        }
        
        for(int i=1; i<n+1; i++){
            for( int j=1; j< sum+1; j++){
                
                if( nums[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                }
                else if( nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][sum];
    }
        
};
