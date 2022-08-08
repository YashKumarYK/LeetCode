class Solution {
public:
    
//     int solve(vector<int> &nums, int ind, int prev, vector<vector<int>> &dp){
//         if( ind == nums.size()) return 0;
        
//         if( dp[ind][prev+1] != -1) return dp[ind][prev+1]; 
//         if( prev ==-1 || nums[ind]> nums[prev]){
//             return dp[ind][prev+1]= max( 1+ solve(nums,ind+1, ind, dp), solve( nums, ind+1, prev, dp));
//         }
        
//         else{
//             return dp[ind][prev+1]=  solve(nums, ind+1, prev, dp);
//         }
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         vector<vector<int>> dp(nums.size(), vector<int> (nums.size()+1, -1));
//         return solve( nums, 0, -1, dp);
//     }
    
//     int lengthOfLIS(vector<int>& nums) {
//         int n= nums.size();
        
//         vector<int> curr(n+1,0);
//         vector<int> next(n+1,0);
//         for( int i = n-1; i>=0; --i){
//             for(int j= i-1; j>=-1; --j){
//                 if( j ==-1 || nums[i]> nums[j]){
//                     curr[j+1]= max( 1+ next[i+1], next[j+1]);
//                 }

//                 else{
//                     curr[j+1] =  next[j+1];
//                 }
//             }
//             next = curr;
//         }
//         return next[0];
//     }
    
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp( n,1);
    //     int maxi = 1;
    //     for(int ind =0; ind <nums.size(); ind ++){
    //         for( int prev =0;prev<ind ; prev++){
    //             if( nums[ind]> nums[prev]){
    //                 dp[ind] = max( dp[ind], 1+ dp[prev]);
    //             }
    //         }
    //         maxi = max( maxi, dp[ind]);
    //     }
    //     return maxi;
    // }
    
    int lengthOfLIS(vector<int>& nums){
        int n = nums.size();
        vector<int> temp;
        temp.push_back( nums[0]);
        for( int i=1; i<n; i++){
            if( temp.back()<nums[i]){
                temp.push_back( nums[i]);
            }
            else{
                int ind = lower_bound(temp.begin(), temp.end(), nums[i])- temp.begin();
                temp[ind]= nums[i];
            }
        }
        return temp.size();
    }
};