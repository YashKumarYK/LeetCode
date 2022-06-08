class Solution {
public:
    int solve( vector<int> &nums, int n, int index, vector<int> &dp){
        if(index >= n){
            return 0;
        }    
        if( dp[index] != -1) return dp[index];
        int maxi = INT_MIN;
        for( int i=index; i<n; i++){
            int cost= INT_MIN;
            // if( i<n-2)
                cost = nums[i] + solve(nums, n, i+2, dp);
            maxi = max( cost, maxi);
        }
        return dp[index] = maxi;
    }
    
    int robber(vector<int>& nums) {
        int n = nums.size();
        int index=0;
        vector<int> dp(n+1, -1);
        return solve( nums, n, index, dp);
    }
    
    int rob(vector<int> & nums){
        int n = nums.size();
        if (n==1) return nums[0];
        vector<int> temp1,temp2;
        for( int i=0;i<n; i++){
            if( i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        
        return max( robber(temp1), robber(temp2));
    }
};