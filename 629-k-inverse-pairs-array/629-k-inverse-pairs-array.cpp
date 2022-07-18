class Solution {
public:
    int m = 1e9+7;
//     int solve( int n , int k, vector<vector<int>> &dp){
//         if( n==0) return 0;
//         if( k==0) return 1;
        
//         if( dp[n][k]!= -1) return dp[n][k];
        
//         int inv=0;
//         for(int i=0; i<=min(k, n-1); ++i){
//             inv = (inv+ solve( n-1, k-i, dp))%m;
//         }
        
//         return dp[n][k] = inv;
//     }
//     int kInversePairs(int n, int k) {
//         vector<vector<int>> dp(n+1, vector<int> (k+1,-1));
//         return  solve( n, k, dp);
//     }
    
    int kInversePairs(int n, int k) {
        int dp[1001][1001] = {}; //declaring the DP table

        dp[0][0] =1; //intializing 0,0 element 1
        
        for(int i=1 ; i<=n; ++i){ 
            long long int cs = 0;  // to maintain a window the length min(i,j)
            for(int j =0; j<=k; ++j){
                cs+=dp[i-1][j]; 
                
                if(j>=i){
                    cs-=dp[i-1][j-i];
                }
            dp[i][j] = ((long long)dp[i][j] + cs)%1000000007;             
                
                
            }
        }
        return dp[n][k]; 
    }
};