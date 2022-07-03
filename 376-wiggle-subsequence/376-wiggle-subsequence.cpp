class Solution {
public:
    
    int solve( int prev, int ind, vector<int> &nums, bool pTon, vector<vector<int>> &dp){
        if( ind == nums.size()) return 0;
          
        
        if( dp[prev][ind]!= -1) return dp[prev][ind];
        /* 1: when we have to take negative difference
           0: when we have to take positive difference
        */
        
        if( pTon == false){ // we have to take positive 
            if( nums[ind]- nums[prev]>0){
                return dp[prev][ind] =max(1+ solve( ind, ind+1, nums, 1, dp),solve(prev, ind+1, nums, 0, dp));
            }
            else 
                return dp[prev][ind] =solve(prev, ind+1, nums, 0, dp);
        }
        
        else{ // we have to take negative difference
            if( nums[ind]- nums[prev]<0){
                return dp[prev][ind] =max(1+ solve( ind, ind+1, nums, 0, dp),solve(prev, ind+1, nums, 1, dp));
            }
            else 
                return dp[prev][ind] =solve(prev, ind+1, nums, 1, dp);
        }
    }
    int wiggleMaxLength(vector<int>& nums) {
        vector<vector<int>> dp1( nums.size(), vector<int> (nums.size(), -1));
        vector<vector<int>> dp2( nums.size(), vector<int> (nums.size(), -1));
        
        return 1+ max( solve( 0,1,nums, 0, dp1), solve( 0, 1, nums, 1, dp2));
    }
};