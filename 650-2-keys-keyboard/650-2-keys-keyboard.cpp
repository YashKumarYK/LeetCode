class Solution {
public:
    
    int solve( int ind, int prev, int n, bool copy, vector<vector<int>> &dp){
        if( ind ==n) return 0;
        if( ind > n) return 1000;
        
        if( dp[ind][prev] != -1) return dp[ind][prev];
        
        if( copy == 1){
            return dp[ind][prev] = 1+ solve( 2*ind,ind,n, 0, dp);
        }
        
        int copying = 1+ solve( ind, prev, n, 1, dp);
        int paste = INT_MAX;
        
        if( ind>1){
            paste = 1+ solve( ind+prev, prev, n, 0, dp);
        }
        return dp[ind][prev] = min(copying , paste);
    }
    
    int minSteps(int n) {
        vector<vector<int>> dp( n, vector<int> (n, -1));
        return solve(1, 0, n, 0, dp);
    }
};