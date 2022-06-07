class Solution {
public:
    //recursion + memoization
    // int solve( vector<int> &arr, int i, int k, int n, vector<int> &dp){
    //     if( i==n) return 0;
    //     if( dp[i] !=-1) return dp[i];
    //     int maxi = INT_MIN;
    //     int maxAns = INT_MIN;
    //     int l =0;
    //     for( int j=i ; j < min(n,k+i); j++){
    //         l++;
    //         maxi = max( maxi, arr[j]);
    //         int sum = maxi* l + solve(arr, j+1, k,n, dp);
    //         maxAns = max( sum, maxAns);
    //     }
    //     return dp[i] = maxAns;
    // }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        // vector<int> dp(n,-1);
        // return solve( arr, 0, k,n, dp);
        
        
        //top down approach- tabulation
        vector<int> dp(n+1);
        dp[n]=0;
        for( int i=n-1; i>=0; i--){
            int maxi = INT_MIN;
            int maxAns = INT_MIN;
            int l =0;
            for( int j=i ; j < min(n,k+i); j++){
                l++;
                maxi = max( maxi, arr[j]);
                int sum = maxi* l + dp[j+1];
                maxAns = max( sum, maxAns);
            }
            dp[i] = maxAns;
        }
        return dp[0];
    }
};