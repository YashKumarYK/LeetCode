class Solution {
public:
    
    // int solve( vector<int> &nums, int i, int j, vector<vector<int>> &dp){
    //     if( i> j){
    //         return 0;
    //     }
    //     if( dp[i][j] !=-1) return dp[i][j];
    //     int maxi = INT_MIN;
    //     for( int k=i; k<=j; k++){
    //         int cost = nums[i-1]*nums[k]*nums[j+1] + solve( nums, i, k-1, dp)+ solve(nums, k+1, j, dp);
    //         maxi = max( cost, maxi);
    //     }
    //     return dp[i][j] =maxi;
    // }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        // vector<vector<int>> dp( n+2, vector<int> (n+2, -1));
        // return solve( nums, 1, n, dp);
        
        ///dynamic programming
        vector<vector<int>> dp( n+2, vector<int> (n+2, 0));
        for(int i=n; i>=1; i--){
            for( int j=1; j<n+1; j++) {
                if (i>j) continue;
                int maxi = INT_MIN;
                for( int k =i; k<=j; k++){
                    int cost =nums[i-1]* nums[k]* nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    maxi = max( cost, maxi);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};