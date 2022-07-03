class Solution {
public:
    
    int solve( int ind, vector<int> &nums, int pTon, vector<vector<int>> &dp){
        if( ind == nums.size()) return 0;
          
        
        if( dp[ind][pTon]!= -1) return dp[ind][pTon];
        /* 1: when we have to take negative difference
           0: when we have to take positive difference
        */
        
        if( pTon == false){ // we have to take positive 
            if( nums[ind]- nums[ind-1]>0){
                return dp[ind][pTon] =max(1+ solve( ind+1, nums, 1, dp),solve(ind+1, nums, 0, dp));
            }
            else 
                return dp[ind][pTon] =solve( ind+1, nums, 0, dp);
        }
        
        else{ // we have to take negative difference
            if( nums[ind]- nums[ind-1]<0){
                return dp[ind][pTon] =max(1+ solve(ind+1, nums, 0, dp),solve(ind+1, nums, 1, dp));
            }
            else 
                return dp[ind][pTon] =solve(ind+1, nums, 1, dp);
        }
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        vector<vector<int>> dp1( nums.size(), vector<int> (2, -1));
        // vector<vector<int>> dp2( nums.size(), vector<int> (nums.size(), -1));
        return 1+ max( solve( 1,nums, 0, dp1), solve( 1, nums, 1, dp1));
    }
};